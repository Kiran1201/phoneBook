#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a contact
typedef struct
{
    char name[50];
    char phone[15];
} Contact;

// Define a structure for a linked list node
typedef struct node
{
    Contact contact;
    struct node *next;
} Node;

// Declare functions for the phonebook application
void add_contact(Node **head);
void delete_contact(Node **head, char *name);
void search_contact(Node *head, char *name);
void modify_contact(Node *head, char *name);
void sort_contacts(Node *head);
void filter_contacts(Node *head, char *phone);

int main()
{
    Node *head = NULL;
    int choice;
    char name[50];
    char search_name[50];
    char modify_name[50];
    char filter_phone[15];

    // Display the main menu and get the user's choice
    do
    {
        printf("\nPhonebook Application\n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Search contact\n");
        printf("4. Modify contact\n");
        printf("5. Sort contacts\n");
        printf("6. Filter contacts\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_contact(&head);
            break;
        case 2:
            printf("Enter name to delete: ");
            scanf("%s", name);
            delete_contact(&head, name);
            break;
        case 3:

            printf("Enter name to search: ");
            scanf("%s", search_name);
            search_contact(head, search_name);
            break;
        case 4:

            printf("Enter name to modify: ");
            scanf("%s", modify_name);
            modify_contact(head, modify_name);
            break;
        case 5:
            sort_contacts(head);
            break;
        case 6:
            printf("Enter phone to filter: ");
            scanf("%s", filter_phone);
            filter_contacts(head, filter_phone);
            break;
        case 7:
            printf("Exiting application...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 7);

    // Free memory allocated for the linked list
    Node *current = head;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

// The add_contact function takes a double pointer to the head of the linked list as its parameter. It prompts the user to enter a new contact's name and phone number and creates a new node for the linked list to store the contact information. If the linked list is empty, the new node becomes the head of the list. Otherwise, the function iterates through the list to find the last node and adds the new node after it.

// Here's the implementation of the add_contact function:

void add_contact(Node **head)
{
    Contact new_contact;

    // Get input for the new contact
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter phone: ");
    scanf("%s", new_contact.phone);

    // Create a new node for the linked list
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->contact = new_contact;
    new_node->next = NULL;

    // Add the new node to the end of the linked list
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }

    printf("Contact added successfully.\n");
}

// Note that the scanf function is used to read input from the user and store it in the new_contact variable. The malloc function is used to allocate memory for the new node, and the -> operator is used to access the contact and next members of the node. The *head pointer is dereferenced to check if the list is empty, and the current pointer is used to iterate through the list. Finally, a message is printed to confirm that the contact was added successfully.

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
// The delete_contact function takes a double pointer to the head of the linked list and a pointer to a character array representing the name of the contact to be deleted. It iterates through the list to find the node that contains the contact with the specified name, and removes that node from the list.

// Here's the implementation of the delete_contact function:

void delete_contact(Node **head, char *name)
{
    Node *current = *head;
    Node *previous = NULL;

    while (current != NULL)
    {
        if (strcmp(current->contact.name, name) == 0)
        {
            // Remove the node from the list
            if (previous == NULL)
            {
                *head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            printf("Contact deleted successfully.\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Contact not found.\n");
}

// Note that the strcmp function is used to compare the name parameter to the name member of the Contact struct in each node. The previous pointer is used to keep track of the previous node as the list is iterated, so that the next pointer of that node can be updated to skip over the deleted node. The free function is used to deallocate the memory used by the deleted node, and a message is printed to confirm that the contact was deleted successfully. If the contact is not found in the list, a message is printed to indicate that.

// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// The search_contact function takes a pointer to the head of the linked list and a pointer to a character array representing the name of the contact to be searched. It iterates through the list to find the node that contains the contact with the specified name, and prints the name and phone number of that contact.

// Here's the implementation of the search_contact function:

void search_contact(Node *head, char *name)
{
    Node *current = head;
    while (current != NULL)
    {
        if (strcmp(current->contact.name, name) == 0)
        {
            printf("Name: %s\nPhone: %s\n", current->contact.name, current->contact.phone);
            return;
        }
        current = current->next;
    }
    printf("Contact not found.\n");
}

// Note that the strcmp function is used to compare the name parameter to the name member of the Contact struct in each node. If a node containing a matching contact is found, the name and phone members of that contact are printed using printf. If no matching contact is found, a message is printed to indicate that.
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// The modify_contact function takes a pointer to the head of the linked list and a pointer to a character array representing the name of the contact to be modified. It iterates through the list to find the node that contains the contact with the specified name, and prompts the user to enter new values for the contact's name and phone number. The function then updates the name and phone members of the contact with the new values.

// Here's the implementation of the modify_contact function:

void modify_contact(Node *head, char *name)
{
    Node *current = head;
    while (current != NULL)
    {
        if (strcmp(current->contact.name, name) == 0)
        {
            // Get input for the new contact information
            printf("Enter new name: ");
            scanf("%s", current->contact.name);
            printf("Enter new phone: ");
            scanf("%s", current->contact.phone);
            printf("Contact modified successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("Contact not found.\n");
}
// Note that the strcmp function is used to compare the name parameter to the name member of the Contact struct in each node. If a node containing a matching contact is found, the scanf function is used to read input from the user and store it in the name and phone members of the contact. A message is printed to confirm that the contact was modified successfully. If no matching contact is found, a message is printed to indicate that.
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// The sort_contacts function takes a pointer to the head of the linked list, and sorts the contacts in the list alphabetically by name. The function uses a simple selection sort algorithm to perform the sorting.

// Here's the implementation of the sort_contacts function:

void sort_contacts(Node *head)
{
    Node *i, *j, *min_node;
    Contact temp;

    // Traverse the list
    for (i = head; i != NULL; i = i->next)
    {
        // Find the minimum element in the unsorted part of the list
        min_node = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (strcmp(j->contact.name, min_node->contact.name) < 0)
            {
                min_node = j;
            }
        }
        // Swap the minimum element with the current element
        if (min_node != i)
        {
            temp = i->contact;
            i->contact = min_node->contact;
            min_node->contact = temp;
        }
    }

    printf("Contacts sorted successfully.\n");
}

// The strcmp function is used to compare the name member of each contact in the list. The function then swaps the Contact structs in each node as needed to put the contacts in alphabetical order. Finally, a message is printed to confirm that the contacts were sorted successfully.
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// The filter_contacts function takes a pointer to the head of the linked list and a pointer to a character array representing the phone number to be filtered. It iterates through the list to find the nodes that contain the contacts with phone numbers that match the specified phone number, and prints the names and phone numbers of those contacts.

// Here's the implementation of the filter_contacts function:

void filter_contacts(Node *head, char *phone)
{
    Node *current = head;
    int count = 0;
    while (current != NULL)
    {
        if (strcmp(current->contact.phone, phone) == 0)
        {
            printf("Name: %s\nPhone: %s\n", current->contact.name, current->contact.phone);
            count++;
        }
        current = current->next;
    }
    if (count == 0)
    {
        printf("No contacts found with phone number %s.\n", phone);
    }
    else
    {
        printf("%d contact(s) found with phone number %s.\n", count, phone);
    }
}
// Note that the strcmp function is used to compare the phone parameter to the phone member of the Contact struct in each node. If a node containing a matching contact is found, the name and phone members of that contact are printed using printf. If no matching contacts are found, a message is printed to indicate that. If one or more matching contacts are found, a message is printed to indicate how many contacts were found.
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
