#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
};
struct node* top=NULL;
void push(int value)
{

struct node*newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=value;
if(top==NULL)
{
newnode->next=NULL;

}
else
{
newnode->next=top;
}
top=newnode;
printf("node is inserted\n\n");
}
void pop()
{
if(top==NULL)
{
printf("\n Stack is empty \n");

}
else
{
struct node*temp=top;
int temp_data=top->data;
top=top->next;
free(temp);
printf("the popped element is :%d",temp_data);
}
}
void display()
{
if(top==NULL)
{
printf("\n stack is empty \n");
}
else
{
printf("the stack is :\n");
struct node *temp=top;
while(temp->next!=NULL)
{
printf("%d-->",temp->data);
temp=temp->next;
}
printf("%d-->NULL\n\n",temp->data);
}
}
int main()
{
int choice,value;
printf("\n implementation of stack using linked list\n");
while(1)
{
printf("1.push\n2.pop\n3.display\n4.exit\n");
printf("\n enter your choice ");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("\n enter the value to insert");
	scanf("%d",&value);
	push(value);
	break;
case 2:pop();
	break;
case 3:display();
	break;
case 4:exit(0);
	break;
default:printf("\n invalid choice\n");
}
}
} 


