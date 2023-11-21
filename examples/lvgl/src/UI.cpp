#include <UI.h>
#include "images/logo.c"

UI::UI() : _tft() {}

void UI::setup()
{
    _tft.setup();

    // Set objects
    screen1 = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen1, lv_color_hex(COLOR_GRAY_950), _LV_STYLE_STATE_CMP_SAME);

    screen2 = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen2, lv_color_hex(COLOR_GRAY_950), _LV_STYLE_STATE_CMP_SAME);
    lv_obj_set_style_border_color(screen2, lv_color_hex(COLOR_GRAY_700), _LV_STYLE_STATE_CMP_SAME);
    lv_obj_set_style_border_width(screen2, 6, _LV_STYLE_STATE_CMP_SAME);

    image1 = lv_img_create(screen1);
    lv_obj_set_style_align(image1, LV_ALIGN_CENTER, _LV_STYLE_STATE_CMP_SAME);
    lv_img_set_src(image1, &logo);

    label1 = lv_label_create(screen2);
    lv_obj_set_style_text_color(label1, lv_color_hex(COLOR_GRAY_50), _LV_STYLE_STATE_CMP_SAME);
    lv_obj_set_style_align(label1, LV_ALIGN_CENTER, _LV_STYLE_STATE_CMP_SAME);
    lv_obj_set_style_text_font(label1, &lv_font_montserrat_42, _LV_STYLE_STATE_CMP_SAME);
    lv_label_set_text(label1, "0");

    label2 = lv_label_create(screen2);
    lv_obj_set_style_text_color(label2, lv_color_hex(COLOR_GRAY_700), _LV_STYLE_STATE_CMP_SAME);
    lv_obj_set_style_align(label2, LV_ALIGN_BOTTOM_MID, _LV_STYLE_STATE_CMP_SAME);
    lv_obj_set_style_text_font(label2, &lv_font_montserrat_20, _LV_STYLE_STATE_CMP_SAME);
    lv_obj_set_style_pad_all(label2, 5, _LV_STYLE_STATE_CMP_SAME);
    lv_label_set_text(label2, "");

    // Load screen
    lv_scr_load(screen1);

    _tft.start();
}