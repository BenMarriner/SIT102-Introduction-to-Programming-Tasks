#include "splashkit.h"
#include "terminal_user_input.h"

using namespace std;

int display_menu()
{
    write_line("1: Inches to Centimetres");
    write_line("2: Centimetres to Inches");
    write_line("3: Quit");
    return read_integer_range("Please select an option from the menu: ", 1, 3);
}

double inches_to_cm(double conversion_number)
{
    return conversion_number * 2.54;
}

double cm_to_inches(double conversion_number)
{
    return conversion_number / 2.54;
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
                write_line(to_string(inches_to_cm(read_double("Enter value in inches:"))) + " centimetres");
                break;
            case 2:
                write_line(to_string(cm_to_inches(read_double("Enter value in centimetres:"))) + " inches");
        }
    } while (menu_selection != 3);
    
    return 0;
}