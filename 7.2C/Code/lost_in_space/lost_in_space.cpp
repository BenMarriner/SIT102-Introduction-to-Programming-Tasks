#include "lost_in_space.h"

void load_resources()
{
    load_resource_bundle("game_bundle", "lost_in_space.txt");
}

game_data new_game()
{
    game_data game;
    // New player
    game.player = new_player();
    
    return game;
}

void update_game(game_data &game)
{
    // Perform movement and update the camera
    update_player(game.player);
    update_power_ups(game.power_ups);
    check_collisions(game);
}

void draw_game(const game_data &game)
{
    // Redraw everything
    clear_screen(COLOR_BLACK);

    // Draw player
    draw_player(game.player);

    // Draw power ups
    draw_power_ups(game.power_ups);

    // Draw hud
    draw_hud(game);
}

// Works out the correct value to add to a resource bar
// in order to prevent it from going past its max value
double clamp_value(double value, double current_value, double max_value)
{
    if ((max_value - current_value) < value)
    {
        return max_value - current_value;
    }
    else
    {
        return value;
    }
}

// Applies collected power up to player
void apply_power_up(game_data &game, power_up_type type)
{
    switch (type)
    {
        case FUEL:
            game.player.fuel_pct += clamp_value(0.25, game.player.fuel_pct, 1);
            play_sound_effect("fuel_sound");
            break;
        case SHIELD:
            game.player.shield_pct += clamp_value(0.25, game.player.shield_pct, 1);
            play_sound_effect("shield_sound");
            break;
        case BATTERY:
            game.player.battery_pct += clamp_value(0.25, game.player.battery_pct, 1);
            play_sound_effect("battery_sound");
            break;
        case STAR:
            game.player.score += 5;
            play_sound_effect("coin_sound");
            break;
        case COIN:
            game.player.score += 1;
            play_sound_effect("coin_sound");
            break;
        case DIAMOND:
            game.player.score += 10;
            play_sound_effect("coin_sound");
            break;
    }
}

// Removes a power up from the power up array and also the world
void remove_power_up(game_data &game, int index)
{
    int last_idx = game.power_ups.size() - 1;
    game.power_ups[index] = game.power_ups[last_idx];
    game.power_ups.pop_back();
}

// Checks if player has collided with any power ups
void check_collisions(game_data &game)
{
    for (int i = game.power_ups.size() - 1; i < game.power_ups.size(); i--)
    {
        if (sprite_collision(game.player.player_sprite, game.power_ups[i].power_up_sprite))
        {
            // Apply power up
            apply_power_up(game, game.power_ups[i].type);
            // Remove power up from world
            remove_power_up(game, i);
        }
    }
}

// Draws the HUD onto the screen
void draw_hud(const game_data &game)
{
    // Dashboard
    fill_rectangle(COLOR_YELLOW, 0, screen_height() - SCREEN_BOTTOM_BORDER, screen_width(), SCREEN_BOTTOM_BORDER, option_to_screen());
    // Player location
    draw_text("LOCATION: " + point_to_string(center_point(game.player.player_sprite)), COLOR_BLACK, (screen_width() / 2) - 135, 695, option_to_screen());
    // Score
    fill_rectangle(COLOR_WHITE, 900, screen_height() - ((SCREEN_BOTTOM_BORDER / 2) + 20), 100, 40, option_to_screen());
    draw_text("SCORE: " + to_string(game.player.score), COLOR_BLACK, 900, screen_height() - ((SCREEN_BOTTOM_BORDER / 2) + 5), option_to_screen());
    // Minimap
    fill_rectangle(COLOR_DARK_GREEN, (screen_width() / 2) - 55, screen_height() - 145, 110, 110, option_to_screen());
    fill_rectangle(COLOR_BLACK, (screen_width() / 2) - 50, screen_height() - 140, 100, 100, option_to_screen());
    draw_mini_map(game.power_ups);
    // Fuel gauge
    draw_power_bar("bar_fuel", "fuel", game.player.fuel_pct, 20, 580);
    // Shield
    draw_power_bar("bar_shield", "shield", game.player.shield_pct, 20, 625);
    // Battery
    draw_power_bar("bar_battery", "battery", game.player.battery_pct, 20, 670);
}