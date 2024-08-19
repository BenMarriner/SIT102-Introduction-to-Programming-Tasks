#include "splashkit.h"
#include "terminal_user_input.h"
#include <string>
#include <vector>

using std::vector;
using namespace std;

struct knight_data
{
    string name;
    int age;
    string birth_month;
    int level;
    vector<string> weapons;
};

struct kingdom_data
{
    string name;
    vector<knight_data> knights;
};

enum knight_update_option
{
    UPDATE_NAME,
    UPDATE_AGE,
    UPDATE_BIRTH_MONTH,
    UPDATE_LEVEL,
    ADD_WEAPON,
    REMOVE_WEAPON,
    FINISH_UPDATE
};

enum kingdom_update_option
{
    ADD_KNIGHT,
    QUERY_KNIGHT,
    DELETE_KNIGHT,
    UPDATE_KNIGHT,
    DISPLAY_KINGDOM_DETAILS,
    QUIT
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
        default:
            return "";
    }
}

knight_update_option read_knight_update_option()
{
    int result;

    write_line("1: Update name");
    write_line("2: Update age");
    write_line("3: Update birth month");
    write_line("4: Update level");
    write_line("5: Add Weapon");
    write_line("6: Remove Weapon");
    write_line("7: Finish update");
    result = read_integer_range("Select option:", 1, 7);
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

void add_weapon(knight_data &knight)
{
    knight.weapons.push_back(to_uppercase(read_string("Please enter the name of the weapon:")));
    write_line("The weapon has been added");
}

void delete_weapon(knight_data &knight, int index)
{
    if (index >= 0 and index < knight.weapons.size())
    {
        int last_idx = knight.weapons.size() - 1;
        write_line("Removed " + knight.weapons[index]);
        knight.weapons[index] = knight.weapons[last_idx];
        knight.weapons.pop_back();
    }
}

void write_knight(const knight_data &knight)
{
    write_line("Name: " + knight.name);
    write_line("Age: " + to_string(knight.age));
    write_line("Birth Month: " + knight.birth_month);
    write_line("Level: " + to_string(knight.level));
    if (knight.weapons.size() == 0)
    {
        write_line("This knight has no weapons");
    }   
    else
    {
        write_line("Weapons List:");
        for (int i = 0; i < knight.weapons.size(); i++)
        {
            write_line(knight.weapons[i]);
        }
    }       
}

void update_knight(knight_data &knight)
{
    knight_update_option option;

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
                break;
            case ADD_WEAPON:
                add_weapon(knight);
                break;
            case REMOVE_WEAPON:
                if (knight.weapons.size() == 0)
                {
                    write_line("No weapons can be found");
                }
                else
                {
                    int weapon_selection;
                    for (int i = 0; i < knight.weapons.size(); i++)
                    {
                        write_line(to_string(i + 1) + ": " + knight.weapons[i]);
                    }
                    weapon_selection = read_integer_range("Please type the number of the weapon you want to delete or type 0 to go back:", 1, knight.weapons.size()) - 1;
                    if (weapon_selection == -1)
                    {
                        break;
                    }
                    else
                    {
                        delete_weapon(knight, weapon_selection);
                    }
                }
                break;
            case FINISH_UPDATE:
                break;
        }
    } while ( option != FINISH_UPDATE );
}

void add_knight(kingdom_data &kingdom)
{
    knight_data new_knight = read_knight();

    kingdom.knights.push_back(new_knight);
}

void write_kingdom(const kingdom_data &kingdom)
{
    write_line("==== Knights ====");
    write_line(kingdom.name);
    for (int i = 0; i < kingdom.knights.size(); i++)
    {
        write_knight(kingdom.knights[i]);
    }
    write_line("==============");
}

void delete_knight(kingdom_data &kingdom, int index)
{
    if (index >= 0 and index < kingdom.knights.size())
    {
        int last_idx = kingdom.knights.size() - 1;
        kingdom.knights[index] = kingdom.knights[last_idx];
        kingdom.knights.pop_back();
    }
}

kingdom_data read_kingdom()
{
    kingdom_data result;
    result.name = read_string("Enter kingdom name:");
    return result;
}

int select_knight(const kingdom_data &kingdom)
{
    int knight_selection;

    for (int i = 0; i < kingdom.knights.size(); i++)
    {
        write_line("[" + to_string(i + 1) + "] " + kingdom.knights[i].name);
    }
    knight_selection = read_integer_range("Please enter the number of the knight you want to select or enter 0 if you do not want to select a knight:", 0, kingdom.knights.size());
    return knight_selection - 1;
    
}

kingdom_update_option read_kingdom_update_options()
{
    int result;
    
    write_line("1: Add Knight");
    write_line("2: Query Knight");
    write_line("3: Delete Knight");
    write_line("4: Update Knight");
    write_line("5: Display Kingdom Details");
    write_line("6: Quit");
    result = read_integer_range("Select option: ", 1, 6);
    return static_cast<kingdom_update_option>(result - 1);
}

void update_kingdom(kingdom_data &kingdom)
{
    kingdom_update_option option;

    do
    {
        write_line();
        write_line("== " + kingdom.name + " ==");
        write_line();
        option = read_kingdom_update_options();
        
        switch (option)
        {
            case (ADD_KNIGHT):
            {
                add_knight(kingdom);
                break;
            }
            case (QUERY_KNIGHT):
            {
                int knight_selection = select_knight(kingdom);
                
                if (knight_selection != -1)
                {
                    write_knight(kingdom.knights[knight_selection]);
                }
                break;
            }
            case (DELETE_KNIGHT):
            {
                int knight_selection = select_knight(kingdom);

                if (knight_selection != -1)
                {
                    delete_knight(kingdom, knight_selection);
                }
                break;
            }
            case (UPDATE_KNIGHT):
            {
                int knight_selection = select_knight(kingdom);

                if (knight_selection != -1)
                {
                    update_knight(kingdom.knights[knight_selection]);
                }
                break;
            }
            case (DISPLAY_KINGDOM_DETAILS):
            {
                write_line("Number of knights in kingdom: " + to_string(kingdom.knights.size()));
                write_line("List of Knights in kingdom:");
                for (int i = 0; i < kingdom.knights.size(); i++)
                {
                    write_line(kingdom.knights[i].name);
                }
            }
            case (QUIT):
            {
                break;
            }
        }
    } while (option != QUIT);
}

int main()
{
    kingdom_data my_kingdom = read_kingdom();
    int number_of_knights = read_integer("Please enter the number of knights you would like to add to the kingdom:");

    for (int i = 0; i < number_of_knights; i++)
    {
        add_knight(my_kingdom);
    }

    update_kingdom(my_kingdom);

    return 0;
}