cmake_minimum_required(VERSION 3.5)
project(SCIFIO-bug)

set(ITK_NO_IO_FACTORY_REGISTER_MANAGER TRUE)
find_package(ITK)
include(${ITK_USE_FILE})
add_executable(reader reader.cpp)
target_link_libraries(reader ${ITK_LIBRARIES})

add_executable(writer writer.cpp)
target_link_libraries(writer ${ITK_LIBRARIES})
