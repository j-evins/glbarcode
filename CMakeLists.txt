cmake_minimum_required (VERSION 3.22)

project (glbarcodepp)


set (Package_Name "glbarcode++")
set (Package_URL  "https://github.com/j-evins/glbarcode")

set (API_Version     "0")
set (Feature_Version "1")
set (Bugfix_Version  "0")

set (Package_Version "${API_Version}.${Feature_Version}.${Bugfix_Version}")

set (Unique_Package_Name ${Package_Name}-${API_Version})
set (Unique_CAPI_Package_Name ${Package_Name}-capi-${API_Version})

# Uncomment to build with pedantic flags
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wpedantic")


# cache variables for installation destinations
include(GNUInstallDirs)


#
# Path for locally defined cmake modules
#
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

#
# Optional dependencies on qrencode and qt libraries
#
find_package (LibQrencode 4.0 QUIET)
find_package (Qt6 6.2 COMPONENTS Core Gui QUIET)

#
# Subdirectories
#
add_subdirectory (glbarcode)
add_subdirectory (glbarcode/capi)
add_subdirectory (examples)
add_subdirectory (app)
add_subdirectory (doc)
add_subdirectory (test)
add_subdirectory (test/capi)


#
# Print configuration information
#
message (STATUS "")
message (STATUS "Project name ............ " ${Package_Name})
message (STATUS "Project version ......... " ${Package_Version})
message (STATUS "Host system ............. " ${CMAKE_HOST_SYSTEM} " " ${CMAKE_HOST_SYSTEM_PROCESSOR})
message (STATUS "Target system ........... " ${CMAKE_SYSTEM} " " ${CMAKE_SYSTEM_PROCESSOR})
message (STATUS "Installation prefix ..... " ${CMAKE_INSTALL_PREFIX})
message (STATUS "Source code location .... " ${CMAKE_SOURCE_DIR})
message (STATUS "CMake version ........... " ${CMAKE_VERSION})
message (STATUS "C++ Compiler ............ " ${CMAKE_CXX_COMPILER_ID} " " ${CMAKE_CXX_COMPILER} " " ${CMAKE_CXX_COMPILER_VERSION})

if (LIBQRENCODE_FOUND)
  message (STATUS "qrencode (optional)...... " ${LIBQRENCODE_VERSION_STRING})
else (LIBQRENCODE_FOUND)
  message (STATUS "qrencode (optional)...... No.")
endif (LIBQRENCODE_FOUND)

if (Qt6_FOUND)
  message (STATUS "Qt version .............. " ${Qt6Core_VERSION})
else (Qt6_FOUND)
  message (STATUS "Qt version .............. No.")
endif (Qt6_FOUND)

message (STATUS "")


