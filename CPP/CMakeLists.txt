cmake_minimum_required(VERSION 3.3)
project(3DGameEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")

set(SOURCE_FILES
        src/glew/glew.c
        src/glew/glew.h
        src/test/Test.cpp src/engine/core/Engine.cpp src/engine/core/Engine.h src/engine/core/Time.cpp src/engine/core/Time.h src/engine/window/Window.cpp src/engine/window/Window.h)
add_executable(3DGameEngine ${SOURCE_FILES})
find_package(OpenGL REQUIRED)
if(APPLE)
    include_directories(${OPENGL_INCLUDE_DIR}/OpenGL lib/glfw/include/GLFW)
else()
    include_directories(${OPENGL_INCLUDE_DIR}/GL lib/glfw/include/GLFW)
endif()

add_subdirectory(lib/glfw)
#
target_link_libraries (3DGameEngine glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES} opengl32)


