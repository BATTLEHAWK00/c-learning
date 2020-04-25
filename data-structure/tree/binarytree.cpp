#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>
typedef struct binarytree
{
    int data;
    binarytree *LChild=NULL,*RChild=NULL;
};
void PreOrder(binarytree *root)
{
    if(root==NULL)
        return;
    else
    {
        printf("%d ",root->data);
        PreOrder(root->LChild);
        PreOrder(root->RChild);
    }
}
void MidOrder(binarytree *root)
{
    if(root==NULL)
        return;
    else
    {
        PreOrder(root->LChild);
        printf("%d ",root->data);
        PreOrder(root->RChild);
    }
}
void PostOrder(binarytree *root)
{
    if(root==NULL)
        return;
    else
    {
        PreOrder(root->LChild);
        PreOrder(root->RChild);
        printf("%d ",root->data);
    }
}
void PrintTree(binarytree *root,int layer)
{
    if(root==NULL)
        return;
    int i;
    PrintTree(root->RChild,layer+1);
    for(i=0;i<layer;i++)
        printf("  ");
    printf("%d \n",root->data);
    PrintTree(root->LChild,layer+1);

}
binarytree* CreateTree(int data)
{
    binarytree *temp=(binarytree*)malloc(sizeof(binarytree));
    temp->LChild=NULL;
    temp->RChild=NULL;
    temp->data=data;
    return temp;
}
int nodes=0;
void RandomCreateTree(binarytree *root,int depth)
{
    int n=1;
    srand(time(0));
    if(depth==10)
        return;
    root=CreateTree(nodes++);      
    if(depth==0)
    {
        printf("L ");
        RandomCreateTree(root->LChild,depth+1);
        printf("R ");
        RandomCreateTree(root->RChild,depth+1);
        return;
    }
    if(rand()%2)
    {
        printf("L ");
        RandomCreateTree(root->LChild,depth+1);
    } 
    if(rand()%2)
    {
        printf("R ");
        RandomCreateTree(root->LChild,depth+1);
    }
}
int main()
{
    binarytree *root=NULL;
    RandomCreateTree(root,0);
    printf("\n");
    PrintTree(root,0);
    getchar();
    return 0;
}