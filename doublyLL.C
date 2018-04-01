#include<stdio.h>
#include<stdlib.h>
//#include<malloc.h>
struct Node{
    int data;
    struct Node*prev;
    struct Node*next;
};
//to insert at the front of the LL
void push(struct Node**head_ref,int new_data) {

  struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));
  new_node->data=new_data;
  new_node->next=(*head_ref);
  new_node->prev=NULL;
  if(*head_ref!=NULL)
    (*head_ref)->prev=new_node;
    (*head_ref)=new_node;
  }
  //insert a node after a given node in a doubly LL
  void insert_after(struct Node**prev_node,int new_data){
    if(prev_node==NULL)
    {
      printf("the given prev node can not be null\n");
      return;
    }
    struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
    (new_node)->data=new_data;
    (new_node)->next=(*prev_node)->next;
    (*prev_node)->next=(new_node);
    (new_node)->prev=(*prev_node);
    if((new_node)->next!=NULL)
       (new_node)->next->prev=(new_node);
  }
  //INSERT AT THE END IN A GVEN LL
  void insert_at_end(struct Node**head_ref,int new_data){
    struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));
    struct Node*last=*head_ref;
    new_node->data=new_data;
    new_node->next=NULL;
    if(*head_ref==NULL)
      new_node->prev=NULL;
      (*head_ref)=new_node;
  while(last->next!=NULL)
    //TRAVERSE THE LIST
    last=last->next;
    last->next=new_node;
    new_node->prev=last;
   return;
  }
  //print the ll
  void printlist(struct Node*n)
  {
    struct Node*last;
      printf("traversal in forward direction:");
      while(n!=NULL)
      {
        printf("%d\n",n->data);
        last=n;
        n=n->next;
      }
      printf("traversal in backwards direction:");
      while(last!=NULL)
      {
        printf("%d\n",last->data);
        last=last->prev;
      }
  }
  int main(void)
  {
    struct Node*head=NULL;
    insert_at_end(&head,6);
    push(&head,7);
    push(&head,1);
    //insert_at_end(&head,2);
    //insert_after(&head->next,8);
    printf("the created DLL is:");
    printlist(head);
    getchar();
    return 0;
  }


  /* code */
