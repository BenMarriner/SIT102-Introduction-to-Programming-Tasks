#include "splashkit.h"

#define STROUHAL 0.33 // Strouhal's number

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

double calculate_air_speed(double freq, double amp) // calculate air speed of bird using the equation
{
    amp = amp / 100;
    return freq * amp / STROUHAL;
}

void output_air_speed(double amp, double freq, string birdname) // print air speed in terminal
{
    double air_speed = calculate_air_speed(freq, amp);
    write("The air speed of the " + birdname + " is: ");
    write_line(air_speed);
}

int calculate_afl_score(int behinds, int goals) // calculate afl score. Behinds means points
{   
    return goals * 6 + behinds;
}

void output_afl_score(int goals, int behinds)
{
    write("Your AFL team's score is: ");
    write_line(calculate_afl_score(behinds, goals));
}

int main()
{
    string name = read_string("What is your name?"); // input name
    string age = read_string("How old are you?"); // input age

    write_line("Name: " + name); // output name to terminal
    write_line("Age: " + age); // output age to terminal

    // African Swallow
    output_air_speed(21, 15, "African Swallow");
    // European Swallow
    output_air_speed(22, 14, "European Swallow");
    // Custom bird
    output_air_speed
    (
        read_double("Enter amplitude"), // Input amplitude in terminal
        read_double("Enter frequency"), // Input frequency in terminal
        read_string("Enter the name of the bird:") // Input name of bird in terminal
    );
    
    output_afl_score
    (
        read_integer("Enter number of behinds (points):"), // Input behinds (points)
        read_integer("Enter number of goals:") // Input goals
    );
    
    return 0;
}