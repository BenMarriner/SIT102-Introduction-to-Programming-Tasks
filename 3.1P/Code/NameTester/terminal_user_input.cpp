#include "splashkit.h"

string read_string(string prompt) // input string function
{
    write_line(prompt);
    return read_line();
}

int read_integer(string prompt) // input integer function
{
    return convert_to_integer(read_string(prompt));
}

double read_double(string prompt) // input double function
{
    return convert_to_double(read_string(prompt));
}