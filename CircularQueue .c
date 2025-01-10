#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int cqueue_arr[SIZE];
int front=-1;
int rear=-1;
void insert(int item)
{
if((front==0&&rear==SIZE-1)||(front==(rear+1)%SIZE))
{
printf("Queue is full");
return;
}
else
{
if(front==-1)
{
front=0;
}
rear=(rear+1)%SIZE;
cqueue_arr[rear]=item;
printf("%d is inserted \n",item);

} 
}
void deletion()
{
if(front==-1)
{
printf("queue is empty");
return;
}
else
{
printf("%d is deleted from queue\n",cqueue_arr[front]);
if(front==rear)
{
front=-1;
rear=-1;

}
else
{
front=(front+1)%SIZE;
}
}
}
void display()
{
int i;
if(front==-1)
{
printf("queue is empty\n");
return ;
}
else
{
printf("queue element \n");
for(i=front;i!=rear;i=(i+1)%SIZE)
{
printf("%d \t",cqueue_arr[i]);
}
printf("%d ",cqueue_arr[i]);
}
}
int main()
{
int choice,item;
do
{
printf("\n 1.insert \n");
printf("2.delete \n");
printf("3.display\n");
printf("4.exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("input the element for insertion in the queue\n");
	scanf("%d",&item);
	insert(item);
	break;
case 2:deletion();
	break;
case 3:display();
	break;
case 4:exit(0);
	break;
default:printf("wrong choice\n");

}
}
while(choice!=4);
return 0;
}
