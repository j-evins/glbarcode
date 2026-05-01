include_directories (
  ${glbarcodepp_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
)

set (PUBLIC_HEADERS
  gbc_factory.h
  gbc_barcode.h
  gbc_renderer.h
  gbc_renderer_debug.h
  gbc_renderer_eps.h
  gbc_renderer_svg.h
  ${CMAKE_CURRENT_BINARY_DIR}/gbc_version.h
)

set (LIB_SOURCES
  gbc_factory.cpp
  gbc_barcode.cpp
  gbc_renderer.cpp
  gbc_renderer_debug.cpp
  gbc_renderer_eps.cpp
  gbc_renderer_svg.cpp
)

configure_file (gbc_version.h.in ${CMAKE_CURRENT_BINARY_DIR}/gbc_version.h @ONLY)


add_library (glbarcode-capi STATIC
  ${LIB_SOURCES}
)

target_compile_features (glbarcode++
  PRIVATE cxx_std_20
)

target_include_directories (glbarcode-capi
  PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}..>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/..
)

target_link_libraries (glbarcode-capi
  PRIVATE
    glbarcode++
)


configure_file (${Unique_CAPI_Package_Name}.pc.in ${CMAKE_CURRENT_BINARY_DIR}/${Unique_CAPI_Package_Name}.pc @ONLY)

install (TARGETS glbarcode-capi LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install (FILES ${PUBLIC_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glbarcode/capi)
install (FILES ${CMAKE_CURRENT_BINARY_DIR}/${Unique_CAPI_Package_Name}.pc DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
