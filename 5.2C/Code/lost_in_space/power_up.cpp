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

// Initialises a random new power up and places it in the world
power_up_data new_power_up(double x, double y)
{
    power_up_data result;
    result.type = static_cast<power_up_type>(rnd(6));
    result.power_up_sprite = create_sprite(set_power_up_sprite(result.type));
    sprite_set_dx(result.power_up_sprite, rnd() * 4 - 2);
    sprite_set_dy(result.power_up_sprite, rnd() * 4 - 2);
    return result;
}

// Draws the sprite of the power up onto the screen
void draw_power_up(const power_up_data &power_up)
{
    draw_sprite(power_up.power_up_sprite);
}


// Updates the position of the power up in the world so that it moves
void update_power_up(power_up_data &power_up)
{
    update_sprite(power_up.power_up_sprite);
}