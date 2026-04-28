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

add_library (${Lib_Name} SHARED
  ${LIB_SOURCES}
)

target_compile_features (${Lib_Name}
  PUBLIC cxx_std_20
)

target_include_directories (${Lib_Name}
  PUBLIC
    ..
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/..
)

target_link_libraries (${Lib_Name}
  PRIVATE
    ${OPTIONAL_QRENCODE}
    ${OPTIONAL_QT}
)


configure_file (Version.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/Version.hpp @ONLY)
configure_file (${Unique_Package_Name}.pc.in ${CMAKE_CURRENT_BINARY_DIR}/${Unique_Package_Name}.pc @ONLY)


install (TARGETS ${Lib_Name} LIBRARY DESTINATION lib)
install (FILES ${PUBLIC_HEADERS} DESTINATION include/${Unique_Package_Name}/glbarcode)
install (FILES ${CMAKE_CURRENT_BINARY_DIR}/${Unique_Package_Name}.pc DESTINATION lib/pkgconfig)
