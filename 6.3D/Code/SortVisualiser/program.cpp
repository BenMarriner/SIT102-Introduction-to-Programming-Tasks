// Link to Screencast: https://youtu.be/Uf63VB2nAU0

#include "splashkit.h"

#define NUM_VALS 100

void draw_values(const int values[], int size) 
{
    int x = 0;
    int y;
    int rect_height;
    int rect_width = screen_width() / size;

    for (int i = 0; i < size; i++)
    {
        rect_height = values[i];
        y = screen_height() - rect_height;

        fill_rectangle(COLOR_RED, x, y, rect_width, rect_height);
        draw_rectangle(COLOR_WHITE, x, y, rect_width, rect_height);
        
        x += rect_width;
    }
}

void swap(int &value1, int &value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

void draw_sort(int values[], int size)
{
    clear_screen(COLOR_WHITE);
    draw_values(values, size);
    refresh_screen(60);
}

void bubble_sort(int values[], int size)
{
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (values[i] > values[i + 1])
            {
                swap(values[i], values[i + 1]);
                draw_sort(values, size);
            }
        }
    }
}

// Sorts the values in a partition using the specified pivot
int partition(int values[], int size, int start, int end)
{
    int pivot = values[end];
    int partitionIndex = start;

    for(int i = start; i < end; i++)
    {
        if (values[i] <= pivot)
        {
            swap(values[i], values[partitionIndex]);
            draw_sort(values, size);
            partitionIndex++;
        }
    }
    swap(values[partitionIndex], values[end]);
    return partitionIndex;
}

/**
 * Takes the last number of an array and uses it as a pivot.
 * It then sorts the numbers into two partitions: a partition
 * with numbers less than or equal to the pivot and another 
 * with the ones that are greater. It then repeats the process 
 * with the two partitions as if they were their own arrays
 * until the partitions only contain one value.
 */
void quick_sort(int values[], int size, int start, int end)
{
    if (start < end)
    {
        int partitionIndex = partition(values, size, start, end);
        quick_sort(values, size, start, partitionIndex - 1);
        quick_sort(values, size, partitionIndex + 1, end);
    }
}

void random_fill_array(int values[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        values[i] = rnd(screen_height()) + 1;
    }
}

void handle_input(int values[], int size)
{
    if (key_typed(R_KEY))
    {
        random_fill_array(values, size);
    }
    else if (key_typed(S_KEY))
    {
        bubble_sort(values, size);
    }
    else if (key_typed(D_KEY))
    {
        quick_sort(values, size, 0, size - 1);
    }
}

int main()
{
    int values[NUM_VALS];

    open_window("Sort Visualiser", 800, 600);
    
    random_fill_array(values, NUM_VALS);

    while ( not quit_requested() )
    {
        process_events();
        handle_input(values, NUM_VALS);
        
        draw_sort(values, NUM_VALS);
    }

    return 0;
}