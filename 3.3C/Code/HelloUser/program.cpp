#include "splashkit.h"
#include "terminal_user_input.h"

int main()
{
    // Test program
    string name;
    int age;
    double height;
    bool test;

    bool again;

    do
    {
        name = read_string("Enter your name: ");
        write_line("For read integer test errors for real numbers and text");
        write_line(" - eg '3.1415' and 'fred'");
        age = read_integer("Enter your age: ");
        write_line("For read double test errors for text = eg 'fred'");
        height = read_double("Enter your height: ");
        write_line("read boolean test errors with text other than yes or no");
        test = read_boolean("Testing read boolean: ");

        write_line("Got values: ");
        write("String: ");
        write_line(name);
        write("Integer: ");
        write_line(age);
        write("Double: ");
        write_line(height);
        write("Boolean: ");
        if (test)
        {
            write_line("yes");
        }
        else
        {
            write_line("no");
        }

        again = read_boolean("Try this again? ");
    } while (again);
    return 0;
}