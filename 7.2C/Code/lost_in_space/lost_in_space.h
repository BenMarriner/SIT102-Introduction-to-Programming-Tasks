#ifndef LOST_IN_SPACE
#define LOST_IN_SPACE

#include "splashkit.h"
#include "player.h"
#include "power_up.h"
#include <vector>

using std::vector;

struct game_data
{
    player_data player;
    vector<power_up_data> power_ups;
    // Game Timer here
};

/**
 * Load the game images, sounds, etc.
 */
void load_resources();

/**
 * Defines new game information
 * @returns game data for new games
 */
game_data new_game();

/**
 * Updates elements of the game before it is drawn
 */
void update_game(game_data &game);

/**
 * Draws the game onto the screen
 */
void draw_game(const game_data &game);

/**
 * Works out the correct value to add to a resource bar
 * in order to prevent it from going past its max value
 */
double clamp_value(double value, double current_value, double max_value);

/**
 * Applies collected power up to player
 */
void apply_power_up(game_data &game, power_up_type type);

/**
 * Removes a power up from the power up array and also the world
 */
void remove_power_up(game_data &game, int index);

/** Checks if player has collided with any power ups
 * 
 */
void check_collisions(game_data &game);

/** 
 * Draws the HUD onto the screen
 * @param   game    The instance of the game. Used to access player and power up data
 */
void draw_hud(const game_data &game);

#endif