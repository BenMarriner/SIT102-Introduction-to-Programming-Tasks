#include "player.h"

#ifndef LOST_IN_SPACE_POWER_UP
#define LOST_IN_SPACE_POWER_UP

/**
 * The different power ups that can be collected
 */
enum power_up_type
{
    FUEL,
    SHIELD,
    STAR,
    COIN,
    BATTERY,
    DIAMOND
};

/**
 * Stores the type as well as the power up's sprite
 * @field   type                The type of power up
 * @field   power_up_sprite     The power up's sprite
 */
struct power_up_data
{
    power_up_type type;
    sprite power_up_sprite;
};

/**
 * Sets the sprite of a power_up based on its type value
 * @param   power_up_type   The given type of power up
 * @returns A bitmap of the sprite used for the given type
 */
bitmap set_power_up_sprite(power_up_type power_up_type);

/**
 * Initialises a random new power up and places it in the world
 * @param   x   The x-coordinate of where the power-up is placed
 * @param   y   The y-coordinate of where the power-up is placed
 * @returns The power up consisting of its data values
 */
power_up_data new_power_up(double x, double y);

/**
 * Draws the sprite of the power up onto the screen
 * @param   power_up   The power up to draw
 */
void draw_power_up(const power_up_data &power_up);

/**
 * Updates the position of the power up in the world so that it moves
 * @param   power_up    The power up to update/move
 */
void update_power_up(power_up_data &power_up);

#endif