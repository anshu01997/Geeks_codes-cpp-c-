
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};
void push(struct Node **head_ref,int new_data)
{
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

/* Function to remove loop. Used by detectAndRemoveLoop() */
void removeLoop(struct Node *, struct Node *);
int detectAndRemoveLoop(struct Node *list)
{
    struct Node  *slow_p = list, *fast_p = list;

    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;

        /* If slow_p and fast_p meet at some point then there
           is a loop */
        if (slow_p == fast_p)
        {
            removeLoop(slow_p, list);

            /* Return 1 to indicate that loop is found */
            return 1;
        }
    }

    /* Return 0 to indeciate that ther is no loop*/
    return 0;
}
void removeLoop(struct Node *loop_node,struct Node *head)
{
  struct Node *ptr1;
  struct Node *ptr2;
  ptr1 = head;
  while(1)
  {
    ptr2 = loop_node;
    while(ptr2->next != loop_node && ptr2->next != ptr1)
    {
      ptr2=ptr2->next;
      if(ptr2->next == ptr1)
      break;
      ptr1=ptr1->next;
    }

  }
  ptr2->next = NULL;
}
void printlist(struct Node *node)
{
  while(node != NULL)
  {
    printf("%d ",node->data );
    node=node->next;
  }
}
int main()
{
  struct Node *head = NULL;
  push(&head,20);
  push(&head,5);
  push(&head,15);
  push(&head,21);
  head->next->next->next->next=head;
  detectAndRemoveLoop(head);
    printf("Linked List after removing loop \n");
    printList(head);
  return 0;
}
