#include "splashkit.h"

using namespace std;

// Load all fruit images and the sound effect
void load_resources()
{
load_bitmap("Cherry", "Cherry.png");
load_bitmap("Gooseberry", "Gooseberry.png");
load_bitmap("Blueberry", "Blueberry.png");
load_bitmap("Pomegranate", "Pomegranate.png");
load_bitmap("Apricot", "Apricot.png");
load_bitmap("Raspberry", "Raspberry.png");
load_bitmap("Blackberry", "Blackberry.png");
load_bitmap("Strawberry", "Strawberry.png");
load_bitmap("Currant", "Currant.png");
load_sound_effect("Splat", "Splat-SoundBible.com-1826190667.wav"); // Recorded by Mike Koenig - http://soundbible.com/642-Splat.html
}

// Chooses a fruit to display based on the id input
bitmap fruit_bitmap(int id)
{
    switch(id)
    {
        case 0:	    
            return bitmap_named("Cherry");
		case 1:	
            return bitmap_named("Gooseberry");
		case 2:		
            return bitmap_named("Blueberry");
        case 3:
            return bitmap_named("Pomegranate");
        case 4:
            return bitmap_named("Apricot");
        case 5:
            return bitmap_named("Raspberry");
        case 6:
            return bitmap_named("Blackberry");
        case 7:
            return bitmap_named("Strawberry"); 
        case 8:
            return bitmap_named("Currant");
        default:
            return bitmap_named("Currant");
    }
}

int main()
{
    int num_fruit = rnd(0,8); // Randomly chooses a fruit id number
    int score = 0; // Score counter that starts at 0
    bitmap fruit; // Fruit image to be displayed
    double fruit_position_x, fruit_position_y; // XY coordinates of the fruit image
    
    open_window("Fruit Punch", 600, 600); // Open window
    load_resources(); // Load all resources

    fruit = fruit_bitmap(num_fruit); // Displays a random fruit image
    fruit_position_x = rnd(screen_width() - bitmap_width(fruit)); // Pick a random horizontal position in the window 
    fruit_position_y = rnd(screen_height() - bitmap_height(fruit)); // Pick a random vertical position in the window
    
    while (not quit_requested()) // Loop until the player quits the game
    {
        process_events();
        clear_screen(COLOR_WHITE); // Clear to white background
        draw_text("Score: " + to_string(score), COLOR_BLACK, 0, 0); // Display score
        draw_bitmap(fruit, fruit_position_x, fruit_position_y); // Display fruit graphic

        if (mouse_clicked(LEFT_BUTTON) and bitmap_point_collision(fruit, fruit_position_x, fruit_position_y, mouse_x(), mouse_y())) // When the player clicks on the fruit
        {
            score = score + 1; // Increment the score by 1
            play_sound_effect("Splat"); // Splat sound effect
            fruit = fruit_bitmap(rnd(0,8)); // Pick a new fruit to display
            fruit_position_x = rnd(screen_width() - bitmap_width(fruit)); // Pick a new random horizontal position
            fruit_position_y = rnd(screen_height() - bitmap_height(fruit)); // Pick a new random vertical position
        }
        refresh_screen(60); // Update screen
    }
    return 0;
}