#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
#include<vector>
using namespace std;
struct btree{
    int data=0;
    btree *lchild=NULL,*rchild=NULL;
};
int Data=1;
void randomcreate(btree *p,int level)
{
    if(level==5)
        return;
    if(p==NULL)
        p=new btree;
    int flag=rand()%3;
    if(flag==0)
    {
        p->lchild=new btree;
        randomcreate(p->lchild,level+1);
        p->lchild->data=Data++;
    }
    else if(flag==1)
    {
        p->rchild=new btree;
        randomcreate(p->rchild,level+1);
        p->rchild->data=Data++;
    }
    else if(flag==2)
    {
        p->lchild=new btree;
        randomcreate(p->lchild,level+1);
        p->rchild=new btree;
        randomcreate(p->rchild,level+1);
        p->lchild->data=Data++;
        p->rchild->data=Data++;
    }
}
void printtree(btree *p,int level){
    if(p==NULL)
        return;
    printtree(p->lchild,level+1);
    for(int i=0;i<level-1;i++)
        cout<<"    ";
    cout<<p->data<<endl;
    //printf("L=%p R=%p Data=%d\n",p->lchild,p->rchild,p->data);
    printtree(p->rchild,level+1);
}
void printall(btree *p)
{
    vector<btree*> q;
    q.push_back(p);
    while(!q.empty())
    {
        btree *t=q.front();
        q.erase(q.begin());
        
        cout<<t->data<<" ";

        if(t->lchild!=NULL)
            q.push_back(t->lchild);
        if(t->rchild!=NULL)
            q.push_back(t->rchild);
    }
    cout<<endl;
}
int main()
{
    srand(time(0));
    btree *tree=new btree;
    randomcreate(tree,0);
    cout<<"从左到右输出:"<<endl;
    printtree(tree,1);
    cout<<"层次遍历:"<<endl;
    printall(tree);
    //printf("L=%p R=%p Data=%d",tree->lchild,tree->rchild,tree->data);
    return 0;
}