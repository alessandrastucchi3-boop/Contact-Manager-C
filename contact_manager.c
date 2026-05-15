#include <stdio.h>
#include <string.h>

// Contact structure definition
typedef struct
{
    char name[50];
    char number[50];
}
contact;

// Function prototypes
void sort_contacts(contact list[], int n);
int search_contact(contact list[], int n, char name[50]);
contact get_contact(void);

int main(void)
{
    int N = 5;
    contact contacts_list[N];
    char target_name[50];
    int index;

    // Data input
    for(int i = 0; i < N; i++)
    {
        contacts_list[i] = get_contact();
    }

    // Sort contacts alphabetically
    sort_contacts(contacts_list, N);

    printf("\n--- Alphabetical Contact List ---\n");
    for(int i = 0; i < N; i++)
    {
        printf("Name: %s | Number: %s\n", contacts_list[i].name, contacts_list[i].number);
    }

    // Search functionality
    printf("\nWhat contact are you looking for? ");
    scanf("%s", target_name);

    index = search_contact(contacts_list, N, target_name);

    if (index != -1)
    {
        printf("Success! The number is: %s\n", contacts_list[index].number);
    }
    else
    {
        printf("Contact not found.\n");
    }

    return 0;
}

contact get_contact(void)
{
    contact c;
    printf("Enter name: ");
    scanf("%s", c.name);
    printf("Enter phone number: ");
    scanf("%s", c.number);
    return c;
}

void sort_contacts(contact list[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(list[j].name, list[j + 1].name) > 0)
            {
                contact temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

int search_contact(contact list[], int n, char name[50])
{
    for(int i = 0; i < n; i++)
    {
        if(strcmp(list[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}
