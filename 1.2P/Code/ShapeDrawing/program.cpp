#include "splashkit.h"
void draw_house()
{
    clear_screen(COLOR_WHITE);
    fill_ellipse(COLOR_BRIGHT_GREEN, 0, 400, 800, 400);
    fill_rectangle(COLOR_GRAY, 300, 300, 200, 200);
    fill_triangle(COLOR_RED, 250, 300, 400, 150, 550, 300);
    refresh_screen();
}

void draw_face()
{
    // Clear screen for new picture
    clear_screen(COLOR_WHITE);
    
    // Head
    fill_circle(COLOR_GOLD, 400, 300, 200);
    // Eyeballs
    fill_ellipse(COLOR_WHITE, 250, 225, 100, 50);
    fill_ellipse(COLOR_WHITE, 450, 225, 100, 50);
    // Eye Colour
    fill_circle(COLOR_SKY_BLUE, 300, 250, 25);
    fill_circle(COLOR_SKY_BLUE, 500, 250, 25);
    // Mouth
    fill_rectangle(COLOR_PINK, 250, 350, 300, 50);
    
    // Update screen with new picture
    refresh_screen();
}

int main()
{
    open_window("Shapes by Ben",800,600);

    draw_house();
    delay(5000);

    draw_face();
    delay(5000);

    draw_house();
    delay(5000);

    draw_face();
    delay(5000);
}