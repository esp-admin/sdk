#ifndef H_TFT
#define H_TFT

#include <SPI.h>
#include <lvgl.h>
#include <TFT_eSPI.h>

#define TFT_SCREEN_WIDTH 240
#define TFT_SCREEN_HEIGHT 240
#define TFT_TASK_STACK_SIZE 5600
#define TFT_TASK_PRIORITY 5

class TFT
{
public:
    void setup();
    void start();

private:
    lv_disp_draw_buf_t _draw_buf;
    lv_color_t _buf[TFT_SCREEN_WIDTH * TFT_SCREEN_HEIGHT / 10];
    static TFT_eSPI _tft;
    static void _flushDisplay(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
    static void _task(void *pvParameters);
};

#endif