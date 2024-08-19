#include "splashkit.h"
#include "datatypes.h"
#include "math.h"
#include "rendering.h"
#include "gfx_animations.h"
#include "string"

using namespace std;

#define NUM_OF_SEQUENCES 5 // Used to control the number of sequences to keep track of in the sequence_tracker array

/**
 * Loads all of the images required for the animation so that they can loaded into the bitmap array.
 * A sound effect is also loaded but this will only be played once and does not belong in any arrays
 **/
void load_resources()
{
    load_bitmap("Gunbarrel", "Gunbarrel.png");
    load_bitmap("Daniel Craig", "Bond.png");
    load_bitmap("MuzzleFlash", "Muzzle_Flash.png");
    load_bitmap("BloodDrip", "BloodDrip.png");
    load_sound_effect("Gunshot", "Gunshot.wav");
}

// Begin program
int main()
{   
    bool paused = false; // Animation will start unpaused
    vector<sequence_progress> sequence_tracker; // This will keep track of the animation's progress as well as which graphics have been loaded into the bitmap array
    for (int i = 0; i < NUM_OF_SEQUENCES; i++)
    {
        sequence_tracker.push_back({false, false});
    }

    vector<circle_properties> circles; // The array in which circles will be stored
    vector<rectangle_properties> rectangles; // The array in which rectangles will be stored
    vector<bitmap_properties> bitmaps; // The array in which bitmap images will be stored
    vector<double> window_intervals; // The array of doubles that stores all the intervals of the window

    int muzzle_flash_time = 0; // Helps keep track of how long the muzzle flash image has been on screen for
    bool gun_shot_fired = false; // Whether or not the gun shot sound has been fired. This sound effect only needs to play once
    
    open_window("Gunbarrel", 1280, 720);
    load_resources();
    window_intervals = screen_intervals(); // Calculate window intervals

    do
    {
        process_events();
        
        // Toggle paused state with ESCAPE button
        if (key_typed(ESCAPE_KEY))
        {
            paused = not paused;
        }
        
        // Only execute animation when not paused
        if (not paused)
        {
            clear_screen(COLOR_BLACK);

            /** Check through the sequence_tracker array for the first false value
             * The program will then execute the sequence that corresponds to the index of that value
             * Using the sequences procedure
             **/ 
            for (int i = 0; i < sequence_tracker.size(); i++)
            {
                if (sequence_tracker[i].complete == false)
                {
                    sequences(circles, rectangles, bitmaps, window_intervals, muzzle_flash_time, gun_shot_fired, sequence_tracker, i);
                    break;
                }
            }
            // Render all graphics and shapes onto the screen
            render(circles, rectangles, bitmaps);

            refresh_screen(60);
        }

    } while (not quit_requested());
    
    return 0;
}