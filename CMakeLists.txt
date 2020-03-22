CMAKE_MINIMUM_REQUIRED(VERSION 3.1.0)

PROJECT(rtsdl LANGUAGES CXX VERSION 0.0.1)

SET(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(
    "src/"
    "extlibs/SDL2/include/"
    "extlibs/GLM/include/"
)

ADD_EXECUTABLE(
    ${PROJECT_NAME}
    src/main.cpp
    src/Render.cpp
    src/Scene.cpp
    src/Camera.cpp
    src/Sphere.cpp
    src/Plane.cpp
)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
    mingw32
    "${CMAKE_CURRENT_SOURCE_DIR}/extlibs/SDL2/lib/libSDL2main.a"
    "${CMAKE_CURRENT_SOURCE_DIR}/extlibs/SDL2/lib/libSDL2.dll.a"
)

INSTALL(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)