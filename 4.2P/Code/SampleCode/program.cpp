#include "splashkit.h"
#include "terminal_user_input.h"

using namespace std;

int display_menu()
{
    write_line("1: Feet to Metres");
    write_line("2: Metres to Feet");
    write_line("3: Quit");
    return read_integer_range("Please select an option from the menu: ", 1, 3);
}

double feet_to_metres(double conversion_number)
{
    return conversion_number / 3.28;
}

double metres_to_feet(double conversion_number)
{
    return conversion_number * 3.28;
}

int main()
{
    int menu_selection;

    do
    {
        menu_selection = display_menu();

        switch (menu_selection)
        {
            case 1:
                write_line(to_string(feet_to_metres(read_double("Enter value in feet:"))) + " metres");
                break;
            case 2:
                write_line(to_string(metres_to_feet(read_double("Enter value in metres:"))) + " feet");
        }
    } while (menu_selection != 3);
    
    return 0;
}