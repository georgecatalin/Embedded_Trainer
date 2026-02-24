#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node 
{
    int data;
    struct node *next;
};

int get_list_length(struct node *head)
{
    int length = 0;

    while(head!=NULL)
    {
        head= head->next;
        length++;
    }

    return length;
}


struct node *get_nth_element(struct node *head, int n)
{
    if(n<0)
        return NULL;

    int index = 0;
    while(head!=NULL && index<n)
    {
        index ++;
        head=head->next;
    }

    return head;
}

void append_element(struct node **headref, int data)
{
    assert(headref!=NULL);

    //Consider the case when the linked list is empty
    if(*headref == NULL)
    {
        //create the first element of the linked list
        *headref = (struct node *) malloc(sizeof(struct node));
        (*headref)->data = data;
        (*headref)->next = NULL;
        return;
    }

    //Traverse the linked list till the last element
    struct node *head = *headref;
    while(head->next != NULL)
    {
        head= head->next;
    }

    //Append a new element at the end
    head->next = (struct node *) malloc(sizeof(struct node));
    head->next->data = data;
    head->next->next = NULL;
}

int pop(struct node **headref)
{
    assert(headref != NULL);

    if(*headref!=NULL)
    {
        printf("Deleting the node with the following data %d.\n", (*headref)->data);
        //store the next element after header in a variable to be used later
        struct node *next = (*headref)->next;

        //store the data to return later
        int data = (*headref)->data;
        //set the header to point to nowhere, thus detaching from the linked list
        (*headref)->next = NULL;
        free(*headref);

        *headref = next;

        return data;
    }
}

int delete_elements_from_list(struct node **headref)
{
    assert(headref!=NULL);

    struct node *head = *headref;
    struct node *next = NULL;

    while (head!=NULL)
    {
        printf("Deleting the element carrying the value %d\n", head->data);
        //store the next element of the current element
        next = head->next;

        head->next = NULL;
        free(head);

        head = next;
    }
    
}

int main(void)
{


    return 0;
}