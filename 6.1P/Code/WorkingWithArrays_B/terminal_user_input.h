#ifndef TERMINAL_USER_INPUT
#define TERMINAL_USER_INPUT

#include <string>
using std::string;

/**
 * Gives the user a chance to input something by
 * first giving them a prompt and then returning
 * the text that they typed
 * 
 * @param prompt    The question asked by the terminal
 * @returns         The text that is typed
 */
 string read_string(string prompt);

/**
 * Similar to read_string but provided the text typed by
 * the user is an integer number, the function will return
 * the number as an integer. This enables it to be used in
 * calculations
 * 
 * @param prompt    The question asked by the terminal
 * @returns         The integer that is typed
 */
int read_integer(string prompt);

/**
 * A variant of read_integer that checks whether a number
 * is in a given range or not. If an out-of-range integer
 * is typed, the terminal will ask for one that is within
 * range
 * 
 * @param prompt    The question asked by the terminal
 * @param min       The minimum integer that can be accepted
 * @param max       The maximum integer that can be accepted          
 * @returns         The integer that is typed
 */
int read_integer_range(string prompt, int min, int max);

/**
 * Similar to read_string but provided the text typed by
 * the user is a double, the function will return
 * the number as an double. This enables it to be used in
 * calculations
 * 
 * @param prompt    The question asked by the terminal
 * @returns         The double that is typed
 */
double read_double(string prompt);

/**
 * A variant of read_double that checks whether a number
 * is in a given range or not. If an out-of-range double
 * is typed, the terminal will ask for one that is within
 * range
 * 
 * @param prompt    The question asked by the terminal
 * @param min       The minimum double that can be accepted
 * @param max       The maximum double that can be accepted          
 * @returns         The double that is typed
 */
double read_double_range(string prompt, double min, double max);

/**
 * Returns true or false depending on whether the user has typed
 * Yes, y, No or n
 * @param prompt    The question asked by the terminal
 * @returns         True or false
**/
bool read_boolean(string prompt);

#endif