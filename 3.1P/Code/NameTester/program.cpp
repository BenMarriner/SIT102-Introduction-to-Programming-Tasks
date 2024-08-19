#include "splashkit.h"
#include "terminal_user_input.h"

int display_main_menu() // Show menu options in terminal
{
    int selection;
    
    write_line("1: Name Messages");                           // Name messages feature
    write_line("2: Play Guess that Number");                  // Guess that number game
    write_line("3: Quit Program");                            // Quit the program
    selection = read_integer("Please select an option: ");                         
    return selection;                                         // Selected menu item number
}

void name_messages() // Name messages feature
{
    string name_selection = read_string("Please type in a name: ");
    
    // Valid names and messages
    if (name_selection == "Lael")
    {
        write_line("Lives off of ice-cream and cake");
    }
    else if (name_selection == "Darsh")
    {
        write_line("Lives in a gym");
    }
    else if (name_selection == "Sarah")
    {
        write_line("Makes good butter chicken curry");
    }
    else if (name_selection == "Ash")
    {
        write_line("Lives life with no regrets");
    }
    else if (name_selection == "Olivia")
    {
        write_line("Has an eye for room decoration");
    }
    else // Print this if there is no match
    {
        write_line("Name not found");
    }
}

void guess_that_number()
{
    int correctNumber = rnd(100) + 1; // Number to guess
    int guess; // Player's guess

    write_line("I am thinking of a number between 1 and 100.");
    write_line("Which number is it?");

    // Repeatedly check the player's guess until it is correct
    do
    {
        guess = read_integer("Enter your number here: ");
        if (guess < correctNumber)
        {
            write_line("Go a bit higher than that");
        }
        else if (guess > correctNumber)
        {
            write_line("Go a bit lower than that");
        }
    } while (guess != correctNumber);
    write_line("Congratulations! You are correct"); // Print this once the player guesses the number
}

int main()
{
    int menu_selection; // Number of the selected menu item

    do // The loop to keep the program running until the user wants to quit the program
    {
        menu_selection = display_main_menu();
        switch (menu_selection)
        {
            case 1:
                /* Name Messages */
                name_messages();
                break;
            case 2:
                /* Guess that Number */
                guess_that_number();
                break;
            case 3:
                /* Quit Program */
                break;
            default:
                /* Invalid Menu Selection */
                write_line("Invalid selection. Please try again");
                break;
        }        
    } while (menu_selection != 3); // Repeat while the user hasn't selected quit
    
    return 0;
}