#ifndef H_UI
#define H_UI

#include <TFT.h>

#define COLOR_BLUE_700 0x1d4ed8
#define COLOR_GREEN_700 0x15803d
#define COLOR_RED_700 0xb91c1c
#define COLOR_GRAY_950 0x030712
#define COLOR_GRAY_700 0x334155
#define COLOR_GRAY_50 0xf9fafb

class UI
{
public:
    lv_obj_t *label1;
    lv_obj_t *label2;
    lv_obj_t *image1;
    lv_obj_t *screen1;
    lv_obj_t *screen2;

    UI();
    void setup();

private:
    TFT _tft;
};

#endif