/**
 * Here are some procedures that help with the animations of the graphics
 * used in the sequences of the gun barrel animation
 **/

#ifndef GFX_ANIMATIONS
#define GFX_ANIMATIONS

#include "rendering.h"

/**
 * Uses the position of the animated circle and its screen intervals
 * To control the opacity of trailing circle. It does this by
 * working out how far the animated circle is from its next screen
 * interval and calculating a value between 0 and 1 from there.
 * Similar to the interpolate_between_values function
 * @param   circles     The array of circles being accessed
 **/
void interpolate_opacity(vector<circle_properties> &circles);

/**
 * The base function for animating circle properties
 * @param   circle              The circle to be animated
 * @param   property            The property of the circle that is to be animated
 * @param   value               The value to set the property to
 * @param   screen_intervals    Used in determining the section that the animated circle is in. This is bound to change as the circle is moving across the screen
 **/
void animate_circle(circle_properties &circle, animate_property property, double value, const vector<double> &screen_intervals);

/**
 * The base function for animating bitmap properties
 * @param   bitmap      The bitmap to be animated
 * @param   property    The property of the bitmap that is to be animated
 * @param   value       The value to set the property to
**/
void animate_bitmap(circle_properties &bitmap, animate_property property, double value);

/**
 * Moves a circle in the horizontal direction
 * @param   circle              The circle to be moved
 * @param   distance            Distance to move the circle across
 * @param   screen_intervals    Used in determining the section that the animated circle is in. This is bound to change as the circle is moving across the screen
 **/
void circle_translate(circle_properties &circle, double distance, const vector<double> &screen_intervals);

/**
 * Moves a bitmap image in a specified direction
 * @param   bitmap      The image to be moved
 * @param   direction   The direction to move the image in
 * @param   distance    The distance to move the image
 **/
void bitmap_translate(bitmap_properties &bitmap, animate_property direction, double distance);

#endif