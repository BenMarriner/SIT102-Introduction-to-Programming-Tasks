#include "splashkit.h"
#include "terminal_user_input.h"

using namespace std;

int main()
{
    string test_string = read_string("Type something: ");
    int test_integer = read_integer("Type an integer: ");
    double test_double = read_double("Type a decimal number: ");

    write_line("You typed " + test_string + " as the string");
    write_line("You typed " + to_string(test_integer) + " as the integer");
    write_line("You typed " + to_string(test_double) + " as the double");
    
    return 0;
}