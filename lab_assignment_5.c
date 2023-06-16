#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    int length = 0;
    
    
    while (head != NULL) {
        length++;
        head = head->next;
    }
    
    return length;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
    
    char* string = (char*)malloc((length(head) + 1) * sizeof(char));
    
    int x = 0;
    
    while (head != NULL) {
        string[x] = head->letter;
        x++;
        head = head->next;
    }
    
    return string;
}

//D.R.Y. :)
struct node* allocateNode(char c){
    struct node* newItem = malloc(sizeof(struct node));
    
    newItem->letter = c;
    newItem->next = NULL;
    return newItem;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    
    if((*pHead) == NULL) {
        (*pHead) = allocateNode(c);
        return;
    }

    struct node* head = (*pHead);
    
    
    while (head->next != NULL) {
        head = head->next;
    }
    
    head->next = allocateNode(c);;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    struct node* head = (*pHead);
    
    while (head != NULL) {
        struct node* holder = head;
        head = head->next;
        free(holder);
    }
    
    *pHead = NULL;
    pHead = NULL;
}

int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt","r");

    fscanf(inFile, " %d\n", &numInputs);
    
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is : %s\n", str);

        free(str);
        deleteList(&head);

        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }

    fclose(inFile);
}
