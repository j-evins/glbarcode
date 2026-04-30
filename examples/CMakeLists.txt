include_directories(
  ${glbarcodepp_SOURCE_DIR}
)

link_directories(
  ${glbarcodepp_SOURCE_DIR}/glbarcode
)


add_executable(generate-samples
  generate-samples.cpp
)

target_link_libraries(generate-samples
  glbarcode++
)


add_executable(usage-example-1
  usage-example-1.cpp
)

target_link_libraries(usage-example-1
  glbarcode++
)

add_executable(mybarcode-example
  MyBarcode/main.cpp
  MyBarcode/MyBarcode.cpp
)

target_link_libraries(mybarcode-example
  glbarcode++
)

