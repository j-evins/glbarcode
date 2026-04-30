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
find_package (LibQrencode 3.4 QUIET)
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

