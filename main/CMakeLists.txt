idf_component_register(SRCS "NHD_RGB_panel.c" "NHD_RGB.c" "lvgl_demo_ui.c"
                       INCLUDE_DIRS "."
                       REQUIRES esp_lcd esp_driver_gpio esp_timer lvgl lv_demos_ext)