/**
 * Here is just some math functions that are needed throughout various parts
 * of the program such as the animations for the shapes and the rendering
 * system
 **/

#include "math.h"

/**
 * Divides the width of the window into sixths
 * and stores each sixth's horizontal position 
 * in pixels in an array of doubles
 **/
vector<double> screen_intervals()
{
    vector<double> screen_intervals;
    for (double current_interval = 0; current_interval <= 5 /* Number of intervals */; current_interval++)
    {
        screen_intervals.push_back(screen_width() * (current_interval / 5));
    }
    return screen_intervals;
}

/**
 * Get the current section of the window a circle is in
 **/
interval get_current_screen_interval(const circle_properties &circle, const vector<double> &screen_intervals)
{
    int i = 1;
    int j = 0;
    while (i < screen_intervals.size())
    {
        if (circle.x >= screen_intervals[j] && circle.x < screen_intervals[i])
        {
            return {screen_intervals[j], screen_intervals[i]};
        }
        i++; 
        j++;
    }
    return {-1, -1};
}

/**
 * Takes in two doubles and swaps their values
 **/
void swap(int value1, int value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

/**
 * Calculates the value between 0 and 1 using the differences
 * between the input and minimum values as well as between 
 * the input and maximum values
 **/
double interpolate_between_values(double input_value, double value1, double value2)
{
    if (value1 > value2)
    {
        swap(value1, value2);
    }
    return (value2 - input_value) / (value2 - value1);
}

/**
 * Calculates the value between 0 and 1 using the differences
 * between the input and minimum values as well as between 
 * the input and maximum values. This instance of the function
 * also allows for inverting the calculated value by returning
 * its complementary
 **/
double interpolate_between_values(double input_value, double value1, double value2, bool invert)
{
    if (invert)
    {
        return 1 - interpolate_between_values(input_value, value1, value2);
    }
    else
    {
        return interpolate_between_values(input_value, value1, value2);
    }
}