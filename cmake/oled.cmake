set(oled ${CONAN_EXAMPLEOLED_ROOT})
include(MQTT)

file(GLOB SOURCE_FILES ${oled}/src/*)

add_library(oled STATIC ${SOURCE_FILES})
target_include_directories(oled PRIVATE ${oled}/include ${PLATFORM_CXX_INCLUDES})
target_compile_options(oled PRIVATE "$<$<CONFIG:ALL>:${PLATFORM_CXX_FLAGS}>")
target_compile_definitions(oled PRIVATE ${PLATFORM_CXX_DEFS})
