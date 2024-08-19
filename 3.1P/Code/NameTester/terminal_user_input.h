#ifndef TERMINAL_USER_INPUT
#define TERMINAL_USER_INPUT

#include <string>
using std::string;

// Reads what the user types as a string
string read_string(string prompt);

// Reads what the user types as an integer
int read_integer(string prompt);  

// Reads what the user types as a double
double read_double(string prompt);

#endif