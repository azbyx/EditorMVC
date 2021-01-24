cmake_minimum_required(VERSION 3.2)

set(NAME_EXECUTABLE "EditorMVC")
set(NAME_TEST "tests_mvc")
set(PATHES headers/ interfaces/)
set(LIBRARIES controller factory model painter primitives view)

if($ENV{TRAVIS_BUILD_NUMBER})
	project(${NAME_EXECUTABLE} VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER}  LANGUAGES CXX)
else()
	project(${NAME_EXECUTABLE} VERSION 0.0.1  LANGUAGES CXX)
endif()

exec_program(git ARGS submodule update --init --recursive)
get_filename_component(GTEST_SOURCE ./googletest ABSOLUTE)
add_subdirectory(${GTEST_SOURCE} "googletest")

add_executable(${NAME_EXECUTABLE} ./sources/main.cpp)

add_library(controller ./sources/controller.cpp)
add_library(factory    ./sources/factory.cpp)
add_library(model      ./sources/model.cpp)
add_library(painter    ./sources/painter.cpp)
add_library(primitives ./sources/primitives.cpp)
add_library(view       ./sources/view.cpp)

target_include_directories(controller PRIVATE ${PATHES})
target_include_directories(factory PRIVATE ${PATHES})
target_include_directories(model PRIVATE ${PATHES})
target_include_directories(painter PRIVATE ${PATHES})
target_include_directories(primitives PRIVATE ${PATHES})
target_include_directories(view PRIVATE ${PATHES})
target_include_directories(${NAME_EXECUTABLE} PRIVATE ${PATHES})

target_link_libraries(${NAME_EXECUTABLE} PRIVATE ${LIBRARIES})

add_executable(${NAME_TEST} ./sources/gtests.cpp)

target_link_libraries(${NAME_TEST} PRIVATE gmock ${LIBRARIES})

target_include_directories(${NAME_TEST} PRIVATE ${PATHES})

set_target_properties(${NAME_EXECUTABLE} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

set_target_properties(${NAME_TEST} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(${NAME_EXECUTABLE} PRIVATE /W4)
    target_compile_options(${NAME_TEST} PRIVATE /W4)
else()
    target_compile_options(${NAME_EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
    target_compile_options(${NAME_TEST} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

install(TARGETS ${NAME_EXECUTABLE} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT azbyx@inbox.ru)

include(CPack)

enable_testing()

add_test(${NAME_TEST} ${NAME_TEST})
