set (PUBLIC_HEADERS
  Factory.hpp
  Barcode.hpp
  Barcode1dBase.hpp
  Barcode2dBase.hpp
  BarcodeCepnet.hpp
  BarcodeCode39Ext.hpp
  BarcodeCode39.hpp
  BarcodeDataMatrix.hpp
  BarcodeEan13.hpp
  BarcodeOnecode.hpp
  BarcodePostnet11.hpp
  BarcodePostnet5.hpp
  BarcodePostnet9.hpp
  BarcodePostnet.hpp
  BarcodeUpcA.hpp
  BarcodeUpcBase.hpp
  BarcodeQrcode.hpp
  Constants.hpp
  Matrix.hpp
  Renderer.hpp
  QtRenderer.hpp
  RendererSvg.hpp
  RendererEps.hpp
  RendererDebug.hpp
  TypeIdList.hpp
  ${CMAKE_CURRENT_BINARY_DIR}/Version.hpp
)

set (PRIVATE_HEADERS
  DrawingPrimitives.hpp
)

set (LIB_SOURCES
  Factory.cpp
  Barcode.cpp
  Barcode1dBase.cpp
  Barcode2dBase.cpp
  BarcodeCode39.cpp
  BarcodeCode39Ext.cpp
  BarcodeUpcBase.cpp
  BarcodeUpcA.cpp
  BarcodeEan13.cpp
  BarcodePostnet.cpp
  BarcodePostnet5.cpp
  BarcodePostnet9.cpp
  BarcodePostnet11.cpp
  BarcodeCepnet.cpp
  BarcodeOnecode.cpp
  BarcodeDataMatrix.cpp
  BarcodeQrcode.cpp
  DrawingPrimitives.cpp
  Renderer.cpp
  QtRenderer.cpp
  RendererSvg.cpp
  RendererEps.cpp
  RendererDebug.cpp
)

configure_file (Version.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/Version.hpp @ONLY)


if (${LIBQRENCODE_FOUND})
  add_definitions (-DHAVE_QRENCODE=1)
  set (OPTIONAL_QRENCODE "QRENCODE::QRENCODE")
else (${LIBQRENCODE_FOUND})
  set (OPTIONAL_QRENCODE "")
endif (${LIBQRENCODE_FOUND})

if (${Qt6_FOUND})
  add_definitions (-DHAVE_QT=1)
  set (OPTIONAL_QT "Qt6::Gui")
else (${Qt6_FOUND})
  set (OPTIONAL_QT "")
endif (${Qt6_FOUND})


add_library (glbarcode++ STATIC
  ${LIB_SOURCES}
)

target_compile_features (glbarcode++
  PUBLIC cxx_std_20
)

target_include_directories (glbarcode++
  PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}..>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/..
)

target_link_libraries (glbarcode++
  PRIVATE
    ${OPTIONAL_QRENCODE}
    ${OPTIONAL_QT}
)


configure_file (${Unique_Package_Name}.pc.in ${CMAKE_CURRENT_BINARY_DIR}/${Unique_Package_Name}.pc @ONLY)


install (TARGETS glbarcode++ LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install (FILES ${PUBLIC_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glbarcode)
install (FILES ${CMAKE_CURRENT_BINARY_DIR}/${Unique_Package_Name}.pc DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
