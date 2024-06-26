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

#ifndef {{ HEADER_GUARD|snake }}_{{ FILE_NAME|snake }}_H
#define {{ HEADER_GUARD|snake }}_{{ FILE_NAME|snake }}_H

#include "pxr/pxr.h"
#include "hdPrman/api.h"
#include "hdPrman/sceneIndexObserverApi.h"

#ifdef HDPRMAN_USE_SCENE_INDEX_OBSERVER

#include "hdPrman/rileyPrimBase.h"

PXR_NAMESPACE_OPEN_SCOPE

{% for t in FORWARD_DECLS -%}
using HdPrman_{{t}}PrimHandle =
    std::shared_ptr<class HdPrman_{{t}}Prim>;
{% endfor %}
using HdPrman_{{ SCHEMA_NAME }}PrimHandle =
    std::shared_ptr<class HdPrman_{{ SCHEMA_NAME }}Prim>;

/// \class HdPrman_{{SCHEMA_NAME}}Prim
///
/// Wraps a riley {{RILEY_TYPE}} object, initializing or updating it
/// using the {{SCHEMA_CLASS_NAME}}.
///
class HdPrman_{{SCHEMA_NAME}}Prim : public HdPrman_RileyPrimBase
{
public:
    HdPrman_{{SCHEMA_NAME}}Prim(
        HdContainerDataSourceHandle const &primSource,
        const HdsiPrimManagingSceneIndexObserver *observer,
        HdPrman_RenderParam * renderParam);

    ~HdPrman_{{SCHEMA_NAME}}Prim() override;

    using RileyId = riley::{{RILEY_TYPE}}Id;
{%- if ADD_RILEY_ID_LIST %}
    using RileyIdList = riley::{{RILEY_TYPE}}List;
{% endif %}

    const RileyId &GetRileyId() const { return _rileyId; }

protected:
    void _Dirty(
        const HdSceneIndexObserver::DirtiedPrimEntry &entry,
        const HdsiPrimManagingSceneIndexObserver * observer) override;

private:
{%- for name, type_name, opt_dict in MEMBERS -%}
{%- if 'RILEY_RELATIONSHIP_TARGET' in opt_dict %}
    // If there is a riley render target constructed from a riley render
    // output, the render target needs to be deleted before the render
    // output is deleted.
{%- if type_name == 'HdPathArrayDataSource' %}
    // To ensure this, we keep handles to the prims wrapping the render
    // outputs here.
    std::vector<HdPrman_{{opt_dict['RILEY_RELATIONSHIP_TARGET']}}PrimHandle> _{{name}}Prims;
{% else %}
    // To ensure this, we keep handles to the prims wrapping the render
    // outputs here.
    HdPrman_{{opt_dict['RILEY_RELATIONSHIP_TARGET']}}PrimHandle _{{name}}Prim;
{%- endif -%}
{%- endif -%}
{%- endfor %}

// --(BEGIN CUSTOM CODE: Fields)--
{%- if 'Fields' in CUSTOM_CODE_HEADER %}
{{ CUSTOM_CODE_HEADER['Fields'] }}
{%- endif %}
// --(END CUSTOM CODE: Fields)--

    RileyId _rileyId;
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif // #ifdef HDPRMAN_USE_SCENE_INDEX_OBSERVER

#endif

