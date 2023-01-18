//USING C++ for kruskal 
//tried to identify the cycles in directed graph with vector in c++ but couldn't get the desired output 
//this code wouldn't give correct results in all the grpahs with negative weights and directed edges.
//a negative weight is changed by multipying 4 times with itself and adding 1000 to it as penalty

#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstring>
#include <bits/stdc++.h>
#inlcude<sstream>
using namespace std;
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
    int n,min=0,minInd,edges,cost=0,n1,n2,w,ind=0,check[n+1],res[n+1];
    vector<string>vec;
    cout << "enter no of vertices: ";
    cin >> n;
    for(int i=0;i<n+1;i++)
    {
        check[i]=0;
    }
    cout <<"enter no of edges: ";
    cin >> edges;
    struct node*arr[edges+1];
    arr[0]=0;
    for(int i=1;i<edges+1;i++)
    {
        cout << "enter two nodes to establish edge and enter weight : ";
        cin >> n1;
        cin >> n2;
        cin >> w;
        stringstream stream;
        stream << n1;
        string str1;
        stream >> str1;
        stringstream stream;
        stream << n2;
        string str2;
        stream >> str2;
        if(w<0)
        {
        w=(w*w*w*w)+1000;
        }
        struct node* N=(struct node*)malloc(sizeof(struct node));
        N->n1=n1;
        N->n2=n2;
        N->wei=w;
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
    cout << " cost is:" << cost;
}
