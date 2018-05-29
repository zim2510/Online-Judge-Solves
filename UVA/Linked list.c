#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

typedef struct Node node;

void insert(node * head, int data)
{
    while(head->next!=NULL) head=head->next;
    node * temp = (node*) malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    head->next = temp;
}

void update(node * head, int old, int new)
{
    while(head->data != old) head = head->next;
    head->data = new;
}

void delete(node * head, int data)
{
    node * temp;
    while(1){
        temp = head;
        head = head->next;
        if(head->data == data) break;
    }
    temp->next = head->next;
}

void search(node * head, int data)
{
    int count = 0;
    while(1){
        if(head->data == data){
                printf("FOUND ON NODE %d\n", count);
                return;
        }
        else if(head->next == NULL){
            printf("NOT FOUND\n");
            return;
        }
        count++;
        head = head->next;
    }
}

void print(node * head)
{

    while(1){
        head=head->next;
        printf("%d\n", head->data);
        if(head->next == NULL) return;
    }
}

int main()
{
    node* head = (node*) malloc(sizeof(node));
    head->next = NULL;
    insert(head, 10);
    insert(head, 12);
    search(head, 10);
    insert(head, 41);
    print(head);
    update(head, 12, 0);
    print(head);
    delete(head, 10);
    search(head, 012);
    print(head);

}
