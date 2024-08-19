#include "splashkit.h"
#include "terminal_user_input.h"
#include <vector>

using namespace std;
using std::vector;

#define SIZE 3

int total_length(vector<string> names)
{
    int sum = 0;
    for (int i = 0; i < names.size(); i++)
    {
        sum += names[i].length();
    }
    return sum;
}

string longest_name(vector<string> names)
{
    int current_longest_length = 0;
    for (int i = 0; i < names.size(); i++)
    {
        if (names[i].length() > current_longest_length)
        {
            current_longest_length = i;
        }
    }
    return names[current_longest_length];
}

int index_of(string value, vector<string> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (value == data[i])
        {
            return i;
        }
    }
    return -1;
}

void print_summary(const vector<string> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        write_line(data[i]);
    }
    write_line("Total Length: " + to_string(total_length(data)));
    write_line("Longest name: " + longest_name(data));
    write_line("Index of my name: " + to_string(index_of("Ben", data)));
}

int main()
{
    vector<string> names;
    int name_change_index;
    int number_of_names = read_integer("How many names would you like to add?");

    for (int i = 0; i < number_of_names; i++)
    {
        names.push_back(read_string("Enter a name:"));
    }
    print_summary(names);
    

    do
    {
        name_change_index = index_of(read_string("Enter name to change:"), names);
    } while (name_change_index == -1);
    names[name_change_index] = read_string("Please enter new name:");

    print_summary(names);

    return 0;
}