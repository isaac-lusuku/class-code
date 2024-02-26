#include <iostream>;
#include <list>;
#include <stdio.h>;
#include <stdlib.h>;
#include <string>;

using namespace std;

struct Node
{
    int number;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        cout << "There was an \"ERROR\" creating the Node";
        exit(1);
    }
    else {
        newNode->number = num;
        newNode->next = NULL;
        return newNode;
    }
};

void printList(struct Node* head) {
        struct Node* current = head;
        printf("[");
        while (current != NULL) {
            printf("%d", current->number);
            current = current->next;

            if (current != NULL) {
                printf(", ");
            }
        }
        printf("]\n");
};

void append(struct Node** head, int num) {
    struct Node* newNode = createNode(num);
    if (head == NULL) {
        *head = newNode;
    }
    else {
        struct Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;

    }
    
};

void prepend(struct Node** head, int num) {
    struct Node* newNode = createNode(num);
    newNode->next = *head;
    *head = newNode;
};

void deleteByKey(struct Node** head, int key) {
    struct Node* current = *head;
    struct Node* prev = *head;
    int counter = 1;
    while (true) {
        if (counter == key) {
            break;
        }
        else {
            prev = current;
            current = current->next;
            ++counter;
        }
    }
    struct Node* curr_next = current->next;
    prev->next = curr_next;
    delete current;
};

void deleteByValue(struct Node** head, int value) {
    struct Node* current = *head;
    struct Node* prev = *head;
    while (true) {
        if (current->number == value) {
            break;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    struct Node* curr_next = current->next;
    prev->next = curr_next;
    delete current;
};
void insertAfterKey(struct Node** head, int key, int value) {
    struct Node* newNode = createNode(value);
    struct Node* current = *head;
    int counter = 1;
    while (true) {
        if (counter == key) {
            break;
        }
        else {
            current = current->next;
            ++counter;
        }
    }
    struct Node* curr_next = current->next;
    current->next = newNode;
    newNode->next = curr_next;
};

void insertAfterValue(struct Node** head, int searchValue, int newValue) {
    struct Node* newNode = createNode(newValue);
    struct Node* current = *head;
    while (true) {
        if (current->number == searchValue) {
            break;
        }
        else {
            current = current->next;
        }
    }
    struct Node* curr_next = current->next;
    current->next = newNode;
    newNode->next = curr_next;
};

int main()
{
    struct Node* head = NULL;
    int choice, data, p_data, char_choice, del_key, del_value;

    while (1)
    {
        printf("Linked Lists\n");
        printf("1. Print List\n");
        printf("2. Append\n");
        printf("3. Prepend\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice){
            case 1:
                printList(head);
                break;
            case 2:
                printf("Enter data to append: ");
                scanf_s("%d", &data);
                append(&head, data);
                break;
            case 3:
                printf("nter data to prepend: ");
                scanf_s("%d", &p_data);
                prepend(&head, p_data);
                break;
            case 4:
                printf("type '1' if you are to use the key for deleting and '2' if you are to use the value ");
                scanf_s("%d", &char_choice);
                if (char_choice == 1) {
                    printf("Enter the key of the value to be deleted ");
                    scanf_s("%d", &del_key);
                    deleteByKey(&head, del_key);
                    break;
                }else if (char_choice == 2) {
                    printf("Enter the value to be deleted ");
                    scanf_s("%d", &del_value);
                    deleteByValue(&head, del_value);
                    break;
                }
                else {
                    printf("you entered a wrong option");
                    continue;
                }
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }

    }

    return 0;
}
