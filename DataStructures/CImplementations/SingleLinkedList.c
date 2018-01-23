#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *head;          // head pointer holds the address of the first node

int addNode(int data)
{
    struct node *newnode, *temp;
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=data;
    if( head == NULL) {
        head = newnode;
    } else {
        temp = head;
    while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    return 1;
}

void display() {
    struct node *temp;
    temp = head;
    if (head != NULL) {
        for(temp = head; temp != NULL; temp = temp->next)
        {
            printf("%i", temp->data);
        }
    } else {
        printf("List Empty");
    }
}


int main()
{
    head = NULL;
    addNode(1);
    addNode(2);
    addNode(3);
    display();
}


