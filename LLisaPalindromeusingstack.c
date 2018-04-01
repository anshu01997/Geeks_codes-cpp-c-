#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node *next;
};
void lengthll(struct Node *head)
{
  int len=0;
  struct Node *temp=head;
  while(temp != NULL)
  {
    temp=temp->next;
    len++;
  }
}

void push(char);
char pop();

char stack[100];
int top = -1;

void main()
{
  struct Node *head=NULL;
    //char str[100];
    //int i, count = 0, len;

    printf("Enter string to check it is palindrome or not : ");
    scanf("%d", head);

  //  len = strlen(str);

    for (i = 0; i < len; i++)
    {
        push(&head);
    }

    for (i = 0; i < len; i++)
    {
        if (head == pop())
            count++;
    }

    if (count == len)
        printf("%d is a Palindrome ll\n", head);
    else
        printf("%d is not a palindrome ll\n", head);
}

/* Function to push character into stack */
void push(struct Node *head)
{
    stack[++top] = head;
}

/* Function to pop the top character from stack */
char pop()
{
    return(stack[top--]);
}
/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of the Node is
struct Node
{
    int data;
    struct Node* next;
};*/
/*You are required to complete this method
bool isPalindrome(Node *head)
{
    //Your code here
    int flag,f;
   struct Node* head1,current;
    struct Node* point = head;
    struct Node* prev=NULL;
    head1->next = NULL;
    while(point!=NULL)
    {

        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node*));

       newnode->data = point->data;
        newnode->next = head1;
        head1=newnode;

       point = point->next;


    }

    while(head1!=NULL && head!=NULL)
    {
        if(head->data==head1->data)
        {

            head = head->next;
            head1 = head1->next;


        }

        else
        {
            return 0;
        }

    }
   return 1;
}*/
#include<stack>

bool isPalindrome(Node *head)

{

stack <Node*> reverse;

struct Node* temp=head;

while(temp)

{

reverse.push(temp);

temp=temp->next;

}

temp=head;

while(temp)

{

if(reverse.top()->data!=temp->data)

return false;

reverse.pop();

temp=temp->next;

}

return true;

}