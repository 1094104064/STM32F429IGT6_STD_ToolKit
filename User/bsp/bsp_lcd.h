/**
  ******************************************************************************
  *
  * @file    template.h
  * @author  GarMing
  * @brief   Header file of template module.
  *
  ******************************************************************************
  **/
  
#ifndef _TEMPLATE_H
#define _TEMPLATE_H


#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/** 
* @brief   structure
*/ 
typedef struct _lcd_disp_info_t {
    uint16_t hor_res;
    uint16_t ver_res;
    uint32_t draw_color;
}lcd_disp_info_t;

/** 
* @brief   ltdc interface object
*/ 
typedef struct _lcd_ltdc_interface_t {
    int8_t (* init)(void);
    int8_t (* deinit)(void);
}lcd_ltdc_interface_t;

/** 
* @brief   
*/ 
typedef struct _lcd_sdram_interface_t {
    int8_t (* init)(void);
    int8_t (* deinit)(void);
}lcd_sdram_interface_t;

/** 
* @brief   delay interface object
*/ 
typedef struct _lcd_delay_interface_t {
    void (* delay_init)(void);
    void (* delay_ms)(uint32_t ms);
    void (* delay_us)(uint32_t us);
}lcd_delay_interface_t;

/** 
* @brief   backlight interface object
*/ 
typedef struct _lcd_backlight_interface_t {
    int8_t (* init)(void);
    int8_t (* deinit)(void);
    int8_t (* on)(void);
    int8_t (* off)(void);
    int8_t (* set_bright)(uint32_t val);
}lcd_backlight_interface_t;


/** 
* @brief   lcd object
*/ 
typedef struct _bsp_lcd_t {
    lcd_disp_info_t                  disp_info;
    lcd_ltdc_interface_t             ltdc_interface;
    lcd_sdram_interface_t            sdram_interface;
    lcd_backlight_interface_t        backlight_interface;
    lcd_delay_interface_t            delay_interface;

    int8_t      (* draw_pixel)       (uint16_t x, uint16_t y, uint32_t color);
    int8_t      (* fill_rect)        (uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color);
    int8_t      (* draw_line)        (struct _bsp_lcd_t * self, uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey);
    int8_t      (* draw_rect)        (struct _bsp_lcd_t * self, uint16_t x, uint16_t y, uint16_t width, uint16_t height);
    int8_t      (* draw_circle)      (struct _bsp_lcd_t * self, uint16_t x, uint16_t y, uint16_t r);
    int8_t      (* draw_ellipse)     (struct _bsp_lcd_t * self, int32_t x, int32_t y, int32_t r1, int32_t r2);

    uint32_t    (* get_pixel_color)  (uint16_t x, uint16_t y);

}bsp_lcd_t;

/**********************
*  GLOBAL PROTOTYPES
 **********************/
int8_t bsp_lcd_init( bsp_lcd_t * self, 

                     int8_t (* pf_sdram_init)(void),
                     int8_t (* pf_sdram_deinit)(void),
                     
                     int8_t (* pf_ltdc_init)(void),
                     int8_t (* pf_ltdc_deinit)(void),
                     
                     int8_t (* pf_backlight_init)(void),
                     int8_t (* pf_backlight_deinit)(void),
                     int8_t (* pf_backlight_on)(void),
                     int8_t (* pf_backlight_off)(void),
                     int8_t (* pf_backlight_set_bright)(uint32_t val),
                     
                     void (* pf_delay_init)(void),
                     void (* pf_delay_ms)(uint32_t ms),
                     void (* pf_delay_us)(uint32_t us),
                     
                     int8_t (* pf_draw_pixel)(uint16_t x, uint16_t y, uint32_t color),
                     int8_t (* pf_fill_rect)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color) );
/**********************
 *      MACROS
 **********************/



#ifdef __cplusplus
}
#endif

#endif /*_TEMPLATE_H*/


/******************************* (END OF FILE) *********************************/
