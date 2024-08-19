#include "splashkit.h"
#include "terminal_user_input.h"

using namespace std;

#define SIZE 3

int total_length(string names[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += names[i].length();
    }
    return sum;
}

string longest_name(string names[], int size)
{
    int current_longest_length = 0;
    for (int i = 0; i < size; i++)
    {
        if (names[i].length() > current_longest_length)
        {
            current_longest_length = i;
        }
    }
    return names[current_longest_length];
}

int index_of(string value, string data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (value == data[i])
        {
            return i;
        }
    }
    return -1;
}

void print_summary(string data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        write_line(data[i]);
    }
    write_line("Total Length: " + to_string(total_length(data, size)));
    write_line("Longest name: " + longest_name(data, size));
    write_line("Index of my name: " + to_string(index_of("Ben", data, size)));
}

int main()
{
    string names[SIZE];
    int name_change_index;

    for (int i = 0; i < SIZE; i++)
    {
        names[i] = read_string("Enter a name:");
    }
    print_summary(names, SIZE);
    

    do
    {
        name_change_index = index_of(read_string("Enter name to change:"), names, SIZE);
    } while (name_change_index == -1);
    names[name_change_index] = read_string("Please enter new name:");

    print_summary(names, SIZE);

    return 0;
}