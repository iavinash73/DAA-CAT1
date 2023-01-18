//noraml prims code for undirected postive weighted graph.
//this doesn't wrk for general case in directed negative weighted graph beacuse the edges with least cost sould be traced back but it's not possible in diretced graohs. 
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int val;
    int wei;
    struct node *next;
}*newN,*temp,*N,*Min,*t1,*t2,*t3=0,*m1,*m2;
int l=0,min;
struct node* newnode() 
{
    newN=malloc(sizeof(struct node));
    return newN;
};
void addEdge(struct node*arr[],int n1,int n2,int w)
{
    N=newnode();
    if(arr[n1]==0)
    {
        arr[n1]=N;
        arr[n1]->val=n2;
        arr[n1]->wei=w;
    }
    else
    {
        temp=arr[n1];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=N;
        temp->next->val=n2;
        temp->next->wei=w;
    }
    if(l==0)
    {
        l=w;
        Min=N;
    }
    else if(l>w)
    {
        l=w;
        Min=N;
    }
}
void addEdges(struct node*arr[],int n1,int n2,int w)
{
    addEdge(arr,n1,n2,w);
    addEdge(arr,n2,n1,w);
}
struct node * findNode(struct node*arr[],int n,int w)
{
    temp=arr[n];
    while(temp!=NULL)
    {
        if(temp->wei==w)
        {
            break;
        }
        temp=temp->next;
    }
    return temp;
}
struct node* findNext(struct node* arr[],int n,int check[])
{
    temp=arr[n];
    t3=0;
    min=0;
    while(temp!=NULL)
    {
        if(min==0&&check[temp->val]!=1)
        {
            min=temp->wei;
            t3=temp;
        }
        else if(min>temp->wei&&check[temp->val]!=1)
        {
            min=temp->wei;
            t3=temp;
        }
        temp=temp->next;
    }
    return t3;
}
int main()
{
    int n;
    printf("enter no of vertices: ");
    scanf("%d",&n);
    struct node*arr[n];
    int res[n*2],check[n],ind=0,e=0;
    for(int i=0;i<n;i++)
    {
        arr[i]=0;
        check[i]=0;
    } 
    int edges,n1,n2,w,cost=0;
    printf("enter no of edges: ");
    scanf("%d",&edges);
    while(edges--)
    {
        printf("enter two nodes to establish edge: ");
        scanf("%d %d",&n1,&n2);
        printf("enter weight: ");
        scanf("%d",&w);
        n1--;
        n2--;
        addEdges(arr,n1,n2,w); 
    }
    t1=Min;
    t2=findNode(arr,Min->val,l);
    res[ind++]=t1->val+1;
    res[ind++]=t2->val+1;
    check[t1->val]=1;
    check[t2->val]=1;
    cost+=t1->wei;
    while(ind!=n)
    {
        m1=findNext(arr,t1->val,check);
        m2=findNext(arr,t2->val,check);
        if(m2==0 ||m1->wei<m2->wei)
        {
            res[ind++]=m1->val+1;
            check[m1->val]=1;
            cost+=m1->wei;
            t1=m1;
        }
        else if(m1==0 ||m1->wei>m2->wei)
        {
            res[ind++]=m2->val+1;
            check[m2->val]=1;
            cost+=m2->wei;
            t2=m2;
        }
    } 
    printf(" cost is:%d\n",cost);
    for(int i=0;i<ind;i++)
    {
        printf(" %d",res[i]);
    }
}
