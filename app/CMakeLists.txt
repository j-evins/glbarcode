include_directories (
  ${glbarcodepp_SOURCE_DIR}
)

link_directories (
  ${glbarcodepp_SOURCE_DIR}/glbarcode
)

add_executable (glbarcode
  main.cpp
)

target_link_libraries (glbarcode
  glbarcode++
)


install (TARGETS glbarcode RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
