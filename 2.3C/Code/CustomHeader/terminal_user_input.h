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
 * Similar to read_string but provided the text typed by
 * the user is a double, the function will return
 * the number as an double. This enables it to be used in
 * calculations
 * 
 * @param prompt    The question asked by the terminal
 * @returns         The double that is typed
 */
double read_double(string prompt);

#endif