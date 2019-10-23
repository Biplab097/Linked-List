#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef enum {
    true = ~0,
    false = 0
} bool;

Node* addNew(int data,Node* head){
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* last = head;//to use in adding in last of linked list
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL){
      head =  newNode;
    return head;
    }
    while(last->next!=NULL)
      last=last->next;
    last->next=newNode; 
    return head; 
}
bool detect_loop(Node* head){
    Node* slow_p=head;
    Node* fast_p=head;
    //printf("%p ",head);
    while(slow_p && fast_p && fast_p->next){
        slow_p=slow_p->next;
        fast_p=fast_p->next->next;
        if(slow_p==fast_p)
        return true;
    }
    return false;
}
void begginingLoop(Node* head)
{
    Node* slow_p=head;
    Node* fast_p=head;
    if(!head || !(head->next))
      return;
    while(slow_p && fast_p && fast_p->next){
        slow_p=slow_p->next;
        fast_p=fast_p->next->next;
        if(slow_p==fast_p)
        break;
    }  
    if(slow_p!=fast_p){
    printf("no loop exist");return;
    }
    slow_p=head;
    while(slow_p!=fast_p){
        slow_p=slow_p->next;
        fast_p=fast_p->next;

    }
    printf("\nFirst loop element: %d",slow_p->data);
}
void removing_loop(Node* head)
{
    Node* slow_p=head;
    Node* fast_p=head;
    if(!head || !(head->next))
      return;
    while(slow_p && fast_p && fast_p->next){
        slow_p=slow_p->next;
        fast_p=fast_p->next->next;
        if(slow_p==fast_p)
        break;
    }  
    if(slow_p!=fast_p){
    printf("no loop exist");return;
    }
    slow_p=head;
    while(slow_p->next!=fast_p->next){
        slow_p=slow_p->next;
        fast_p=fast_p->next;

    }
    fast_p->next=NULL;
    
}
void create_loop(Node* head)
{
    Node* curr=head;
    while ((curr->next)){
        curr=curr->next;

    }
    curr->next=head->next;
 
}
Node* reverse(Node* head)
{
    Node* prev=NULL;
    Node* next=NULL;
    Node* curr=head;
      
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
  
    return head;

}
int main()
{
    //FILE *r;
    //r = fopen("loop.txt","r");
    Node* head = NULL;
    head = addNew(6,head);
    head = addNew(98,head);
    head = addNew(16,head);
    head = addNew(8,head);
    Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d => ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
    //head=reverse(head);
    printf("\nreverser list\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d => ",temp->data);
        temp = temp->next;
    }
     printf("NULL\n");
     //printf("%d ",head->data);
     //head->next->next->next=head->next;
     create_loop(head);
     if(detect_loop(head))
     printf("loop exist\n");
     else printf("loop doesn't exist");
     begginingLoop(head);
     removing_loop(head);
     if(detect_loop(head))
     printf("\nloop exist after removing\n");
     else printf("\nloop doesn't exist after removing");

    

}