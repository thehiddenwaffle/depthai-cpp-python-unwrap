cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(PYTHON_EXECUTABLE /usr/bin/python3.11)
set(TARGET_NAME device_unwrap)

add_subdirectory(extern)

project(device_unwrap)
find_package(pybind11 CONFIG REQUIRED)

add_executable(${TARGET_NAME} main.cpp
#        extern/depthai-python/src/py_bindings.cpp
#        extern/depthai-python/src/XLinkBindings.cpp
#        extern/depthai-python/src/DeviceBindings.cpp
#        extern/depthai-python/src/CalibrationHandlerBindings.cpp
#        extern/depthai-python/src/DeviceBootloaderBindings.cpp
#        extern/depthai-python/src/DatatypeBindings.cpp
#        extern/depthai-python/src/DataQueueBindings.cpp
#        extern/depthai-python/src/pipeline/PipelineBindings.cpp
#        extern/depthai-python/src/pipeline/CommonBindings.cpp
#        extern/depthai-python/src/pipeline/AssetManagerBindings.cpp
#        extern/depthai-python/src/openvino/OpenVINOBindings.cpp
#        extern/depthai-python/src/log/LogBindings.cpp
#        extern/depthai-python/src/VersionBindings.cpp
#
#        extern/depthai-python/src/pipeline/node/NodeBindings.cpp
#
#        extern/depthai-python/src/pipeline/node/XLinkInBindings.cpp
#        extern/depthai-python/src/pipeline/node/XLinkOutBindings.cpp
#        extern/depthai-python/src/pipeline/node/ColorCameraBindings.cpp
#        extern/depthai-python/src/pipeline/node/CameraBindings.cpp
#        extern/depthai-python/src/pipeline/node/MonoCameraBindings.cpp
#        extern/depthai-python/src/pipeline/node/StereoDepthBindings.cpp
#        extern/depthai-python/src/pipeline/node/NeuralNetworkBindings.cpp
#        extern/depthai-python/src/pipeline/node/VideoEncoderBindings.cpp
#        extern/depthai-python/src/pipeline/node/ImageManipBindings.cpp
#        extern/depthai-python/src/pipeline/node/SPIOutBindings.cpp
#        extern/depthai-python/src/pipeline/node/SPIInBindings.cpp
#        extern/depthai-python/src/pipeline/node/DetectionNetworkBindings.cpp
#        extern/depthai-python/src/pipeline/node/SystemLoggerBindings.cpp
#        extern/depthai-python/src/pipeline/node/ScriptBindings.cpp
#        extern/depthai-python/src/pipeline/node/SpatialLocationCalculatorBindings.cpp
#        extern/depthai-python/src/pipeline/node/SpatialDetectionNetworkBindings.cpp
#        extern/depthai-python/src/pipeline/node/ObjectTrackerBindings.cpp
#        extern/depthai-python/src/pipeline/node/IMUBindings.cpp
#        extern/depthai-python/src/pipeline/node/EdgeDetectorBindings.cpp
#        extern/depthai-python/src/pipeline/node/FeatureTrackerBindings.cpp
#        extern/depthai-python/src/pipeline/node/AprilTagBindings.cpp
#        extern/depthai-python/src/pipeline/node/DetectionParserBindings.cpp
#        extern/depthai-python/src/pipeline/node/WarpBindings.cpp
#        extern/depthai-python/src/pipeline/node/UVCBindings.cpp
#        extern/depthai-python/src/pipeline/node/ToFBindings.cpp
#        extern/depthai-python/src/pipeline/node/PointCloudBindings.cpp
#        extern/depthai-python/src/pipeline/node/SyncBindings.cpp
#        extern/depthai-python/src/pipeline/node/MessageDemuxBindings.cpp
#
#        extern/depthai-python/src/pipeline/datatype/ADatatypeBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/AprilTagConfigBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/AprilTagsBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/BufferBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/CameraControlBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/EdgeDetectorConfigBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/FeatureTrackerConfigBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/ToFConfigBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/ImageManipConfigBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/ImgDetectionsBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/ImgFrameBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/EncodedFrameBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/IMUDataBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/MessageGroupBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/NNDataBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/SpatialImgDetectionsBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/SpatialLocationCalculatorConfigBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/SpatialLocationCalculatorDataBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/StereoDepthConfigBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/SystemInformationBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/TrackedFeaturesBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/TrackletsBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/PointCloudConfigBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/PointCloudDataBindings.cpp
)

target_compile_definitions(${TARGET_NAME}
        PUBLIC
        DEPTHAI_PYTHON_VERSION="${DEPTHAI_PYTHON_VERSION}"
        DEPTHAI_PYTHON_COMMIT_HASH="${BUILD_COMMIT}"
        DEPTHAI_PYTHON_COMMIT_DATETIME="${BUILD_COMMIT_DATETIME}"
        DEPTHAI_PYTHON_BUILD_DATETIME="${BUILD_DATETIME}"
)

#pybind11_add_module(${TARGET_NAME} STATIC
#        extern/depthai-python/src/py_bindings.hpp
#        extern/depthai-python/src/XLinkBindings.cpp
#        extern/depthai-python/src/DeviceBindings.cpp
#        extern/depthai-python/src/CalibrationHandlerBindings.cpp
#        extern/depthai-python/src/DeviceBootloaderBindings.cpp
#        extern/depthai-python/src/DatatypeBindings.cpp
#        extern/depthai-python/src/DataQueueBindings.cpp
#        extern/depthai-python/src/pipeline/PipelineBindings.cpp
#        extern/depthai-python/src/pipeline/CommonBindings.cpp
#        extern/depthai-python/src/pipeline/AssetManagerBindings.cpp
#        extern/depthai-python/src/openvino/OpenVINOBindings.cpp
#        extern/depthai-python/src/log/LogBindings.cpp
#        extern/depthai-python/src/VersionBindings.cpp
#
#        extern/depthai-python/src/pipeline/node/NodeBindings.cpp
#
#        extern/depthai-python/src/pipeline/node/XLinkInBindings.cpp
#        extern/depthai-python/src/pipeline/node/XLinkOutBindings.cpp
#        extern/depthai-python/src/pipeline/node/ColorCameraBindings.cpp
#        extern/depthai-python/src/pipeline/node/CameraBindings.cpp
#        extern/depthai-python/src/pipeline/node/MonoCameraBindings.cpp
#        extern/depthai-python/src/pipeline/node/StereoDepthBindings.cpp
#        extern/depthai-python/src/pipeline/node/NeuralNetworkBindings.cpp
#        extern/depthai-python/src/pipeline/node/VideoEncoderBindings.cpp
#        extern/depthai-python/src/pipeline/node/ImageManipBindings.cpp
#        extern/depthai-python/src/pipeline/node/SPIOutBindings.cpp
#        extern/depthai-python/src/pipeline/node/SPIInBindings.cpp
#        extern/depthai-python/src/pipeline/node/DetectionNetworkBindings.cpp
#        extern/depthai-python/src/pipeline/node/SystemLoggerBindings.cpp
#        extern/depthai-python/src/pipeline/node/ScriptBindings.cpp
#        extern/depthai-python/src/pipeline/node/SpatialLocationCalculatorBindings.cpp
#        extern/depthai-python/src/pipeline/node/SpatialDetectionNetworkBindings.cpp
#        extern/depthai-python/src/pipeline/node/ObjectTrackerBindings.cpp
#        extern/depthai-python/src/pipeline/node/IMUBindings.cpp
#        extern/depthai-python/src/pipeline/node/EdgeDetectorBindings.cpp
#        extern/depthai-python/src/pipeline/node/FeatureTrackerBindings.cpp
#        extern/depthai-python/src/pipeline/node/AprilTagBindings.cpp
#        extern/depthai-python/src/pipeline/node/DetectionParserBindings.cpp
#        extern/depthai-python/src/pipeline/node/WarpBindings.cpp
#        extern/depthai-python/src/pipeline/node/UVCBindings.cpp
#        extern/depthai-python/src/pipeline/node/ToFBindings.cpp
#        extern/depthai-python/src/pipeline/node/PointCloudBindings.cpp
#        extern/depthai-python/src/pipeline/node/SyncBindings.cpp
#        extern/depthai-python/src/pipeline/node/MessageDemuxBindings.cpp
#
#        extern/depthai-python/src/pipeline/datatype/ADatatypeBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/AprilTagConfigBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/AprilTagsBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/BufferBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/CameraControlBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/EdgeDetectorConfigBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/FeatureTrackerConfigBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/ToFConfigBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/ImageManipConfigBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/ImgDetectionsBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/ImgFrameBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/EncodedFrameBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/IMUDataBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/MessageGroupBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/NNDataBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/SpatialImgDetectionsBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/SpatialLocationCalculatorConfigBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/SpatialLocationCalculatorDataBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/StereoDepthConfigBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/SystemInformationBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/TrackedFeaturesBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/TrackletsBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/PointCloudConfigBindings.cpp
#        extern/depthai-python/src/pipeline/datatype/PointCloudDataBindings.cpp
#)

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