cmake_minimum_required(VERSION 3.24)
project(EnumerateDevices)

# Get and normalize the SDK root directory from the environment variable
file(TO_CMAKE_PATH "$ENV{SDSP-PF-SDK-Root}" SDSP_PF_SDK_ROOT)

# Ensure the environment variable is set
if(NOT SDSP_PF_SDK_ROOT OR SDSP_PF_SDK_ROOT STREQUAL "")
    message(FATAL_ERROR "Environment variable SDSP-PF-SDK-Root is not set or empty!")
endif()

# Include all headers from the SDK
set(SDK_INCLUDE_DIR "${SDSP_PF_SDK_ROOT}/include")
include_directories(${SDK_INCLUDE_DIR})

# Find all header files (.h and .hpp)
file(GLOB_RECURSE SDK_HEADERS "${SDK_INCLUDE_DIR}/*.h" "${SDK_INCLUDE_DIR}/*.hpp")

# Add main.cpp and headers to the project
set(PROJECT_FILES main.cpp ${CLEANED_HEADERS})  # Change main.cpp to your actual entry file

# Create an executable 
add_executable(${PROJECT_NAME} ${PROJECT_FILES})

# Find all DLLs inside the bin directory
file(GLOB SDK_DLLS "${SDSP_PF_SDK_ROOT}/bin/*.dll")

# Copy all DLLs to the output directory
foreach(DLL ${SDK_DLLS})
    file(TO_CMAKE_PATH "${DLL}" DLL)  # Normalize DLL path
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${DLL}
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
        COMMENT "Copying ${DLL} to output directory"
    )
endforeach()

if(MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif(MSVC)
