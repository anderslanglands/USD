#
# Copyright 2016 Pixar
#
# Licensed under the Apache License, Version 2.0 (the "Apache License")
# with the following modification; you may not use this file except in
# compliance with the Apache License and the following modification to it:
# Section 6. Trademarks. is deleted and replaced with:
#
# 6. Trademarks. This License does not grant permission to use the trade
#    names, trademarks, service marks, or product names of the Licensor
#    and its affiliates, except as required to comply with Section 4(c) of
#    the License and to reproduce the content of the NOTICE file.
#
# You may obtain a copy of the Apache License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the Apache License with the above modification is
# distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied. See the Apache License for the specific
# language governing permissions and limitations under the Apache License.
#

include(gccclangshareddefaults)

set(_PXR_CXX_FLAGS "${_PXR_GCC_CLANG_SHARED_CXX_FLAGS}")

# Prevent floating point result discrepancies on Apple platforms
# due to multiplication+additions being converted to FMA
if (APPLE)
    set(_PXR_CXX_FLAGS "${_PXR_CXX_FLAGS} -ffp-contract=off")
endif()

# clang annoyingly warns about the -pthread option if it's only linking.
if(CMAKE_USE_PTHREADS_INIT)
    _disable_warning("unused-command-line-argument")
endif()
