#include "splashkit.h"

#define MIN_RADIUS 10
#define MAX_RADIUS 200

int main()
{
    double x;
    double y;
    double radius = 100;
    color circle_color = COLOR_GREEN;

    open_window("Shape Shifter by Ben", 800, 600);

    x = screen_width() / 2;
    y = screen_height() / 2;

    while (not quit_requested())
    {
        process_events();
        // Colour change key
        if (key_typed(C_KEY))
        {
            circle_color = random_color();
        }
        
        // Change radius
        if (key_typed(KEYPAD_PLUS) && radius < MAX_RADIUS)
        {
            radius += 10;
        }
        if (key_typed(KEYPAD_MINUS) && radius > MIN_RADIUS)
        {
            radius -= 10;
        }

        // Reset Circle
        if (key_typed(R_KEY))
        {
            x = screen_width() / 2;
            y = screen_height() / 2;
        }

        // Right key
        if (key_down(RIGHT_KEY) && x + radius < screen_width())
        {
            x += 3;
        }
        // Left key
        if (key_down(LEFT_KEY) && x - radius > 0)
        {
            x -= 3;
        }
        // Up Key
        if (key_down(UP_KEY) && y - radius > 0)
        {
            y -= 3;
        }
        // Down Key
        if (key_down(DOWN_KEY) && y + radius < screen_height())
        {
            y += 3;
        }

        clear_screen(COLOR_WHITE);
        fill_circle(circle_color, x, y, radius);
        refresh_screen(60);
    }

    return 0;
}