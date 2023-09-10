#include "light.h"
#include "renderParam.h"
#include "renderer.h"

#include "pxr/imaging/hd/sceneDelegate.h"
#include "pxr/imaging/hd/tokens.h"


PXR_NAMESPACE_OPEN_SCOPE

HdEmbreeLight::HdEmbreeLight(SdfPath const &id, TfToken const &lightType)
    : HdLight(id), _lightType(lightType) {
  if (!id.IsEmpty()) {
    TF_WARN("Creating light %s: %s", id.GetText(), lightType.GetText());
  }
}

HdEmbreeLight::~HdEmbreeLight() {}

void HdEmbreeLight::Sync(HdSceneDelegate *sceneDelegate,
                         HdRenderParam *renderParam, HdDirtyBits *dirtyBits) {
    
    if (GetId().GetString().find("/_UsdImaging_HdEmbreeRendererPlugin") != std::string::npos) {
        // XXX: Where TF is this coming from?
        return;
    }

//   TF_WARN("Syncing light %s", GetId().GetText());

  SdfPath const &id = GetId();
  Light light;

  // Get light's transform. We'll only consider the first time sample for now
  HdTimeSampleArray<GfMatrix4d, 1> xformSamples;
  sceneDelegate->SampleTransform(id, &xformSamples);
  // rows are the axes
  light.xform = GfMatrix4f(xformSamples.values[0]);

  // Compute luminance
  float intensity = sceneDelegate->GetLightParamValue(id, HdLightTokens->intensity).Get<float>();
  float exposure = sceneDelegate->GetLightParamValue(id, HdLightTokens->exposure).Get<float>();
  GfVec3f color = sceneDelegate->GetLightParamValue(id, HdLightTokens->color).Get<GfVec3f>();

  light.luminance = color * intensity * powf(2.0f, exposure);
  light.normalize = sceneDelegate->GetLightParamValue(id, HdLightTokens->normalize).Get<bool>();

  // Get visibility
  bool visible = sceneDelegate->GetVisible(id);
//   TF_WARN("Visible: %d, luminance: %f %f %f", visible, light.luminance[0], light.luminance[1], light.luminance[2]);

  // Switch on the light type and pull the relevant attributes from the scene delegate, applying any normalization factors
  if (_lightType == HdSprimTypeTokens->cylinderLight) {
    light.kind = LightKind::Cylinder;
    light.cylinder = {
        sceneDelegate->GetLightParamValue(id, HdLightTokens->radius)
            .Get<float>(),
        sceneDelegate->GetLightParamValue(id, HdLightTokens->length)
            .Get<float>(),
    };
  } else if (_lightType == HdSprimTypeTokens->diskLight) {
    light.kind = LightKind::Disk;
    light.disk = {
        sceneDelegate->GetLightParamValue(id, HdLightTokens->radius)
            .Get<float>(),
    };
  } else if (_lightType == HdSprimTypeTokens->distantLight) {
    light.kind = LightKind::Distant;

    light.distant = {
        float(GfDegreesToRadians(sceneDelegate->GetLightParamValue(id, HdLightTokens->angle)
            .Get<float>() / 2.0f)),
    };

  } else if (_lightType == HdSprimTypeTokens->domeLight) {
    light.kind = LightKind::Dome;
    light.dome = {};
  } else if (_lightType == HdSprimTypeTokens->rectLight) {
    light.kind = LightKind::Rect;
    light.rect = {
        sceneDelegate->GetLightParamValue(id, HdLightTokens->width)
            .Get<float>(),
        sceneDelegate->GetLightParamValue(id, HdLightTokens->height)
            .Get<float>(),
    };
  } else if (_lightType == HdSprimTypeTokens->sphereLight) {
    light.kind = LightKind::Sphere;
    light.sphere = {
        sceneDelegate->GetLightParamValue(id, HdLightTokens->radius)
            .Get<float>(),
    };
  } else if (_lightType == HdSprimTypeTokens->diskLight) {
    light.kind = LightKind::Disk;
    light.disk = {
        sceneDelegate->GetLightParamValue(id, HdLightTokens->radius).Get<float>()
    };
  }

  light.shaping.focus = sceneDelegate->GetLightParamValue(id, HdLightTokens->shapingFocus).Get<float>();
  light.shaping.focusTint = sceneDelegate->GetLightParamValue(id, HdLightTokens->shapingFocusTint).Get<GfVec3f>();
  light.shaping.coneAngle = sceneDelegate->GetLightParamValue(id, HdLightTokens->shapingConeAngle).Get<float>();
  light.shaping.coneSoftness = sceneDelegate->GetLightParamValue(id, HdLightTokens->shapingConeSoftness).Get<float>();

  HdEmbreeRenderer *renderer =
      static_cast<HdEmbreeRenderParam *>(renderParam)->GetRenderer();
  _lightId = renderer->SetLight(id, light);
}

HdDirtyBits HdEmbreeLight::GetInitialDirtyBitsMask() const {
  return HdLight::AllDirty;
}

void HdEmbreeLight::Finalize(HdRenderParam *renderParam) {}

PXR_NAMESPACE_CLOSE_SCOPE
