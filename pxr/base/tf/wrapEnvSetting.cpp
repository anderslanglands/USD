//
// Copyright 2016 Pixar
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
#include "pxr/pxr.h"

#include <locale>

#include <boost/python/def.hpp>
#include <boost/python/object.hpp>

#include <string>
#include <variant>

#include "pxr/base/tf/envSetting.h"

PXR_NAMESPACE_OPEN_SCOPE

extern std::variant<int, bool, std::string> const *
Tf_GetEnvSettingByName(std::string const&);

static boost::python::object
_GetEnvSettingByName(std::string const& name) {
    std::variant<int, bool, std::string> const *
        variantValue = Tf_GetEnvSettingByName(name);

    if (!variantValue) {
        return boost::python::object();
    } 

    if (std::string const *value = std::get_if<std::string>(variantValue)) {
        return boost::python::object(*value);
    } else if (bool const *value = std::get_if<bool>(variantValue)) {
        return boost::python::object(*value);
    } else if (int const *value = std::get_if<int>(variantValue)) {
        return boost::python::object(*value); 
    } 
            
    return boost::python::object();
}

PXR_NAMESPACE_CLOSE_SCOPE

PXR_NAMESPACE_USING_DIRECTIVE

void wrapEnvSetting() {
    def("GetEnvSetting", &_GetEnvSettingByName);
}
