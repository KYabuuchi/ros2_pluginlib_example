cmake_minimum_required(VERSION 3.14)
project(user_defined_plugin)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

pluginlib_export_plugin_description_file(base_interface plugins.xml)

ament_auto_add_library(${PROJECT_NAME}
  SHARED
  user_defined_plugin.cpp
)

ament_auto_package()
