#include "splashkit.h"
#include "player.h"
#include "power_up.h"

/**
 * Load the game images, sounds, etc.
 */
void load_resources()
{
    load_resource_bundle("game_bundle", "lost_in_space.txt");
}

// Configure instance of a power bar
void draw_power_bar(string bar_type, string icon_type, double bar_health_percentage, double hud_location_x, double hud_location_y)
{    
    draw_bitmap("bar_empty", hud_location_x, hud_location_y, option_to_screen());
    draw_bitmap(bar_type, hud_location_x, hud_location_y, option_part_bmp(0, 0, bitmap_width(bar_type) * bar_health_percentage, bitmap_height(bar_type), option_to_screen()));
    draw_bitmap(icon_type, hud_location_x + bitmap_width(bar_type) - 20, hud_location_y - 30, option_to_screen(option_scale_bmp(0.5, 0.5)));
}

// Draw HUD
void draw_hud(player_data player)
{
    // Dashboard
    fill_rectangle(COLOR_YELLOW, 0, screen_height() - SCREEN_BOTTOM_BORDER, screen_width(), SCREEN_BOTTOM_BORDER, option_to_screen());
    // Player location
    draw_text("LOCATION: " + point_to_string(center_point(player.player_sprite)), COLOR_BLACK, (screen_width() / 2) - 135, 695, option_to_screen());
    // Score
    fill_rectangle(COLOR_WHITE, 900, screen_height() - ((SCREEN_BOTTOM_BORDER / 2) + 20), 100, 40, option_to_screen());
    draw_text("SCORE: ", COLOR_BLACK, 900, screen_height() - ((SCREEN_BOTTOM_BORDER / 2) + 5), option_to_screen());
    // Minimap
    fill_rectangle(COLOR_DARK_GREEN, (screen_width() / 2) - 55, screen_height() - 145, 110, 110, option_to_screen());
    fill_rectangle(COLOR_BLACK, (screen_width() / 2) - 50, screen_height() - 140, 100, 100, option_to_screen());
    // Fuel gauge
    draw_power_bar("bar_fuel", "fuel", player.fuel_pct, 20, 580);
    // Shield
    draw_power_bar("bar_shield", "shield", player.shield_pct, 20, 625);
    // Battery
    draw_power_bar("bar_battery", "battery", player.battery_pct, 20, 670);
}

/**
 * Entry point.
 * 
 * Manages the initialisation of data, the event loop, and quitting.
 */
int main()
{
    open_window("Lost In Space", 1280, 720);
    load_resources();

    player_data player;
    player = new_player();
    power_up_data power_up = new_power_up(256, 128);

    while ( not quit_requested() )
    {
        // Handle input to adjust player movement
        process_events();
        handle_input(player);

        // Perform movement and update the camera
        update_player(player);
        update_power_up(power_up);

        // Redraw everything
        clear_screen(COLOR_BLACK);

        // Spawn power up
        draw_power_up(power_up);

        // as well as the player who can move
        draw_player(player);

        // Redraw hud
        draw_hud(player);

        refresh_screen(60);
    }

    return 0;
}