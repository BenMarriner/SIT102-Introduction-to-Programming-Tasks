#include "splashkit.h"

using namespace std;

string read_string(string prompt) // input string function
{
    write_line(prompt);
    return read_line();
}

int read_integer(string prompt) // input integer function
{
    string line;
    int result;

    line = read_string(prompt);

    while (not is_integer(line))
    {
        line = read_string("Please enter a whole number");
    }
    
    result = convert_to_integer(line);

    return result;
}

int read_integer_range(string prompt, int min, int max)
{
    int result;

    result = read_integer(prompt);

    while (result < min or result > max)
    {
        result = read_integer("Please enter a number between " + to_string(min) + " and " + to_string(max));
    }

    return result;
}

double read_double(string prompt) // input double function
{
    string line;
    double result;

    line = read_string(prompt);

    while (not is_double(line))
    {
        line = read_string("Please enter a number");
    }
    
    result = convert_to_double(line);

    return result;
}

double read_double_range(string prompt, double min, double max)
{
    int result;

    result = read_double(prompt);

    while (result < min or result > max)
    {
        result = read_double("Please enter a number between " + to_string(min) + " and " + to_string(max));
    }
    
    return result;
}

bool read_boolean(string prompt)
{
    string line = to_lowercase(trim(read_string(prompt)));
    write_line(line);
    
    // Do this until the user enters a satisfactory response
    while (line != "yes" and line != "y" and line != "no" and line != "n")
    {
        line = to_lowercase(trim(read_string("Invalid response, please try again")));
    }
    
    // Return true or false based on which response was inputted
    if (line == "yes" or line == "y")
    {
        return true;
    }
    else
    {
        return false;
    }
}