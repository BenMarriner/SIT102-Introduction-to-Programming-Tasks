/**
 * The rendering system procedures and functions can be found here
 **/

#include "rendering.h"
#include "string"

using namespace std;

/**
 * Takes an image name (usually as a literal string) and searches
 * for the image in the given bitmap array. Returns the index
 * of the image found in the array or -1 if it cannot find an image
 **/
int get_bitmap_index(const vector<bitmap_properties> &bitmaps, string image_name)
{
    for (int i = 0; i < bitmaps.size(); i++)
    {
        if (bitmaps[i].image_name == image_name)
        {
            return i;
        }
    }
    return -1;
}

/**
 * Used in sequence 1 for deciding when to render a static circle behind
 * the moving one as well as controlling its opacity
 **/
void create_trailing_circle(const vector<double> &screen_intervals, vector<circle_properties> &circles)
{
    if (circles[0].screen_interval.current_interval != screen_intervals[0])
    {
        if (circles.size() == 1) // If a trailing circle does not already exist
        {
            // Add a trailing circle
            populate_circles(circles, {1,1,1,1}, circles[0].screen_interval.current_interval, screen_height() / 2, 50, circles[0].screen_interval);
        }
        
        animate_circle(circles[1], X, circles[0].screen_interval.current_interval, screen_intervals);
        interpolate_opacity(circles);
    }
}

/**
 * Deletes the specified bitmap from a bitmap array
 * thereby removing it from the screen
 **/
void delete_bitmap(vector<bitmap_properties> &bitmaps, int index)
{
    if (index >= 0 && index < bitmaps.size())
    {
        if (bitmaps.size() == 1)
        {
            bitmaps.pop_back();
        }
        else if (bitmaps.size() == 0)
        {
            return;
        }
        else
        {
            bitmap_properties bitmap = bitmaps[index];

            for (int i = index; i < bitmaps.size() - 1; i++)
            {
                bitmaps[i] = bitmaps[i + 1];
                bitmaps[i + 1] = bitmap;
            }
            bitmaps.pop_back();
        }
    }
}

/**
 * Adds a circle to the circle array so that it can be rendered
 * on the screen
 **/
void populate_circles(vector<circle_properties> &circles, color colour, double x, double y, double radius, interval current_screen_interval)
{
    circles.push_back({colour, x, y, radius, current_screen_interval});
}

/**
 * Adds a rectangle to a rectangle array so that it can be rendered
 * on the screen
 **/
void populate_rectangles(vector<rectangle_properties> &rectangles, color colour, double x, double y, double width, double height)
{
    rectangles.push_back({colour, x, y, width, height});
}

/**
 * Adds a bitmap image to an array of bitmap images so that it can be rendered
 **/
void populate_bitmaps(vector<bitmap_properties> &bitmaps, string name_of_image, double x, double y)
{
    bitmaps.push_back({name_of_image, x, y});
}

/**
 * Adds a bitmap image to an array of bitmap images so that it can be rendered.
 * This instance of the function lets us specify the index location we want to
 * store the image in. The reason we may want to do this is so that we can have
 * control over the order the images are rendered in
 **/
void populate_bitmaps(vector<bitmap_properties> &bitmaps, string name_of_image, double x, double y, int index)
{
    populate_bitmaps(bitmaps, name_of_image, x, y);
    for (int i = bitmaps.size() - 1; i > index; i--)
    {
        bitmaps[i] = bitmaps[i - 1];
        bitmaps[i - 1] = {name_of_image, x, y};        
    }
}

/**
 * Handles the loading of all graphics used in the animation.
 * It does this by loading in the graphics needed for each sequence
 * as each sequence is executed as opposed to loading them
 * in all at once.
 **/
void populate(vector<circle_properties> &circles, vector<rectangle_properties> &rectangles, vector<bitmap_properties> &bitmaps, vector<double> &window_intervals, vector<sequence_progress> &sequence_tracker, int sequence_number, bool &gun_shot_fired)
{
    switch (sequence_number)
    {
        // Sequence 1 graphics
        case 0:
        {
            if (sequence_tracker[0].graphics_loaded == false)
            {
                populate_circles(circles, COLOR_WHITE, 0, screen_height() / 2, 50, {window_intervals[0], window_intervals[1]});
                sequence_tracker[0].graphics_loaded = true;
            }
            break;
        }
        // Sequence 2 graphics
        case 1:
        {
            if (sequence_tracker[1].graphics_loaded == false)
            {
                populate_bitmaps(bitmaps, "Gunbarrel", screen_width(), 0);
                populate_rectangles(rectangles, COLOR_WHITE, bitmaps[get_bitmap_index(bitmaps, "Gunbarrel")].x, bitmaps[get_bitmap_index(bitmaps, "Gunbarrel")].y, 600, 600);
                sequence_tracker[1].graphics_loaded = true;
            }
            break;
        }
        // Sequence 3 graphics
        case 2:
        {
            if (sequence_tracker[2].graphics_loaded == false)
            {
                populate_bitmaps(bitmaps, "Daniel Craig", (screen_width() - bitmap_width("Daniel Craig")) / 2, (screen_height() - bitmap_height("Daniel Craig")) / 2);
                sequence_tracker[2].graphics_loaded = true;
            }
            break;
        }
        // Sequence 4 graphics
        case 3:
        {
            if (sequence_tracker[3].graphics_loaded == false)
            {
                populate_bitmaps(bitmaps, "MuzzleFlash", bitmaps[get_bitmap_index(bitmaps, "Daniel Craig")].x + (97 - (bitmap_width("MuzzleFlash") / 2)), bitmaps[get_bitmap_index(bitmaps, "Daniel Craig")].y + (97 - (bitmap_height("MuzzleFlash") / 2)), 1);
                if (gun_shot_fired == false)
                {
                    play_sound_effect("Gunshot");
                    gun_shot_fired = true;
                }
                sequence_tracker[3].graphics_loaded = true;
            }
            break;            
        }
        // Sequence 5 graphics
        case 4:
        {
            if (sequence_tracker[4].graphics_loaded == false)
            {
                populate_bitmaps(bitmaps, "BloodDrip", 0, -bitmap_height("BloodDrip"), 0);
                sequence_tracker[4].graphics_loaded = true;
            }
            break;
        }
    }
}

/**
 * Draws all circles from a circle array onto the screen
 **/
void render_circles(const vector<circle_properties> &circles)
{
    for (int i = 0; i < circles.size(); i++)
    {
        fill_circle
        (
            circles[i].colour,
            circles[i].x,
            circles[i].y,
            circles[i].radius
        );
    }
}

/**
 * Draws all rectangles from a rectangle array onto the screen
 **/
void render_rectangles(const vector<rectangle_properties> &rectangles)
{
    for (int i = 0; i < rectangles.size(); i++)
    {
        fill_rectangle
        (
            rectangles[i].colour,
            rectangles[i].x,
            rectangles[i].y,
            rectangles[i].width,
            rectangles[i].height
        );
    }
}

/**
 * Draws all bitmap images from a bitmap array onto the screen
 **/
void render_bitmaps(const vector<bitmap_properties> &bitmaps)
{
    for (int i = bitmaps.size() - 1; i >= 0; i--)
    {
        draw_bitmap(bitmaps[i].image_name, bitmaps[i].x, bitmaps[i].y);
    }
}

/**
 * Draws all graphics from the specified arrays onto the screen
 **/
void render(const vector<circle_properties> &circles, const vector<rectangle_properties> &rectangles, const vector<bitmap_properties> &bitmaps)
{
    render_rectangles(rectangles);
    render_bitmaps(bitmaps);
    render_circles(circles);
}

/**
 * The first sequence of the animation
 **/
void sequence1(vector<circle_properties> &circles, vector<double> &window_intervals, vector<sequence_progress> &sequence_tracker)
{   
    if (circles[0].x < screen_width() + circles[0].radius)
    {
        circle_translate(circles[0], 6, window_intervals);
        create_trailing_circle(window_intervals, circles);
    }
    else
    {
        // This sequence has finished
        sequence_tracker[0].complete = true;
    }
}

/**
 * The second sequence of the animation
 **/
void sequence2(vector<rectangle_properties> &rectangles, vector<bitmap_properties> &bitmaps, vector<sequence_progress> &sequence_tracker)
{
    if (bitmaps[get_bitmap_index(bitmaps, "Gunbarrel")].x > screen_width() / 2 - 100)
    {
        bitmap_translate(bitmaps[get_bitmap_index(bitmaps, "Gunbarrel")], X, -5);
        rectangles[0].x = bitmaps[get_bitmap_index(bitmaps, "Gunbarrel")].x + 300;
        rectangles[0].y = bitmaps[get_bitmap_index(bitmaps, "Gunbarrel")].y;
    }
    else
    {
        // This sequence has finished
        sequence_tracker[1].complete = true;
    }
}

/**
 * The third sequence of the animation
 **/
void sequence3(vector<rectangle_properties> &rectangles, vector<bitmap_properties> &bitmaps, vector<sequence_progress> &sequence_tracker)
{
    if (bitmaps[get_bitmap_index(bitmaps, "Gunbarrel")].x > 0)
    {
        bitmap_translate(bitmaps[get_bitmap_index(bitmaps, "Gunbarrel")], X, -5);
        rectangles[0].x = bitmaps[get_bitmap_index(bitmaps, "Gunbarrel")].x + 300;
        rectangles[0].y = bitmaps[get_bitmap_index(bitmaps, "Gunbarrel")].y;
    }
    else
    {
        // This sequence has finished
        sequence_tracker[2].complete = true;
    }
}

/**
 * The fourth sequence of the animation
 **/
void sequence4(vector<bitmap_properties> &bitmaps, vector<sequence_progress> &sequence_tracker, int &muzzle_flash_timer)
{
    if (muzzle_flash_timer == 5)
    {
        delete_bitmap(bitmaps, get_bitmap_index(bitmaps, "MuzzleFlash"));
        muzzle_flash_timer += 1;
    }
    else if (muzzle_flash_timer < 5)
    {
        muzzle_flash_timer += 1;
    }
    else
    {
        sequence_tracker[3].complete = true;
    }
}

/**
 * The fifth sequence of the animation
 **/
void sequence5(vector<bitmap_properties> &bitmaps, vector<sequence_progress> &sequence_tracker)
{
    if (bitmaps[get_bitmap_index(bitmaps, "BloodDrip")].y < 0)
    {
        bitmap_translate(bitmaps[get_bitmap_index(bitmaps, "BloodDrip")], Y, 5);
    }
    else
    {
        sequence_tracker[4].complete = true;
    } 
}

/**
 * Chooses which sequence to execute
 **/
void sequences(vector<circle_properties> &circles, vector<rectangle_properties> &rectangles, vector<bitmap_properties> &bitmaps, vector<double> &window_intervals, int &muzzle_flash_timer, bool &gun_shot_fired, vector<sequence_progress> &sequence_tracker, int sequence_number)
{
    populate(circles, rectangles, bitmaps, window_intervals, sequence_tracker, sequence_number, gun_shot_fired);
    switch (sequence_number)
    {
        case 0:
        {
            sequence1(circles, window_intervals, sequence_tracker);
            break;
        }
        case 1:
        {
            sequence2(rectangles, bitmaps, sequence_tracker);
            break;
        }
        case 2:
        {
            sequence3(rectangles, bitmaps, sequence_tracker);
            break;
        }
        case 3:
        {
            sequence4(bitmaps, sequence_tracker, muzzle_flash_timer);
            break;
        }
        case 4:
        {
            sequence5(bitmaps, sequence_tracker);
            break;
        }
        default:
        {
            break;
        }
    }
}
