/**
 * The rendering system procedures and functions can be found here
 **/

#ifndef RENDERING
#define RENDERING

#include "splashkit.h"
#include "math.h"
#include "gfx_animations.h"

/**
 * Takes an image name (usually as a literal string) and searches
 * for the image in the given bitmap array. Returns the index
 * of the image found in the array or -1 if it cannot find an image
 * @param   bitmaps     The array of bitmaps to search
 * @param   image_name  The name of the image to search for
 * @returns The index of the image found in the array or -1 if one cannot be found
 **/
int get_bitmap_index(const vector<bitmap_properties> &bitmaps, string image_name);

/**
 * Used in sequence 1 for deciding when to render a static circle behind
 * the moving one as well as controlling its opacity
 * @param   screen_intervals    Used to keep track of which section the animated circle is in
 * @param   circles             The array of circles where all circles are stored
 **/
void create_trailing_circle(const vector<double> &screen_intervals, vector<circle_properties> &circles);

/**
 * Deletes the specified bitmap from a bitmap array
 * thereby removing it from the screen
 * @param   bitmaps     The array to delete the bitmap from
 * @param   index       The index location of the bitmap in the array
 **/
void delete_bitmap(vector<bitmap_properties> &bitmaps, int index);

/**
 * Adds a circle to a circle array so that it can be rendered
 * on the screen
 * @param   circles                     The array of circles where all circles are stored
 * @param   colour                      The colour of the circle being added
 * @param   x                           The horizontal position of the circle being added
 * @param   y                           The vertical position of the circle being added
 * @param   radius                      The radius of the circle being added
 * @param   current_screen_interval     The section that the circle being added is in
 **/
void populate_circles(vector<circle_properties> &circles, color colour, double x, double y, double radius, interval current_screen_interval);

/**
 * Adds a rectangle to a rectangle array so that it can be rendered
 * on the screen
 * @param   rectangles                  The array of rectangles where all rectangles are stored
 * @param   colour                      The colour of the rectangle being added
 * @param   x                           The horizontal position of the rectangle being added
 * @param   y                           The vertical position of the rectangle being added
 * @param   width                       The width of the rectangle being added
 * @param   height                      The height of the rectangle being added
 **/
void populate_rectangles(vector<rectangle_properties> &rectangles, color colour, double x, double y, double width, double height);

/**
 * Adds a bitmap image to an array of bitmap images so that it can be rendered
 * @param   bitmaps         The array of bitmap images where all images are stored
 * @param   name_of_image   The name of the image being added
 * @param   x               The horizontal position of the image being added
 * @param   y               The vertical position of the image being added
 **/
void populate_bitmaps(vector<bitmap_properties> &bitmaps, string name_of_image, double x, double y);

/**
 * Adds a bitmap image to an array of bitmap images so that it can be rendered.
 * This instance of the function lets us specify the index location we want to
 * store the image in. The reason we may want to do this is so that we can have
 * control over the order the images are rendered in
 * @param   bitmaps         The array of bitmap images where all images are stored
 * @param   name_of_image   The name of the image being added
 * @param   x               The horizontal position of the image being added
 * @param   y               The vertical position of the image being added
 * @param   index           The index location of the array to store the image in
 **/
void populate_bitmaps(vector<bitmap_properties> &bitmaps, string name_of_image, double x, double y, int index);

/**
 * Handles the loading of all graphics used in the animation.
 * It does this by loading in the graphics needed for each sequence
 * as each sequence is executed as opposed to loading them
 * in all at once.
 * @param   circles             The array of circles where all circles are stored
 * @param   rectangles          The array of rectangles where all rectangles are stored
 * @param   bitmaps             The array of bitmap images where all images are stored
 * @param   window_intervals    Used to keep track of which section the animated circle is in
 * @param   sequence_tracker    Used to keep track of the sequences that have their graphics loaded or not
 * @param   sequence_number     The number of the sequence to load graphics in for
 * @param   gun_shot_fired      Whether or not the gun shot sound has been fired in sequence 4
 **/ 
void populate(vector<circle_properties> &circles, vector<rectangle_properties> &rectangles, vector<bitmap_properties> &bitmaps, vector<double> &window_intervals, vector<sequence_progress> &sequence_tracker, int sequence_number, bool &gun_shot_fired);

/**
 * Draws all circles from a circle array onto the screen
 * @param   circles     The array to draw circles from
 **/
void render_circles(const vector<circle_properties> &circles);

/**
 * Draws all rectangles from a rectangle array onto the screen
 * @param   rectangles     The array to draw rectangles from
 **/
void render_rectangles(const vector<rectangle_properties> &rectangles);

/**
 * Draws all bitmap images from a bitmap array onto the screen
 * @param   bitmaps     The array to draw bitmaps from
 **/
void render_bitmaps(const vector<bitmap_properties> &bitmaps);

/**
 * Draws all graphics from the specified arrays onto the screen
 * @param   circles     The array to draw circles from
 * @param   rectangles  The array to draw rectangles from
 * @param   bitmaps     The array to draw bitmaps from
 **/
void render(const vector<circle_properties> &circles, const vector<rectangle_properties> &rectangles, const vector<bitmap_properties> &bitmaps);

/**
 * The first sequence of the animation
 * @param   circles             The circle array where all circle information is stored
 * @param   window_intervals    Used to keep track of which section the animated circle is in
 * @param   sequence_tracker    Used in order to mark the completion of the first sequence
 **/
void sequence1(vector<circle_properties> &circles, vector<double> &window_intervals, vector<sequence_progress> &sequence_tracker);

/**
 * The second sequence of the animation
 * @param   rectangles          The rectangle array where all rectangle information is stored
 * @param   bitmaps             The bitmap array where all bitmap image information is stored
 * @param   sequence_tracker    Used in order to mark the completion of the second sequence
 **/
void sequence2(vector<rectangle_properties> &rectangles, vector<bitmap_properties> &bitmaps, vector<sequence_progress> &sequence_tracker);

/**
 * The third sequence of the animation
 * @param   rectangles          The rectangle array where all rectangle information is stored
 * @param   bitmaps             The bitmap array where all bitmap image information is stored
 * @param   sequence_tracker    Used in order to mark the completion of the third sequence
 **/
void sequence3(vector<rectangle_properties> &rectangles, vector<bitmap_properties> &bitmaps, vector<sequence_progress> &sequence_tracker);

/**
 * The fourth sequence of the animation
 * @param   bitmaps             The bitmap array where all bitmap image information is stored
 * @param   sequence_tracker    Used in order to mark the completion of the fourth sequence
 * @param   muzzle_flash_timer  The timer that helps determine how long the muzzle flash image should stay on screen for
 **/
void sequence4(vector<bitmap_properties> &bitmaps, vector<sequence_progress> &sequence_tracker, int &muzzle_flash_timer);

/**
 * The fifth sequence of the animation
 * @param   bitmaps             The bitmap array where all bitmap image information is stored
 * @param   sequence_tracker    Used in order to mark the completion of the fifth sequence
 **/
void sequence5(vector<bitmap_properties> &bitmaps, vector<sequence_progress> &sequence_tracker);

/**
 * Chooses which sequence to execute
 * @param   circles             The circle array where all circle information is stored
 * @param   rectangles          The rectangle array where all rectangle information is stored
 * @param   bitmaps             The bitmap array where all bitmap image information is stored
 * @param   window_intervals    Used to keep track of which section the animated circle is in during sequence 1
 * @param   muzzle_flash_timer  The timer that helps determine how long the muzzle flash image should stay on screen for during sequence 4
 * @param   gun_shot_fired      Whether or not the gun shot sound has been fired in sequence 4
 * @param   sequence_tracker    Keeps track of which sequences have been executed and which graphics for each of the sequences have been loaded
 * @param   sequence_number     The number of the sequence to execute
 **/
void sequences(vector<circle_properties> &circles, vector<rectangle_properties> &rectangles, vector<bitmap_properties> &bitmaps, vector<double> &window_intervals, int &muzzle_flash_timer, bool &gun_shot_fired, vector<sequence_progress> &sequence_tracker, int sequence_number);

#endif