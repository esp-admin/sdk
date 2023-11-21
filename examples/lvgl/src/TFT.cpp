#include <TFT.h>

TFT_eSPI TFT::_tft(TFT_SCREEN_WIDTH, TFT_SCREEN_HEIGHT);

void TFT::setup()
{
    lv_init();

    _tft.begin();

    lv_disp_draw_buf_init(&_draw_buf, _buf, NULL, TFT_SCREEN_WIDTH * TFT_SCREEN_HEIGHT / 10);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = TFT_SCREEN_WIDTH;
    disp_drv.ver_res = TFT_SCREEN_HEIGHT;
    disp_drv.flush_cb = _flushDisplay;
    disp_drv.draw_buf = &_draw_buf;
    lv_disp_drv_register(&disp_drv);
}

void TFT::start()
{
    xTaskCreate(_task, "tft_task", TFT_TASK_STACK_SIZE, nullptr, TFT_TASK_PRIORITY, nullptr);
}

void TFT::_flushDisplay(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    _tft.startWrite();
    _tft.setAddrWindow(area->x1, area->y1, w, h);
    _tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    _tft.endWrite();

    lv_disp_flush_ready(disp);
}

void TFT::_task(void *pvParameters)
{
    for (;;)
    {
        lv_timer_handler();
        delay(5);
    }
}
