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

#include "hdPrman/rileyDisplacementSchema.h"

#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/base/trace/trace.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(HdPrmanRileyDisplacementSchemaTokens,
    HD_PRMAN_RILEY_DISPLACEMENT_SCHEMA_TOKENS);

// --(BEGIN CUSTOM CODE: Schema Methods)--
// --(END CUSTOM CODE: Schema Methods)--

HdPrmanRileyShadingNodeVectorSchema
HdPrmanRileyDisplacementSchema::GetDisplacement()
#if HD_API_VERSION >= 66
                                            const
#else
                                                 
#endif
{
    return HdPrmanRileyShadingNodeVectorSchema(_GetTypedDataSource<HdVectorDataSource>(
        HdPrmanRileyDisplacementSchemaTokens->displacement));
}

HdPrmanRileyParamListSchema
HdPrmanRileyDisplacementSchema::GetAttributes()
#if HD_API_VERSION >= 66
                                            const
#else
                                                 
#endif
{
    return HdPrmanRileyParamListSchema(_GetTypedDataSource<HdContainerDataSource>(
        HdPrmanRileyDisplacementSchemaTokens->attributes));
}

/*static*/
HdContainerDataSourceHandle
HdPrmanRileyDisplacementSchema::BuildRetained(
        const HdVectorDataSourceHandle &displacement,
        const HdContainerDataSourceHandle &attributes
)
{
    TfToken _names[2];
    HdDataSourceBaseHandle _values[2];

    size_t _count = 0;

    if (displacement) {
        _names[_count] = HdPrmanRileyDisplacementSchemaTokens->displacement;
        _values[_count++] = displacement;
    }

    if (attributes) {
        _names[_count] = HdPrmanRileyDisplacementSchemaTokens->attributes;
        _values[_count++] = attributes;
    }
    return HdRetainedContainerDataSource::New(_count, _names, _values);
}

HdPrmanRileyDisplacementSchema::Builder &
HdPrmanRileyDisplacementSchema::Builder::SetDisplacement(
    const HdVectorDataSourceHandle &displacement)
{
    _displacement = displacement;
    return *this;
}

HdPrmanRileyDisplacementSchema::Builder &
HdPrmanRileyDisplacementSchema::Builder::SetAttributes(
    const HdContainerDataSourceHandle &attributes)
{
    _attributes = attributes;
    return *this;
}

HdContainerDataSourceHandle
HdPrmanRileyDisplacementSchema::Builder::Build()
{
    return HdPrmanRileyDisplacementSchema::BuildRetained(
        _displacement,
        _attributes
    );
}

/*static*/
HdPrmanRileyDisplacementSchema
HdPrmanRileyDisplacementSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer)
{
    return HdPrmanRileyDisplacementSchema(
        fromParentContainer
        ? HdContainerDataSource::Cast(fromParentContainer->Get(
                HdPrmanRileyDisplacementSchemaTokens->rileyDisplacement))
        : nullptr);
}

/*static*/
const TfToken &
HdPrmanRileyDisplacementSchema::GetSchemaToken()
{
    return HdPrmanRileyDisplacementSchemaTokens->rileyDisplacement;
}

/*static*/
const HdDataSourceLocator &
HdPrmanRileyDisplacementSchema::GetDefaultLocator()
{
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

/* static */
const HdDataSourceLocator &
HdPrmanRileyDisplacementSchema::GetDisplacementLocator()
{
    static const HdDataSourceLocator locator =
        GetDefaultLocator().Append(
            HdPrmanRileyDisplacementSchemaTokens->displacement);
    return locator;
}

/* static */
const HdDataSourceLocator &
HdPrmanRileyDisplacementSchema::GetAttributesLocator()
{
    static const HdDataSourceLocator locator =
        GetDefaultLocator().Append(
            HdPrmanRileyDisplacementSchemaTokens->attributes);
    return locator;
} 

PXR_NAMESPACE_CLOSE_SCOPE