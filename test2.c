#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
   int data;
   struct Node* next;
}Node;
struct Node* add(struct Node* head,struct Node* tail,int data)
{
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data=data;
  new_node->next=NULL;
  if(head==NULL&&tail==NULL)
  {
   head=new_node;
   tail=new_node;
   return head;
  }
  else if(head==tail&&tail!=NULL){
   tail->next=new_node;
   tail=new_node;
   return head;
  }
  else{
   tail->next=new_node;
   tail=new_node;  
   return head;
  }
return head;
}
int main(int argc[],char const *argv[])
{
  FILE *r;printf("coming");
  //r = fopen(argv[1],"r");
  int t,n,ele;
  //fscanf(r,"%d",&t);
  t = 9;
  n = 0;
  ele =0;
  printf("%d ",t);
  Node* head=NULL;
  Node* tail=NULL;
  while(t--)
  {
   printf("coming");
   //fscanf(r,"%d",&n);
   for(int i = 0;i<n;i++)
   {
    //fscanf(r,"%d",&ele);
    printf("coming");
    head=add(head,tail,ele);
   } 
   while(head->next!=NULL)
   {
    printf("%d \n",head->data);
    head=head->next;
   }
  }
 return 0;
}
