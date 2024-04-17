cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(PYTHON_EXECUTABLE /usr/bin/python3.11)
set(TARGET_NAME device_unwrap)

add_subdirectory(extern)

project(device_unwrap)
find_package(pybind11 CONFIG REQUIRED)

add_executable(${TARGET_NAME} main.cpp)

target_compile_definitions(${TARGET_NAME}
        PUBLIC
        DEPTHAI_PYTHON_VERSION="${DEPTHAI_PYTHON_VERSION}"
        DEPTHAI_PYTHON_COMMIT_HASH="${BUILD_COMMIT}"
        DEPTHAI_PYTHON_COMMIT_DATETIME="${BUILD_COMMIT_DATETIME}"
        DEPTHAI_PYTHON_BUILD_DATETIME="${BUILD_DATETIME}"
)

target_include_directories(${TARGET_NAME} PUBLIC extern/depthai-python/src)

target_link_libraries(${TARGET_NAME}
        PUBLIC
        depthai
        # pybind11
        pybind11::pybind11
        pybind11::module
        pybind11::embed
        depthai::core # Use non-opencv target as we use opencv-python in bindings
        hedley
        pybind11_json
)