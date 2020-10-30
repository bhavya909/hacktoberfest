#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};

getnode()
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    return p;

}
InsBeg(struct node **list,int x)
{
    struct node *temp;
    temp=getnode();
    temp->info=x;
    temp->next=*list;
    *list =temp;

}
Intersection(struct node *list1,struct node *list2)
{
    struct node *list3=NULL;
    struct node *p,*q;
    p=list1;
    q=list2;

    while(p!=NULL && q!=NULL)
    {
        if(p->info<q->info)
        {
            p=p->next;
        }
        else if(p->info == q->info)
        {
            Insend(&list3,p->info);
            p=p->next;
            q=q->next;
        }

        else
        {
            q=q->next;
        }

    }

    return list3;
}
Insend(struct node **list,int x)
{
    struct node *p,*temp;
    temp=*list;
    if(*list==NULL)
    {
        InsBeg(&(*list),x);
    }
    else
    {while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    p=getnode();
    p->info=x;
    p->next=NULL;
    temp->next =p;
    }
}

Traverse(struct node *list)
{
    struct node *t;
    t=list;
    while(t!=NULL)
    {
        printf("%d\t",t->info);

        t=t->next;
    }


}
void main()
{
    struct node *START1,*START2,*START3;
    START1=NULL;
    START2=NULL;
    START3=NULL;
    int x;

    InsBeg(&START1,50);
    InsBeg(&START1,40);
    InsBeg(&START1,30);
    InsBeg(&START1,25);
    InsBeg(&START1,10);
    InsBeg(&START1,5);

    InsBeg(&START2,45);
    InsBeg(&START2,40);
    InsBeg(&START2,25);
    InsBeg(&START2,15);
    InsBeg(&START2,5);

    Traverse(START1);
    printf("\n");

    Traverse(START2);
    printf("\n");

    START3=Intersection(START1,START2);
    printf("\n\n");
    Traverse(START3);
}
