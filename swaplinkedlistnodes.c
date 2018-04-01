#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};
void swapNodes(struct Node **head_ref,int x,int y)
{
  if(x == y)
    return;
    //search for x and keep track of curr and prev pointers
    struct Node *prevX=NULL, *currentX = *head_ref;

   while(currentX && currentX->data != x)
    {
      prevX = currentX;
      currentX = currentX->next;
    }
    struct Node *prevY=NULL, *currentY= *head_ref;
    while(currentY && currentY->data != y)
    {
      prevY=currentY;
      currentY=currentY->next;
    }
    if(currentX == NULL || currentY == NULL)
      return;
    if(prevX != NULL)
         prevX->next = currentY;
        else
        *head_ref = currentY;
    if(prevY != NULL)
         prevX->next = currentX;
         else
          *head_ref=currentX;
  struct Node *temp = currentY->next;
  currentY->next = currentX->next;
  currentX->next = temp;
    }
void push(struct Node** head_ref,int new_data)
{
  struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}
void printlist(struct Node *node)
{
  while(node!=NULL)
  {
    printf("%d\n",node->data);
    node=node->next;
  }
}
  int main()
  {
    struct Node *start=NULL;
    push(&start,6);
    push(&start,5);
    push(&start,7);
    push(&start,9);
    push(&start,11);
    printf("\n Linked list before calling swapNodes() ");
    printlist(start);
    swapNodes(&start,6,11);
    printf("\n Linked list after calling swapNodes() ");
    printlist(start);
    return 0;
}
