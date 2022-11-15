cmake_minimum_required(VERSION 3.0.0)
project(Astro VERSION 0.1.0)

# include(CTest)
# enable_testing()
include(/usr/local/vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(box2d CONFIG REQUIRED)

find_package(GLEW REQUIRED)
# include_directories(${GLEW_INCLUDE_DIRS})
# link_libraries(${GLEW_LIBRARIES})

find_package(glfw3 3.3 REQUIRED)
# link_libraries(glfw)

find_package(OpenGL REQUIRED)
# link_libraries(OpenGL::GL)

add_executable(Astro main.cpp)
target_link_libraries(Astro PRIVATE 
    box2d::box2d
    ${GLEW_LIBRARIES}
    glfw
    OpenGL::GL
)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
