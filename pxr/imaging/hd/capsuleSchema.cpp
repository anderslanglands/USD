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
/* ** Edit hdGen/schema.py instead to make changes.                        ** */
/* **                                                                      ** */
/* ************************************************************************** */

#include "pxr/imaging/hd/capsuleSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/base/trace/trace.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(HdCapsuleSchemaTokens,
    HD_CAPSULE_SCHEMA_TOKENS);

// --(BEGIN CUSTOM CODE: Schema Methods)--
// --(END CUSTOM CODE: Schema Methods)--




HdDoubleDataSourceHandle
HdCapsuleSchema::GetHeight()
{
    return _GetTypedDataSource<HdDoubleDataSource>(
        HdCapsuleSchemaTokens->height);
}

HdDoubleDataSourceHandle
HdCapsuleSchema::GetRadius()
{
    return _GetTypedDataSource<HdDoubleDataSource>(
        HdCapsuleSchemaTokens->radius);
}

HdDoubleDataSourceHandle
HdCapsuleSchema::GetRadiusTop()
{
    return _GetTypedDataSource<HdDoubleDataSource>(
        HdCapsuleSchemaTokens->radiusTop);
}

HdDoubleDataSourceHandle
HdCapsuleSchema::GetRadiusBottom()
{
    return _GetTypedDataSource<HdDoubleDataSource>(
        HdCapsuleSchemaTokens->radiusBottom);
}

HdTokenDataSourceHandle
HdCapsuleSchema::GetAxis()
{
    return _GetTypedDataSource<HdTokenDataSource>(
        HdCapsuleSchemaTokens->axis);
}

/*static*/
HdContainerDataSourceHandle
HdCapsuleSchema::BuildRetained(
        const HdDoubleDataSourceHandle &height,
        const HdDoubleDataSourceHandle &radius,
        const HdDoubleDataSourceHandle &radiusTop,
        const HdDoubleDataSourceHandle &radiusBottom,
        const HdTokenDataSourceHandle &axis
)
{
    TfToken _names[5];
    HdDataSourceBaseHandle _values[5];

    size_t _count = 0;
    if (height) {
        _names[_count] = HdCapsuleSchemaTokens->height;
        _values[_count++] = height;
    }

    if (radius) {
        _names[_count] = HdCapsuleSchemaTokens->radius;
        _values[_count++] = radius;
    }

    if (radiusTop) {
        _names[_count] = HdCapsuleSchemaTokens->radiusTop;
        _values[_count++] = radiusTop;
    }

    if (radiusBottom) {
        _names[_count] = HdCapsuleSchemaTokens->radiusBottom;
        _values[_count++] = radiusBottom;
    }

    if (axis) {
        _names[_count] = HdCapsuleSchemaTokens->axis;
        _values[_count++] = axis;
    }

    return HdRetainedContainerDataSource::New(_count, _names, _values);
}

/*static*/
HdCapsuleSchema
HdCapsuleSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer)
{
    return HdCapsuleSchema(
        fromParentContainer
        ? HdContainerDataSource::Cast(fromParentContainer->Get(
                HdCapsuleSchemaTokens->capsule))
        : nullptr);
}

/*static*/
const TfToken &
HdCapsuleSchema::GetSchemaToken()
{
    return HdCapsuleSchemaTokens->capsule;
}

/*static*/
const HdDataSourceLocator &
HdCapsuleSchema::GetDefaultLocator()
{
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
} 

/*static*/
HdTokenDataSourceHandle
HdCapsuleSchema::BuildAxisDataSource(
    const TfToken &axis)
{
    if (axis == HdCapsuleSchemaTokens->X) {
        static const HdRetainedTypedSampledDataSource<TfToken>::Handle ds =
            HdRetainedTypedSampledDataSource<TfToken>::New(axis);
        return ds;
    }
    if (axis == HdCapsuleSchemaTokens->Y) {
        static const HdRetainedTypedSampledDataSource<TfToken>::Handle ds =
            HdRetainedTypedSampledDataSource<TfToken>::New(axis);
        return ds;
    }
    if (axis == HdCapsuleSchemaTokens->Z) {
        static const HdRetainedTypedSampledDataSource<TfToken>::Handle ds =
            HdRetainedTypedSampledDataSource<TfToken>::New(axis);
        return ds;
    }

    // fallback for unknown token
    return HdRetainedTypedSampledDataSource<TfToken>::New(axis);
}

HdCapsuleSchema::Builder &
HdCapsuleSchema::Builder::SetHeight(
    const HdDoubleDataSourceHandle &height)
{
    _height = height;
    return *this;
}

HdCapsuleSchema::Builder &
HdCapsuleSchema::Builder::SetRadius(
    const HdDoubleDataSourceHandle &radius)
{
    _radius = radius;
    return *this;
}

HdCapsuleSchema::Builder &
HdCapsuleSchema::Builder::SetRadiusTop(
    const HdDoubleDataSourceHandle &radiusTop)
{
    _radiusTop = radiusTop;
    return *this;
}

HdCapsuleSchema::Builder &
HdCapsuleSchema::Builder::SetRadiusBottom(
    const HdDoubleDataSourceHandle &radiusBottom)
{
    _radiusBottom = radiusBottom;
    return *this;
}

HdCapsuleSchema::Builder &
HdCapsuleSchema::Builder::SetAxis(
    const HdTokenDataSourceHandle &axis)
{
    _axis = axis;
    return *this;
}

HdContainerDataSourceHandle
HdCapsuleSchema::Builder::Build()
{
    return HdCapsuleSchema::BuildRetained(
        _height,
        _radius,
        _radiusTop,
        _radiusBottom,
        _axis
    );
}


PXR_NAMESPACE_CLOSE_SCOPE