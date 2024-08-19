#include "splashkit.h"

int main()
{
    open_window("Transparency Test", 1280, 720);
    bitmap black_box = load_bitmap("BlackBox", "BlackBox.png");
    bitmap rose = load_bitmap("Rose", "Rainbow-Rose.jpg");

    while (not quit_requested())
    {
        process_events();

        clear_screen(COLOR_RED);
        draw_bitmap(black_box, (screen_width() - bitmap_width(black_box)) / 2, (screen_height() - bitmap_height(black_box)) / 2);
        // draw_bitmap(rose, 0, 0, option_scale_bmp(0.75, 0.75));
        draw_bitmap(rose, 125, 125);
        fill_circle_on_bitmap(black_box, COLOR_TRANSPARENT, bitmap_width(black_box) / 2, bitmap_height(black_box) / 2, 50);

        refresh_screen();
    }
    return 0;
}