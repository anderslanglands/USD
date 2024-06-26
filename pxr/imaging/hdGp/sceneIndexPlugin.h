//
// Copyright 2022 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#ifndef PXR_IMAGING_HD_GP_SCENE_INDEX_PLUGIN_H
#define PXR_IMAGING_HD_GP_SCENE_INDEX_PLUGIN_H

#include "pxr/base/tf/envSetting.h"
#include "pxr/imaging/hd/sceneIndexPlugin.h"
#include "pxr/imaging/hd/sceneIndexPluginRegistry.h"

PXR_NAMESPACE_OPEN_SCOPE

extern TfEnvSetting<bool> HDGP_INCLUDE_DEFAULT_RESOLVER;

/// \class HdGpSceneIndexPlugin
/// 
/// HdGpSceneIndexPlugin provides HdSceneIndexPluginRegistry access to 
/// instantiate HdGpGenerativeProceduralResolvingSceneIndex either directly
/// or automatically via RegisterSceneIndexForRenderer.
///
class HdGpSceneIndexPlugin : public HdSceneIndexPlugin
{
public:
    static const HdSceneIndexPluginRegistry::InsertionPhase
    GetInsertionPhase()
    {
        // XXX Until we have a better way to declare ordering/dependencies b/w
        //     scene index plugins, allow plugins to run before and after this
        //     plugin (i.e., don't use 0).
        return 2;
    }

    HdGpSceneIndexPlugin();

protected:
    HdSceneIndexBaseRefPtr _AppendSceneIndex(
        const HdSceneIndexBaseRefPtr &inputScene,
        const HdContainerDataSourceHandle &inputArgs) override;
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif
