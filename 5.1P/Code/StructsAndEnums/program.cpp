#include "splashkit.h"
#include "terminal_user_input.h"
#include <string>

using namespace std;

struct knight_data
{
    string name;
    int age;
    string birth_month;
    int level;
};

enum knight_update_option
{
    UPDATE_NAME,
    UPDATE_AGE,
    UPDATE_BIRTH_MONTH,
    UPDATE_LEVEL,
    FINISH_UPDATE
};

string read_birth_month()
{
    int birth_month;
    
    write_line("1: January");
    write_line("2: February");
    write_line("3: March");
    write_line("4: April");
    write_line("5: May");
    write_line("6: June");
    write_line("7: July");
    write_line("8: August");
    write_line("9: September");
    write_line("10: October");
    write_line("11: November");
    write_line("12: December");
    birth_month = read_integer_range("Pick a birth month:", 1, 12);
    
    switch (birth_month)
    {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
    }
}

knight_update_option read_knight_update_option()
{
    int result;

    write_line("1: Update name");
    write_line("2: Update age");
    write_line("3: Update birth month");
    write_line("4: Update level");
    write_line("5: Finish update");
    result = read_integer_range("Select option:", 1, 5);
    return static_cast<knight_update_option>(result - 1);
}

knight_data read_knight()
{
    knight_data result;

    result.name = read_string("Enter name: ");
    result.age = read_integer("Enter age: ");
    result.birth_month = read_birth_month();
    result.level = read_integer("Enter level for your knight: ");

    return result;
}

void write_knight(const knight_data &knight)
{
    write_line("Hello " + knight.name + " aged " + to_string(knight.age) + " born in " + knight.birth_month);
    write_line("You are level " + to_string(knight.level));
}

void update_knight(knight_data &knight)
{
    int option;

    do
    {
        write_line();
        write_line("== Update Knight ==");
        write_line();
        option = read_knight_update_option();
        
        switch (option)
        {
            case UPDATE_NAME:
                knight.name = read_string("Enter new name:");
                write_knight(knight);
                break;
            case UPDATE_AGE:
                knight.age = read_integer("Enter new age:");
                write_knight(knight);
                break;
            case UPDATE_BIRTH_MONTH:
                knight.birth_month = read_birth_month();
                write_knight(knight);
                break;
            case UPDATE_LEVEL:
                knight.level = read_integer("Enter new level:");
                write_knight(knight);
            case FINISH_UPDATE:
                break;
        }
    } while ( option != FINISH_UPDATE );
}

int main()
{
    knight_data my_knight = read_knight();

    write_knight(my_knight);
    update_knight(my_knight);

    return 0;
}