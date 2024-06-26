//
// Copyright 2023 Pixar
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
////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/* **                                                                      ** */
/* ** This file is generated by a script.                                  ** */
/* **                                                                      ** */
/* ** Do not edit it directly (unless it is within a CUSTOM CODE section)! ** */
/* ** Edit hdSchemaDefs.py instead to make changes.                        ** */
/* **                                                                      ** */
/* ************************************************************************** */

#include "hdPrman/rileyRenderTargetSchema.h"

#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/base/trace/trace.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(HdPrmanRileyRenderTargetSchemaTokens,
    HD_PRMAN_RILEY_RENDER_TARGET_SCHEMA_TOKENS);

// --(BEGIN CUSTOM CODE: Schema Methods)--
// --(END CUSTOM CODE: Schema Methods)--

HdPathArrayDataSourceHandle
HdPrmanRileyRenderTargetSchema::GetRenderOutputs()
#if HD_API_VERSION >= 66
                                            const
#else
                                                 
#endif
{
    return _GetTypedDataSource<HdPathArrayDataSource>(
        HdPrmanRileyRenderTargetSchemaTokens->renderOutputs);
}

HdVec3iDataSourceHandle
HdPrmanRileyRenderTargetSchema::GetExtent()
#if HD_API_VERSION >= 66
                                            const
#else
                                                 
#endif
{
    return _GetTypedDataSource<HdVec3iDataSource>(
        HdPrmanRileyRenderTargetSchemaTokens->extent);
}

HdTokenDataSourceHandle
HdPrmanRileyRenderTargetSchema::GetFilterMode()
#if HD_API_VERSION >= 66
                                            const
#else
                                                 
#endif
{
    return _GetTypedDataSource<HdTokenDataSource>(
        HdPrmanRileyRenderTargetSchemaTokens->filterMode);
}

HdFloatDataSourceHandle
HdPrmanRileyRenderTargetSchema::GetPixelVariance()
#if HD_API_VERSION >= 66
                                            const
#else
                                                 
#endif
{
    return _GetTypedDataSource<HdFloatDataSource>(
        HdPrmanRileyRenderTargetSchemaTokens->pixelVariance);
}

HdPrmanRileyParamListSchema
HdPrmanRileyRenderTargetSchema::GetParams()
#if HD_API_VERSION >= 66
                                            const
#else
                                                 
#endif
{
    return HdPrmanRileyParamListSchema(_GetTypedDataSource<HdContainerDataSource>(
        HdPrmanRileyRenderTargetSchemaTokens->params));
}

/*static*/
HdContainerDataSourceHandle
HdPrmanRileyRenderTargetSchema::BuildRetained(
        const HdPathArrayDataSourceHandle &renderOutputs,
        const HdVec3iDataSourceHandle &extent,
        const HdTokenDataSourceHandle &filterMode,
        const HdFloatDataSourceHandle &pixelVariance,
        const HdContainerDataSourceHandle &params
)
{
    TfToken _names[5];
    HdDataSourceBaseHandle _values[5];

    size_t _count = 0;

    if (renderOutputs) {
        _names[_count] = HdPrmanRileyRenderTargetSchemaTokens->renderOutputs;
        _values[_count++] = renderOutputs;
    }

    if (extent) {
        _names[_count] = HdPrmanRileyRenderTargetSchemaTokens->extent;
        _values[_count++] = extent;
    }

    if (filterMode) {
        _names[_count] = HdPrmanRileyRenderTargetSchemaTokens->filterMode;
        _values[_count++] = filterMode;
    }

    if (pixelVariance) {
        _names[_count] = HdPrmanRileyRenderTargetSchemaTokens->pixelVariance;
        _values[_count++] = pixelVariance;
    }

    if (params) {
        _names[_count] = HdPrmanRileyRenderTargetSchemaTokens->params;
        _values[_count++] = params;
    }
    return HdRetainedContainerDataSource::New(_count, _names, _values);
}

HdPrmanRileyRenderTargetSchema::Builder &
HdPrmanRileyRenderTargetSchema::Builder::SetRenderOutputs(
    const HdPathArrayDataSourceHandle &renderOutputs)
{
    _renderOutputs = renderOutputs;
    return *this;
}

HdPrmanRileyRenderTargetSchema::Builder &
HdPrmanRileyRenderTargetSchema::Builder::SetExtent(
    const HdVec3iDataSourceHandle &extent)
{
    _extent = extent;
    return *this;
}

HdPrmanRileyRenderTargetSchema::Builder &
HdPrmanRileyRenderTargetSchema::Builder::SetFilterMode(
    const HdTokenDataSourceHandle &filterMode)
{
    _filterMode = filterMode;
    return *this;
}

HdPrmanRileyRenderTargetSchema::Builder &
HdPrmanRileyRenderTargetSchema::Builder::SetPixelVariance(
    const HdFloatDataSourceHandle &pixelVariance)
{
    _pixelVariance = pixelVariance;
    return *this;
}

HdPrmanRileyRenderTargetSchema::Builder &
HdPrmanRileyRenderTargetSchema::Builder::SetParams(
    const HdContainerDataSourceHandle &params)
{
    _params = params;
    return *this;
}

HdContainerDataSourceHandle
HdPrmanRileyRenderTargetSchema::Builder::Build()
{
    return HdPrmanRileyRenderTargetSchema::BuildRetained(
        _renderOutputs,
        _extent,
        _filterMode,
        _pixelVariance,
        _params
    );
}

/*static*/
HdPrmanRileyRenderTargetSchema
HdPrmanRileyRenderTargetSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer)
{
    return HdPrmanRileyRenderTargetSchema(
        fromParentContainer
        ? HdContainerDataSource::Cast(fromParentContainer->Get(
                HdPrmanRileyRenderTargetSchemaTokens->rileyRenderTarget))
        : nullptr);
}

/*static*/
const TfToken &
HdPrmanRileyRenderTargetSchema::GetSchemaToken()
{
    return HdPrmanRileyRenderTargetSchemaTokens->rileyRenderTarget;
}

/*static*/
const HdDataSourceLocator &
HdPrmanRileyRenderTargetSchema::GetDefaultLocator()
{
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

/* static */
const HdDataSourceLocator &
HdPrmanRileyRenderTargetSchema::GetRenderOutputsLocator()
{
    static const HdDataSourceLocator locator =
        GetDefaultLocator().Append(
            HdPrmanRileyRenderTargetSchemaTokens->renderOutputs);
    return locator;
}

/* static */
const HdDataSourceLocator &
HdPrmanRileyRenderTargetSchema::GetExtentLocator()
{
    static const HdDataSourceLocator locator =
        GetDefaultLocator().Append(
            HdPrmanRileyRenderTargetSchemaTokens->extent);
    return locator;
}

/* static */
const HdDataSourceLocator &
HdPrmanRileyRenderTargetSchema::GetFilterModeLocator()
{
    static const HdDataSourceLocator locator =
        GetDefaultLocator().Append(
            HdPrmanRileyRenderTargetSchemaTokens->filterMode);
    return locator;
}

/* static */
const HdDataSourceLocator &
HdPrmanRileyRenderTargetSchema::GetPixelVarianceLocator()
{
    static const HdDataSourceLocator locator =
        GetDefaultLocator().Append(
            HdPrmanRileyRenderTargetSchemaTokens->pixelVariance);
    return locator;
}

/* static */
const HdDataSourceLocator &
HdPrmanRileyRenderTargetSchema::GetParamsLocator()
{
    static const HdDataSourceLocator locator =
        GetDefaultLocator().Append(
            HdPrmanRileyRenderTargetSchemaTokens->params);
    return locator;
}

/*static*/
HdTokenDataSourceHandle
HdPrmanRileyRenderTargetSchema::BuildFilterModeDataSource(
    const TfToken &filterMode)
{

    if (filterMode == HdPrmanRileyRenderTargetSchemaTokens->importance) {
        static const HdRetainedTypedSampledDataSource<TfToken>::Handle ds =
            HdRetainedTypedSampledDataSource<TfToken>::New(filterMode);
        return ds;
    }
    if (filterMode == HdPrmanRileyRenderTargetSchemaTokens->weighted) {
        static const HdRetainedTypedSampledDataSource<TfToken>::Handle ds =
            HdRetainedTypedSampledDataSource<TfToken>::New(filterMode);
        return ds;
    }
    // fallback for unknown token
    return HdRetainedTypedSampledDataSource<TfToken>::New(filterMode);
} 

PXR_NAMESPACE_CLOSE_SCOPE