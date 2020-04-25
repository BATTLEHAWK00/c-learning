#include<iostream>
#include<cstdio>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;
struct GraphNode
{
    int num;
    int info;
};
void dfs(vector<GraphNode*> & Graph,bool **Edges,int a)
{
    bool *vis=new bool[Graph.size()];
    string res;
    for(int i=0;i<Graph.size();i++)
        vis[i]=false;
    vector<int> stack;
    stack.push_back(a);
    while(!stack.empty())
    {
        int b=stack.back();
        stack.pop_back();
        if(vis[b]==true)
            break;
        vis[b]=true;
        res+=to_string(b)+" -> ";
        //cout<<res<<endl;
        for(int i=Graph.size();i>=0;i--)
            if(Edges[b][i]==1&&vis[i]==false)
                stack.push_back(i);
    }
    cout<<res<<endl;
    //cout<<endl;
}
void bfs(vector<GraphNode*> & Graph,int **Edges,int a)
{
    vector<int> Q;
    
}
int main()
{
    srand(time(0));
    vector<GraphNode*> Graph;
    int n;
    cout<<"输入结点数:";
    cin>>n;
    bool **Edges=new bool*[n];
    for(int i=0;i<n;i++)
        Edges[i]=new bool[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            Edges[i][j]=false;
    for(int i=0;i<n;i++)
        Graph.push_back(new GraphNode);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if(rand()%n<2&&i!=j)
                Edges[i][j]=true;
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<Edges[i][j]<<" ";
        cout<<endl;
    }*/
    /*while(1)
    {
        int a,b;
        cout<<"输入一条边(a,b):";
        scanf("%d,%d",&a,&b);
        Edges[a][b]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<Edges[i][j]<<" ";
            cout<<endl;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(Edges[i][j]==1)
                    printf("<%d,%d> ",i,j);
    }*/
    while(1)
    {
        int a;
        cout<<"输入起始点:";
        cin>>a;
        dfs(Graph,Edges,a);
    }
    getchar();
    return 0;
}
