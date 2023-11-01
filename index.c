#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *next;
};

struct Node *head = NULL;

void addFirst(int val)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->key = val;
    newNode->next = head;

    head = newNode;

    printf("Nodul cu key = %d a fost adaugat cu succes in fata!\n", newNode->key);
}

void addLast(int val)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->key = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *lastNode = head;
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }

    printf("Nodul cu key = %d a fost adaugat cu succes in spate!\n", newNode->key);
}

struct Node *searchByKey(int val)
{
    struct Node *searchedNode = NULL;
    if (head == NULL)
    {
        printf("Lista este goala\n");
    }
    else
    {
        struct Node *lastNode = head;
        do
        {
            if (lastNode->key == val)
            {
                searchedNode = lastNode;
                return searchedNode;
            }
            lastNode = lastNode->next;
        } while (lastNode->next != NULL);
        if (lastNode->key == val)
        {
            searchedNode = lastNode;
            return searchedNode;
        }
        return NULL;
    }
}

void deleteNodeByKey(int val)
{

    if (head == NULL)
    {
        printf("Lista este goala\n");
    }
    else
    {
        struct Node *temp;
        if (head->key == val)
        {
            temp = head;
            head = head->next;
            free(temp);
            printf("Nodul a fost sters cu succes\n");
        }
        else
        {
            struct Node *currentNode = head;
            while (currentNode->next != NULL)
            {
                if (currentNode->next->key == val)
                {
                    temp = currentNode->next;
                    currentNode->next = currentNode->next->next;
                    free(temp);
                    printf("Nodul a fost sters cu succes\n");
                    break;
                }
                else
                {
                    currentNode = currentNode->next;
                }
            }
        }
    }
}

void printList()
{

    if (head == NULL)
    {
        printf("Lista este goala\n");
    }
    else
    {
        struct Node *lastNode = head;
        do
        {
            printf("key = %d \t next = %d\n", lastNode->key, lastNode->next);
            lastNode = lastNode->next;
        } while (lastNode->next != NULL);
        printf("key = %d \t next = %s\n", lastNode->key, lastNode->next);
    }
}

int main()
{
    addFirst(10);
    addFirst(20);
    addFirst(30);
    addLast(40);
    printList();
    printf("Valoarea 20 cautata este in nodul %d\n", searchByKey(20));
    deleteNodeByKey(20);
    printList();
    printf("Valoarea 10 cautata este in nodul %d\n", searchByKey(10));
    return 0;
}