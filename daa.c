//noraml c code for kruskal but adding a penalty to make sure that path is not taken into account 
//in the other c++ file i tried to identify the cycles but i couldn't complete it fully within given time.
//this code takes input as undirected graph and works for the given input
//kruskal won't work for directed graph because the cycles can't be detected 

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int n1;
    int n2;
    int wei;
}*N;
int findNext(struct node*arr[],int n)
{
    int min=0,minInd=0;
    for(int i=1;i<n+1;i++)
    {
        if(arr[i]!=NULL)
        {
            if(min==0)
            {
                min=arr[i]->wei;
                minInd=i;
            }
            else if(min>arr[i]->wei)
            {
                min=arr[i]->wei;
                minInd=i;
            }
        }
    } 
    return minInd;
}
int main()
{
    int n,min=0,minInd;
    printf("enter no of vertices: ");
    scanf("%d",&n);
    int check[n+1],res[n+1];
    for(int i=0;i<n+1;i++)
    {
        check[i]=0;
    }
    int edges,cost=0,n1,n2,w,ind=0;
    printf("enter no of edges: ");
    scanf("%d",&edges);
    struct node*arr[edges+1];
    arr[0]=0;
    for(int i=1;i<edges+1;i++)
    {
        printf("enter two nodes to establish edge and enter weight : ");
        scanf("%d %d %d",&n1,&n2,&w);
        N=malloc(sizeof(struct node));
        N->n1=n1;
        N->n2=n2;
        N->wei=w;
        if(w<0)
        {
        w=(w*w*w*w)+1000;
        }
        arr[i]=N;
        if(min==0)
        {
            min=w;
            minInd=i;
        }
        else if(min>w)
        {
            min=w;
            minInd=i;
        }
    }
    res[ind++]=arr[minInd]->n1;
    res[ind++]=arr[minInd]->n2;
    check[arr[minInd]->n1]=1;
    check[arr[minInd]->n2]=1;
    cost+=arr[minInd]->wei;
    arr[minInd]=NULL;
    while(ind!=n)
    {
        minInd=findNext(arr,edges);
        if(check[arr[minInd]->n1]!=1||check[arr[minInd]->n2]!=1)
        {
            if(check[arr[minInd]->n1]!=1)res[ind++]=arr[minInd]->n1;
            if(check[arr[minInd]->n2]!=1)res[ind++]=arr[minInd]->n2;
            check[arr[minInd]->n1]=1;
            check[arr[minInd]->n2]=1;
            cost+=arr[minInd]->wei;
        }
        arr[minInd]=NULL;
    }
    printf(" cost is:%d\n",cost);
    for(int i=0;i<ind;i++)
    {
        printf(" %d",res[i]);
    }
}
