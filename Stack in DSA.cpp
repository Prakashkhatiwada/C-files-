#include <stdio.h>
struct linkedliststack
{
int info;
struct linkedliststack *link;
};
void push(struct linkedliststack **,int);
int pop(struct linkedliststack **);
void display(struct linkedliststack **);
void main()
{
struct linkedliststack *TOS;
int x;
char ch='y';
int option;
TOS=NULL;
clrscr();
printf("\n What do you want to do?");
printf("\n1.Push");
printf("\n2.Pop");
printf("\n3.Display");
while(ch=='y')
{
printf("\n Enter your option:");
scanf("%d", &option);
switch(option)
{
case 1:
printf("\n Enter item to insert:");
scanf("%d", &x);
push(&TOS, x);
break;
case 2:
x=pop(&TOS);
printf("\n The deleted item is:%d", x);
break;
case 3:
display(&TOS);
break;
default:
printf("\n WRONG OPTION");
}
printf("\n Do you want to continue(y/n)?");
scanf(" %c", &ch);
}
getch();
}
void push(struct linkedliststack **top,int x)
{
struct linkedliststack *node;
node=(struct linkedliststack *)malloc(sizeof(struct linkedliststack));
node->info=x;
node->link=*top;
*top=node;
}
int pop(struct linkedliststack **top)
{
int item;
struct linkedliststack *temp;
if(*top==NULL)
{
printf("\n Stack is empty");
return -999;
}
else
{
item=(*top)->info;
temp=*top;
*top=(*top)->link;
free(temp);
return item;
}
}
void display(struct linkedliststack **top)
{
struct linkedliststack *temp;
if(*top==NULL)
{
printf("\n Stack is empty");
return;
}
else
{
printf("Stack contents are:\n");
temp=*top;
printf("top-->");
while(temp!=NULL)
{
printf("\t%d", temp->info);
printf("\n\t|\n");
printf(“\n\t|\n”);
temp=temp->link;
}
}
}
