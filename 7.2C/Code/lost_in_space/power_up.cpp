#include "power_up.h"

// Sets the sprite of a power_up based on its type value
bitmap set_power_up_sprite(power_up_type power_up_type)
{
    switch (power_up_type)
    {
        case FUEL:
            return bitmap_named("fuel");
        case SHIELD:
            return bitmap_named("shield");
        case STAR:
            return bitmap_named("star");
        case COIN:
            return bitmap_named("coin");
        case BATTERY:
            return bitmap_named("battery");
        case DIAMOND:
            return bitmap_named("diamond");
        default:
            return bitmap_named("fuel");
    }
}

// Sets the mini map colour of the power up based on its type value
color set_power_up_mini_map_colour(power_up_type power_up_type)
{
    switch (power_up_type)
    {
        case FUEL:
            return {COLOR_DARK_RED.r, COLOR_DARK_RED.g, COLOR_DARK_RED.b, 1};
        case SHIELD:
            return {COLOR_PURPLE.r, COLOR_PURPLE.g, COLOR_PURPLE.b, 1};
        case STAR:
            return {COLOR_GOLD.r, COLOR_GOLD.g, COLOR_GOLD.b, 1};
        case COIN:
            return {COLOR_GOLD.r, COLOR_GOLD.g, COLOR_GOLD.b, 1};
        case BATTERY:
            return {COLOR_GREEN.r, COLOR_GREEN.g, COLOR_GREEN.b, 1};
        case DIAMOND:
            return {COLOR_BLUE.r, COLOR_BLUE.g, COLOR_BLUE.b, 1};
        default:
            return COLOR_BLACK;
    }
}

// Initialises a random new power up and places it in the world
power_up_data new_power_up(double x, double y)
{
    power_up_data result;
    result.type = static_cast<power_up_type>(rnd(6));
    result.power_up_sprite = create_sprite(set_power_up_sprite(result.type));
    result.mini_map_colour = set_power_up_mini_map_colour(result.type);
    sprite_set_x(result.power_up_sprite, x);
    sprite_set_y(result.power_up_sprite, y);
    sprite_set_dx(result.power_up_sprite, rnd() * 4 - 2);
    sprite_set_dy(result.power_up_sprite, rnd() * 4 - 2);
    return result;
}

// Adds a power up to the power up array
void add_power_up(vector<power_up_data> &power_ups)
{
    power_ups.push_back(new_power_up(rnd(POWER_UP_SPAWN_LOCATION_MIN, POWER_UP_SPAWN_LOCATION_MAX), rnd(POWER_UP_SPAWN_LOCATION_MIN, POWER_UP_SPAWN_LOCATION_MAX)));
}

// Updates the position of the power up in the world so that it moves
void update_power_ups(vector<power_up_data> &power_ups)
{
    // Update existing power ups
    for (int i = 0; i < power_ups.size(); i++)
    {
        update_sprite(power_ups[i].power_up_sprite);
    }
    // Randomly spawn new power ups
    if (rnd() < 0.05)
    {
        add_power_up(power_ups);
    }
}

// Draws the sprite of the power up onto the screen
void draw_power_ups(const vector<power_up_data> &power_ups)
{
    for (int i = 0; i < power_ups.size(); i++)
    {
        draw_sprite(power_ups[i].power_up_sprite);
    }
}

point_2d mini_map_coordinate(const power_up_data &power_up)
{
    // (sprite_location - power_up_spawn_location_min) / (total width or height) * 100 + mini_map_location
    double mini_map_x = ((sprite_x(power_up.power_up_sprite) - POWER_UP_SPAWN_LOCATION_MIN) / (abs(POWER_UP_SPAWN_LOCATION_MIN) + POWER_UP_SPAWN_LOCATION_MAX) * 100 + (screen_width() / 2) - 50);
    double mini_map_y = ((sprite_y(power_up.power_up_sprite) - POWER_UP_SPAWN_LOCATION_MIN) / (abs(POWER_UP_SPAWN_LOCATION_MIN) + POWER_UP_SPAWN_LOCATION_MAX) * 100 + (screen_height() - 140));
    return point_at(mini_map_x, mini_map_y);
}

// Draw the minimap
void draw_mini_map(const vector<power_up_data> &power_ups)
{
    for (int i = 0; i < power_ups.size(); i++)
    {
        // Only draw power ups on the mini map that are within the world bounds. This is to prevent the power up dots on the mini map from floating off of it.
        // If either sprite coordinate is outside the world bounds
        if ((sprite_x(power_ups[i].power_up_sprite) >= POWER_UP_SPAWN_LOCATION_MIN && sprite_x(power_ups[i].power_up_sprite) <= POWER_UP_SPAWN_LOCATION_MAX) && (sprite_y(power_ups[i].power_up_sprite) >= POWER_UP_SPAWN_LOCATION_MIN && sprite_y(power_ups[i].power_up_sprite) <= POWER_UP_SPAWN_LOCATION_MAX))
            draw_pixel(power_ups[i].mini_map_colour, mini_map_coordinate(power_ups[i]), option_to_screen());
    }
}