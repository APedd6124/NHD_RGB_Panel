#include "NHD_RGB_panel.h"
#include "esp_check.h"
#include "driver/gpio.h"
#include "esp_lcd_panel_ops.h"

static const char *TAG = "example";

/**
 * @brief This function creates a new RGB panel for the Newhaven Display TFT
 * @param nhd_handle A pointer to the Newhaven Display TFT handle 
 */
esp_err_t new_nhd_rgb_panel(esp_lcd_panel_handle_t *nhd_handle) {

    ESP_RETURN_ON_FALSE(nhd_handle, ESP_ERR_INVALID_ARG, TAG, "panel handle is NULL");

    esp_lcd_rgb_panel_config_t nhd_panel_config = {
        .data_width = 16, 
        .clk_src = LCD_CLK_SRC_DEFAULT, 
        .bounce_buffer_size_px = 10 * LCD_V_RES, 
        /* placeholder for STBYB/DISP pin */
        // .disp_gpio_num = PIN_NUM_DISP 
        .pclk_gpio_num = PIN_NUM_PCLK, 
        .vsync_gpio_num = PIN_NUM_VSYNC,
        .hsync_gpio_num = PIN_NUM_HSYNC, 
        .de_gpio_num = PIN_NUM_DE, 
        .data_gpio_nums = {
            PIN_NUM_B1,
            PIN_NUM_B2, 
            PIN_NUM_B3, 
            PIN_NUM_B4, 
            PIN_NUM_B5, 
            PIN_NUM_G0, 
            PIN_NUM_G1, 
            PIN_NUM_G2,
            PIN_NUM_G3, 
            PIN_NUM_G4,
            PIN_NUM_G5, 
            PIN_NUM_R1,
            PIN_NUM_R2, 
            PIN_NUM_R3, 
            PIN_NUM_R4, 
            PIN_NUM_R5,
        },
        .timings = {
            .pclk_hz = LCD_PIXEL_CLOCK_HZ,
            .h_res = LCD_H_RES,
            .v_res = LCD_V_RES,
            .hsync_back_porch = LCD_HBP,
            .hsync_front_porch = LCD_HFP, 
            .hsync_pulse_width = LCD_HSYNC,
            .vsync_back_porch = LCD_VBP,
            .vsync_front_porch = LCD_VFP, 
            .vsync_pulse_width = LCD_VSYNC,
            .flags = {
                .pclk_active_neg = true 
            }
        },
        .flags.fb_in_psram = true, /* allocate frame buffer from PSRAM */
    };
    return esp_lcd_new_rgb_panel(&nhd_panel_config, nhd_handle);
}

/**
 * @brief This function resets and initializes the NHD RGB display 
 * @param nhd_handle The Newhaven Display TFT handle 
 */
esp_err_t nhd_rgb_panel_init(esp_lcd_panel_handle_t nhd_handle) {

   ESP_RETURN_ON_FALSE(nhd_handle, ESP_ERR_INVALID_ARG, TAG, "panel handle is NULL");
   /* reset() applies panel reset sequence, init() starts RGB output engine */
   ESP_RETURN_ON_ERROR(esp_lcd_panel_reset(nhd_handle), TAG, "RGB panel reset failed");
   ESP_RETURN_ON_ERROR(esp_lcd_panel_init(nhd_handle), TAG, "RGB pael init failed");
   /* successfully reset and initialized RGB panel */
   return ESP_OK; 
}