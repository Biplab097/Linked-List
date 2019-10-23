#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
   int data;
   struct Node* next;
}Node;
struct Node* reverse(struct Node** head)
{
   Node* prev = NULL;
   Node* curr = *head;
   Node* next = NULL;
   while(curr!=NULL)
   {
    next = curr->next;
    curr->next = prev;
    prev=curr;
    curr = next;
   }
*head = prev;
return *head;
}
struct Node* add(struct Node** head,struct Node** tail,int data)
{  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
   new_node->data=data;
   new_node->next=NULL;
   if((*head)==NULL&&(*tail)==NULL)
   {
   (*head)=new_node;
   (*tail)=new_node;
   return (*head);
   }
   else if((*head)!=NULL&&(*tail)!=NULL){
   (*tail)->next=new_node;
   (*tail)=new_node;
   return (*head);
  }
   (*tail)->next=new_node;
    
   (*tail)=new_node;
   return (*head);
}
int main(int argc,char *argv[])
{
 FILE *r;
 r = fopen(argv[1],"r");
 int t,n,ele;
 fscanf(r,"%d",&t);

 

 while(t--)
 {
  Node* head=NULL;
 Node* tail=NULL;
  fscanf(r,"%d",&n);
  for(int i=0;i<n;i++){
     fscanf(r,"%d",&ele);
     head=add(&head,&tail,ele);
 }
  
  Node* temp=head;
  printf("Original Linked List:");
  while(temp!=NULL)
   {
    printf("%d ",temp->data);
    temp=temp->next;
   }
   printf("\nReversed Linked List:");
    head=reverse(&head);
   temp=head;
   while(temp!=NULL)
   {
    printf("%d ",temp->data);
    temp=temp->next;
   }
  printf("\n");
 }
return 0;
}
