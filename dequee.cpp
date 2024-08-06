int dequeue(struct cllqueue **last)
{
int item;
struct cllqueue *temp;
if(*last==NULL)
{
printf("\n Queue is empty");
return -999;
}
else if(*last==(*last)->link)
{
item=(*last)->info;
temp=*last;
*last=NULL;
free(temp);
return item;
}
else
{
temp=(*last)->link;
item=temp->info;
(*last)->link=temp->link;
free(temp);
return item;
}
}
