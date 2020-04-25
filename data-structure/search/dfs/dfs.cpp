#include<iostream>
#include<vector>
#include<cstdio>
#include<time.h>
#include<string>
using namespace std;
int cnt=0;
void dfs(vector<char> & a,int level,vector<int> & b,vector<char> & res)
{
    if(level==a.size())
    {
        for(int i=0;i<res.size();i++)
            cout<<res[i]<<" ";
            //printf("%c ",res[i]);
        cout<<endl;
        cnt++;
        
        //printf("\n");
        return;
    }
    for(int i=0;i<a.size();i++)
        if(!b[i])
        {
            res.push_back(a[i]);
            b[i]=1;
            dfs(a,level+1,b,res);
            res.pop_back();
            b[i]=0;
        }
}
int main()
{
    vector<char> a,res;
    vector<int> b;
    register char t;
    time_t start,end;
    cout<<"输入需要全排列的一组数字:"<<endl;
    while(scanf("%c",&t)!=EOF)
        if(t!='\n'&&t!=' ')
            a.push_back(t);
    b.resize(a.size());
    cout<<"排列结果:"<<endl;
    start=clock();
    dfs(a,0,b,res);
    cout<<"CNT="<<cnt<<endl;
    end=clock();
    cout<<"运行时间:"<<double(end-start)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
    printf("按任意键结束...");
    getchar();
    return 0;
}
