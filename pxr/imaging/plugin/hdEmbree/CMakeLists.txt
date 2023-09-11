set(PXR_PREFIX pxr/imaging)
set(PXR_PACKAGE hdEmbree)

if(NOT EMBREE_FOUND)
    message(WARNING "Not building ${PXR_PACKAGE} because of missing dependency: Embree")
    return()
endif()
if (NOT ${PXR_BUILD_GPU_SUPPORT})
    message(STATUS
        "Skipping ${PXR_PACKAGE} because PXR_BUILD_GPU_SUPPORT is OFF")
    return()
endif()
if(NOT OpenImageIO_FOUND)
    message(WARNING "Not building ${PXR_PACKAGE} because of missing dependency: OpenImageIO")
    return()
endif()

# Use the import targets set by Imath's package config
if (Imath_FOUND)
    set(__OIIO_IMATH_LIBS "Imath::Imath")
else()
    set(__OIIO_IMATH_INCLUDE ${OPENEXR_INCLUDE_DIRS})
    set(__OIIO_IMATH_LIBS ${OPENEXR_LIBRARIES})
endif()

pxr_plugin(hdEmbree
   LIBRARIES
        plug
        tf
        vt
        gf
        work
        hf
        hd
        hdx
        ${TBB_tbb_LIBRARY}
        ${EMBREE_LIBRARY}
        ${OIIO_LIBRARIES}
        ${__OIIO_IMATH_LIBS}

    INCLUDE_DIRS
        ${TBB_INCLUDE_DIRS}
        ${EMBREE_INCLUDE_DIR}
        ${OIIO_INCLUDE_DIRS}
        ${__OIIO_IMATH_INCLUDE}

    PUBLIC_CLASSES
        config
        instancer
        light
        mesh
        meshSamplers
        renderBuffer
        renderer
        rendererPlugin
        renderDelegate
        renderPass
        sampler
        pcg_basic

    PUBLIC_HEADERS
        context.h
        renderParam.h

    PRIVATE_CLASSES
        implicitSurfaceSceneIndexPlugin

    RESOURCE_FILES
        plugInfo.json

    DOXYGEN_FILES
        overview.dox
)

if (X11_FOUND OR APPLE)
pxr_build_test(testHdEmbree
    LIBRARIES
        hdEmbree
        garch
        arch
        hio
    CPPFILES
        testenv/testHdEmbree.cpp
)
endif()
