cmake_minimum_required(VERSION 3.3)
project(3DGameEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")
add_definitions(-DGLEW_STATIC)

set(GLEW_SOURCE src/glew/glew.c src/glew/glew.h)

set(SOURCE_FILES ${GLEW_SOURCE} src/test/Test.cpp src/engine/core/Engine.cpp src/engine/core/Engine.h src/engine/util/Time.cpp src/engine/util/Time.h src/engine/window/Window.cpp src/engine/window/Window.h src/engine/input/Input.cpp src/engine/input/Input.h src/engine/input/Input.cpp src/engine/input/Input.h src/engine/game/Game.cpp src/engine/game/Game.h src/engine/math/Vector2f.h src/engine/math/Vector2f.cpp src/engine/math/Vector2f.h src/engine/math/Vector3f.cpp src/engine/math/Vector3f.h src/engine/math/Matrix4f.cpp src/engine/math/Matrix4f.h src/engine/math/Quaternion.cpp src/engine/math/Quaternion.h src/engine/util/RenderUtil.cpp src/engine/util/RenderUtil.h src/engine/mesh/Vertex.cpp src/engine/mesh/Vertex.h src/engine/mesh/Mesh.cpp src/engine/mesh/Mesh.h src/engine/shader/Shader.cpp src/engine/shader/Shader.h src/engine/util/Util.cpp src/engine/util/Util.h src/engine/util/ResourceLoader.cpp src/engine/util/ResourceLoader.h src/engine/transformation/Transformation.cpp src/engine/transformation/Transformation.h)
add_executable(3DGameEngine ${SOURCE_FILES})

target_link_libraries (3DGameEngine glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES})

set(GameEngineIncludes lib/glfw/include/GLFW)

#Opengl, GLEW, and GLFW
find_package(OpenGL REQUIRED)
if(APPLE)
    include_directories(${OPENGL_INCLUDE_DIR}/OpenGL ${GameEngineIncludes})
else()
    include_directories(${OPENGL_INCLUDE_DIR}/GL ${GameEngineIncludes})
endif()

add_subdirectory(lib/glfw)


