#pragma once 
#include <stdbool.h>
#include "sdkconfig.h"
#include "esp_err.h"
#include "esp_lcd_panel_rgb.h"

#if CONFIG_PANEL_DISPLAY_1
#define LCD_PIXEL_CLOCK_HZ (23 * 1000 * 1000)
#define LCD_H_RES 800
#define LCD_V_RES 480
#define LCD_HSYNC 4
#define LCD_HBP 8
#define LCD_HFP 8
#define LCD_VSYNC 4
#define LCD_VBP 8 
#define LCD_VFP 8 
#elif CONFIG_PANEL_DISPLAY_2
#define LCD_PIXEL_CLOCK_HZ ((20 * 1000 * 1000))
#define LCD_H_RES 800
#define LCD_V_RES 480
#define LCD_HSYNC 4
#define LCD_HBP 8
#define LCD_HFP 8
#define LCD_VSYNC 4
#define LCD_VBP 16 
#define LCD_VFP 16 
#endif 

/**
 * @brief Pin definitions for timing related signals 
 */
#define PIN_NUM_PCLK 1
#define PIN_NUM_HSYNC 41
#define PIN_NUM_VSYNC 42
#define PIN_NUM_DE 2 

/**
 * @brief Pin definitions for 16-bits of RGB data
 */
#define PIN_NUM_B1 40
#define PIN_NUM_B2 39
#define PIN_NUM_B3 38 
#define PIN_NUM_B4 0
#define PIN_NUM_B5 45
#define PIN_NUM_G0 48
#define PIN_NUM_G1 47 
#define PIN_NUM_G2 21
#define PIN_NUM_G3 14
#define PIN_NUM_G4 13
#define PIN_NUM_G5 12 
#define PIN_NUM_R1 11
#define PIN_NUM_R2 10
#define PIN_NUM_R3 9 
#define PIN_NUM_R4 46
#define PIN_NUM_R5 3 

/* 16-bits of RGB data */
#define LCD_DATA_LINES 16 

esp_err_t new_nhd_rgb_panel(esp_lcd_panel_handle_t *nhd_handle);
esp_err_t nhd_rgb_panel_init(esp_lcd_panel_handle_t nhd_handle);