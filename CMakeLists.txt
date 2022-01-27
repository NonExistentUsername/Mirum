cmake_minimum_required(VERSION 3.0.0)
project(Mirum VERSION 0.1.0)

file (GLOB_RECURSE MIRUM_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file (GLOB_RECURSE MIRUM_HEADERS CONFIGURE_DEPENDS "include/*.hpp")

set (MIRUM_INCLUDE_DIRS "")
foreach (_headerFile ${MIRUM_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND MIRUM_INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES MIRUM_INCLUDE_DIRS)

include(CTest)
enable_testing()

include_directories(src)
include_directories(include)
add_executable(Mirum ${MIRUM_SOURCES})
target_include_directories(Mirum PRIVATE ${Foo_INCLUDE_DIRS})

link_directories(C:/msys64/mingw64/bin)
link_directories(C:/msys64/mingw64/lib)

target_link_libraries(Mirum sfml-graphics)
target_link_libraries(Mirum sfml-window)
target_link_libraries(Mirum sfml-system)
target_link_libraries(Mirum sfml-network)
target_link_libraries(Mirum sfml-audio)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
