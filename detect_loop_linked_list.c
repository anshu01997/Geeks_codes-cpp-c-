//FASTEST METHOD (FLOYD'S CYCLE FINDING ALGORITHM)    O(N)
#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node *next;
};
void push(struct Node **head_ref,int new_data)
{
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}
int detect_loop(struct Node *head)
{
  struct Node * slow_ptr = head, *fast_ptr = head;
  while(slow_ptr && fast_ptr && fast_ptr->next)
  {
    slow_ptr = slow_ptr->next;
    fast_ptr = fast_ptr->next->next;
    if(slow_ptr == fast_ptr)
    {
      printf("found loop");
      return 1;
    }
  }
  return 0;
}
int main()
{
  struct Node *head = NULL;
  push(&head,20);
  push(&head,5);
  push(&head,15);
  push(&head,21);
  head->next->next->next->next=head;
  detect_loop(head);
  return 0;
}
