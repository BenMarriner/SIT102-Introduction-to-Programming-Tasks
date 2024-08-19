#include "splashkit.h"
#include "player.h"
#include "power_up.h"
#include "lost_in_space.h"

/**
 * Entry point.
 * 
 * Manages the initialisation of data, the event loop, and quitting.
 */
int main()
{
    open_window("Lost In Space", 1280, 720);
    load_resources();
    
    game_data game = new_game();

    while ( not quit_requested() )
    {   
        // Handle input to adjust player movement
        process_events();
        handle_input(game.player);

        update_game(game);
        draw_game(game);
        
        refresh_screen(60);
    }

    return 0;
}