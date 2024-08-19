/**
 * Here are some procedures that help with the animations of the graphics
 * used in the sequences of the gun barrel animation
 **/

#include "gfx_animations.h"

/**
 * Uses the position of the animated circle and its screen intervals
 * To control the opacity of trailing circle. It does this by
 * working out how far the animated circle is from its next screen
 * interval and calculating a value between 0 and 1 from there.
 * Similar to the interpolate_between_values function-
 **/
void interpolate_opacity(vector<circle_properties> &circles)
{
    circles[1].colour.a = 1 - (circles[0].x / (circles[0].screen_interval.next_interval - circles[0].screen_interval.current_interval));
}

/**
 * The base function for animating circle properties
 **/
void animate_circle(circle_properties &circle, animate_property property, double value, const vector<double> &screen_intervals)
{
    switch (property)
    {
        case X:
        circle.x = value;
        break;
        case Y:
        circle.y = value;
        break;
        case RADIUS:
        circle.radius = value;
        break;
    }
    circle.screen_interval = get_current_screen_interval(circle, screen_intervals);
}

/**
 * The base function for animating bitmap properties
 **/
void animate_bitmap(bitmap_properties &bitmap, animate_property property, double value)
{
    switch (property)
    {
        case X:
        {
            bitmap.x = value;
        break;
        }
        case Y:
        {
            bitmap.y = value;
            break;
        }
        default:
        {
            break;
        }
    }
}

/**
 * Moves a circle in the horizontal direction
 **/
void circle_translate(circle_properties &circle, double distance, const vector<double> &screen_intervals)
{
    animate_circle(circle, X, circle.x + distance, screen_intervals);
}

/**
 * Moves a bitmap image in a specified direction
 **/
void bitmap_translate(bitmap_properties &bitmap, animate_property direction, double distance)
{
    switch (direction)
    {
        case X:
        {
            animate_bitmap(bitmap, direction, bitmap.x + distance);
            break;
        }
        case Y:
        {
            animate_bitmap(bitmap, direction, bitmap.y + distance);
            break;
        }
        default:
        {
            break;
        }
    }
}