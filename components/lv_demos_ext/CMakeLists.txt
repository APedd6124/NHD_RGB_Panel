file(GLOB_RECURSE DEMO_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
# Skip the high-res demo: huge assets, made for large screens
list(FILTER DEMO_SRCS EXCLUDE REGEX "/high_res/")

idf_component_register(SRCS ${DEMO_SRCS}
                       INCLUDE_DIRS "."
                       REQUIRES lvgl)

target_compile_definitions(${COMPONENT_LIB} PUBLIC LV_LVGL_H_INCLUDE_SIMPLE)
# Third-party demo code: don't fail on printf-format or deprecated-API warnings
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-format -Wno-deprecated-declarations)
