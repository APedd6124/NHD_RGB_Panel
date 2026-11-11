idf_component_register(SRCS "NHD_RGB_panel.c" "NHD_RGB.c" "lvgl_demo_ui.c"
                REQUIRES esp_lcd esp_driver_gpio
                    INCLUDE_DIRS ".")
