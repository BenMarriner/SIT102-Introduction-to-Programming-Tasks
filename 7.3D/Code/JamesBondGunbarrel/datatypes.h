/**
 * Here we will of the data types used for storing specific kinds of information
 * needed throughout the animation
 **/

#ifndef DATATYPES
#define DATATYPES

#include "splashkit.h"

/**
 * Choices of properties that can be animated.
 * Can be used for animating circles, rectangles and bitmaps
 **/
enum animate_property
{
    X,
    Y,
    RADIUS
};

/**
 * A pair of doubles describing which section of the window
 * the circle is in
 * @field   current_interval    The interval that is to the left of an object
 * @field   next_interval       The interval that is to the right of an object
 **/
struct interval
{
    double current_interval;
    double next_interval;
};

/**
 * A structure describing the appearance of a circle and
 * how it shall be rendered
 * @field   colour           The colour of the circle
 * @field   x                The horizontal position of the circle
 * @field   y                The vertical position of the circle
 * @field   radius           The radius of the circle
 * @field   screen_interval  The section of window the circle is location in
 **/
struct circle_properties
{
    color colour;
    double x;
    double y;
    double radius;
    interval screen_interval;
};

/**
 * A structure describing the appearance of a rectangle and
 * how it shall be rendered
 * @field   colour  The colour of the rectangle
 * @field   x       The horizontal position of the rectangle
 * @field   y       The vertical position of the rectangle
 * @field   width   The width of the rectangle
 * @field   height  The height of the rectangle
 **/
struct rectangle_properties
{
    color colour;
    double x;
    double y;
    double width;
    double height;
};

/**
 * A structure that stores information about a bitmap image
 * @field   image_name  The name of the image
 * @field   x           The horizontal position in the window
 * @field   y           The vertical position in the window
 **/
struct bitmap_properties
{
    string image_name;
    double x;
    double y;
};

/**
 * A structure that keeps track of whether or not each
 * sequence has its resources loaded and if the sequence
 * has finished being carried out.
 * @field   complete            Is the sequence finished?
 * @field   graphics_loaded     Have the graphics for this sequence been loaded into an array for drawing?
 **/
struct sequence_progress
{
    bool complete = false;
    bool graphics_loaded = false;
};

#endif