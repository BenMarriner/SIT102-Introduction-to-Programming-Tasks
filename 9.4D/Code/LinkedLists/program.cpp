#include "splashkit.h"

#include <functional>
using namespace std;

/**
 * Forward declare that a node is a pointer to
 * a struct node_data value.
 */
typedef struct node_data *node;

/**
 * The linked list has a first and
 * a last node.
 *
 * @field first The first node in the list (or nullptr when it is empty)
 * @field last  The last node in the list (or nullptr when it is empty)
 */
struct linked_list
{
    node first;
    node last;
};

/**
 * Each node records its data, the next and previous
 * nodes, and the list. This allows both forward and
 * reverse iteration through the list, and makes it
 * easier to add and remove elements.
 *
 * @field data      The value in this node
 * @field next      A pointer to the next node in the list
 * @field prev      A pointer to the previous node in the list
 * @field in_list   A pointer to the linked list that contains this node
 */
struct node_data
{
    int data;
    node next;
    node prev;
    linked_list *in_list;
};

/**
 * Setup an empty list.
 *
 * @param list  The list to initialise, passed by reference
 */
void initialise_list(linked_list &list)
{
    list.first = nullptr;
    list.last = nullptr;
}

/**
 * Checks if a list is empty.
 *
 * @param list  The list to check
 * @returns     True when the list is empty
 */
bool list_is_empty(const linked_list &list)
{
    return list.first == nullptr; // last will also be null
}

/**
 * Creates a new node in memory, and returns a pointer to it.
 *
 * @param value     The value for the node
 * @param list      The list the node will be in
 * @param prev      The node before this in the list
 * @param next      The node after this in the list
 */
node new_node(int value, linked_list &list, node prev, node next)
{
    node result;

    result = new node_data();

    result->data = value;
    result->prev = prev;
    result->next = next;
    result->in_list = &list;

    return result;
}

void add_to_start(linked_list &list, int value)
{
    node added_node = new_node(value, list, nullptr, list.first);

    if (not list_is_empty(list))
    {
        list.first -> prev = added_node;
        list.first = added_node;
    }
    else
    {
        list.first = added_node;
        list.last = added_node;
    }
}

/**
 * Add a new node to the end of the list.
 *
 * @param list      The list to add the node to. Passed by reference.
 * @param value     The value to store in the node.
 */
void add_to_end(linked_list &list, int value)
{
    node added_node;

    added_node = new_node(value, list, list.last, nullptr);

    if (not list_is_empty(list))
    {
        list.last->next = added_node; // point last node to new node
        list.last = added_node;
    }
    else
    {
        list.first = added_node;
        list.last = added_node;
    }
}

/**
 * Search the list for the first node that has the 
 * indicated value, or nullptr if there is no matching
 * value in the list.
 * 
 * @param list      The list to search
 * @param value     The value to search for
 * @returns         A pointer to the first node with that value, or 
 *                  nullptr if not in list.
 */
node find_first(const linked_list &list, int value)
{
    node current;

    current = list.first;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            return current;
        }

        current = current->next;
    }

    return nullptr;
}

void insert_after(node selected_node, int value)
{
    if (selected_node == nullptr) return;
    
    linked_list *list = selected_node -> in_list;
    node after = selected_node -> next;
    node added_node = new_node(value, *list, selected_node, after);
    
    selected_node -> next = added_node;
    // Check if there exists a node after the selected one.
    // If there is not, then this was the last one in the list
    if (after != nullptr)
    {
        after -> prev = added_node;
    }
}

/**
 * Delete the passed in node from its list.
 *
 * @param current   The node to delete
 */
void delete_node(node current)
{
    if ( current == nullptr ) return;

    linked_list *list;
    node before, after;

    list = current->in_list;
    before = current->prev;
    after = current->next;

    // is there something before this node?
    if (before != nullptr)
    {
        before->next = current->next;
    }
    else
    {
        // nothing before... so was first
        list->first = after;
    }

    // is there something after this node?
    if (after != nullptr)
    {
        after->prev = current->prev;
    }
    else
    {
        // nothing after... so was last
        list->last = before;
    }

    // now delete... and remove any links out to make sure
    current->prev = nullptr;
    current->next = nullptr;

    delete current;
}

/**
 * Print out the details of the passed in node.
 *
 * @param current       The node to print
 */
void print_node(node current)
{
    if ( current == nullptr ) return;

    write(" -> " + to_string(current->data));
}

/**
 * Print all of the node in this linked list.
 *
 * @param list      The list to print the nodes from.
 */
void print_all(const linked_list &list)
{
    node current;

    current = list.first;

    while (current != nullptr)
    {
        print_node(current);
        current = current->next;
    }
    write_line(".");
}

void reverse_print_all(const linked_list &list)
{
    node current = list.last;

    while (current != nullptr)
    {
        print_node(current);
        current = current -> prev;
    }
    write_line(".");
}

/**
 * A visitor is a procedure (void function) that accepts a node parameter.
 */
typedef std::function<void(node)> visitor;

/**
 * The for each function loops over the elements of
 * a list and executes a visitor function on each element.
 *
 * @param list  The list of nodes to visit
 * @param fn    The function to call
 */
void for_each(const linked_list &list, visitor fn)
{
    node current;
    current = list.first;

    while (current != nullptr)
    {
        fn(current);
        current = current->next;
    }
}

void reverse_for_each(const linked_list &list, visitor fn)
{
    node current = list.last;

    while (current != nullptr)
    {
        fn(current);
        current = current -> prev;
    }
}

/**
 * Print all of the nodes from the list (using the for each function).
 *
 * @param list      The list of nodes to print
 */
void print_with_visitor(const linked_list &list)
{
    for_each(list, print_node);
    write_line(".");
}

void reverse_print_all_with_visitor(const linked_list &list)
{
    reverse_for_each(list, print_node);
    write_line(".");
}

/**
 * Sum all of the values from within the list.
 *
 * @param list      The list to sum the nodes of.
 * @returns         The sum of all of the lists node values
 */
int sum(const linked_list &list)
{
    int result = 0;

    for_each(list,
             [&](node current) {
                 result += current->data;
             });

    return result;
}

int length(const linked_list &list)
{
    int  result = 0;

    reverse_for_each(list,
                    [&](node current)
                    {
                        if (current != nullptr)
                        {
                            result++;
                        }
                    });
    return result;
}
/**
 * Program entry point... tests the above functions.
 */
int main()
{
    linked_list my_list;

    initialise_list(my_list);

    // Build a list 10 -> 20 -> 30...

    write_line("TEST: Add to end");
    add_to_end(my_list, 10);
    add_to_end(my_list, 20);
    add_to_end(my_list, 30);
    print_all(my_list);

    // Add additional nodes to the start of the list...

    write_line("TEST: Add to start");
    add_to_start(my_list, 100);
    print_all(my_list);

    // Test that sum works correctly
    write_line("TEST: Sum");
    write("Sum is: ");
    write_line(sum(my_list));

    write_line("TEST: Length");
    write_line(length(my_list));

    node found;

    //Test find and delete...
    found = find_first(my_list, 20);
    delete_node(found);
    print_all(my_list);

    // Delete start and end as well...
    found = find_first(my_list, 10);
    delete_node(found);
    print_with_visitor(my_list);

    found = find_first(my_list, 30);
    delete_node(found);
    print_all(my_list);

    //Add a new
    add_to_end(my_list, 40);
    print_all(my_list);
    reverse_print_all(my_list);

    // Insert test
    insert_after(my_list.first, 120);
    print_all(my_list); 

    // Reverse print all test
    reverse_print_all_with_visitor(my_list);

    return 0;
}