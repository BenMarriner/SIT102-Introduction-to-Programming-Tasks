// Sources:
// National Nuclear Security Administration 1953, The BADGER explosion, occurred during Operation Upshot Knothole on 18th April 1953, retrieved 19th of March 2020
// <https://commons.wikimedia.org/wiki/File:Operation_Upshot-Knothole_-_Badger_001.jpg>
// Partners In Rhyme, Explosion 3, Partners In Rhyme, retrieved 19th of March 2020
// <https://www.freesoundeffects.com/free-track/explosion-3-466448/>
// Silver Pictures 1988, John McClane with a cigarette, retrieved 19th of March 2020
// <https://www.stormontenergy.com/blog/yippee-ki-yay/>

#include "splashkit.h"

void load_resources()
{
    load_bitmap("explosion", "xx-034.jpg");
    load_bitmap("johnmcclane", "yippee2-400x400.jpg");
    load_sound_effect("explosionsound", "Explosion+3.wav");
    load_font("textfont", "arial.ttf");
}

void render_image(string imageName, string subtitle)
{
    clear_screen(COLOR_BLACK);
    draw_bitmap(imageName, 200, 100);

    if (subtitle != "")
    {
        draw_text(subtitle, COLOR_ORANGE, "textfont", 60, 200, 500);
    }

    refresh_screen();
}

int main()
{
    load_resources();

    open_window("SceneDrawing", 800, 600);
    
    render_image("explosion", "");
    play_sound_effect("explosionsound");
    delay(3000);
    
    render_image("johnmcclane", "Yippee Ki-Yay!");
    
    delay(3000);

    return 0;
}