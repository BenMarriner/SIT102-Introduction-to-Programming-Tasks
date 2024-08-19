/**
 * Here is just some math functions that are needed throughout various parts
 * of the program such as the animations for the shapes and the rendering
 * system
 **/

#ifndef MATH
#define MATH

#include "datatypes.h"

/**
 * Divides the width of the window into sixths
 * and stores each sixth's horizontal position 
 * in pixels in an array of doubles
 * @returns array of horizontal positions
 **/
vector<double> screen_intervals();

/**
 * Get the current section of the window a circle is in
 * @param   circle              The circle in question
 * @param   screen_intervals    The array of doubles that contains the horizontal positions of the intervals
 * @returns The interval to the left and to the right of the circle in question
 **/
interval get_current_screen_interval(const circle_properties &circle, const vector<double> &screen_intervals);

/**
 * Takes in two doubles and swaps their values
 * @param   value1  The first double of the swap
 * @param   value2  The second double of the swap
 **/
void swap(int value1, int value2);

/**
 * Calculates the value between 0 and 1 using the differences
 * between the input and minimum values as well as between 
 * the input and maximum values
 * @param   input_value     The value used to find the number between 0 and 1
 * @param   value1          The minimum value
 * @param   value2          The maximum value
 * @returns A value between 0 and 1
 **/
double interpolate_between_values(double input_value, double value1, double value2);

/**
 * Calculates the value between 0 and 1 using the differences
 * between the input and minimum values as well as between 
 * the input and maximum values. This instance of the function
 * also allows for inverting the calculated value by returning
 * its complementary
 * @param   input_value     The value used to find the number between 0 and 1
 * @param   value1          The minimum value
 * @param   value2          The maximum value
 * @param   invert          Whether to return the calculated value's complementary
 * @returns A value between 0 and 1
 **/
double interpolate_between_values(double input_value, double value1, double value2, bool invert);

#endif