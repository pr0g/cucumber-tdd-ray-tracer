cmake_minimum_required(VERSION 3.15)

project(RayTracerTest)

find_package(CucumberCpp REQUIRED)
find_package(GTest REQUIRED)
find_package(
    Boost COMPONENTS
    filesystem regex date_time thread unit_test_framework program_options
    REQUIRED)

add_executable(${PROJECT_NAME})
target_sources(
    ${PROJECT_NAME}
    PRIVATE
        features/step_definitions/GTestTupleSteps.cpp src/tuple.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE src)
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        CucumberCpp::cucumber-cpp GTest::GTest Boost::boost)
