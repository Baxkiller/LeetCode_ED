#include <bits/stdc++.h>
using namespace std;
#define N 1e3
int graph[N][N];

void input()
{
    int n;
    cin>>n;
    if(n>=N) exit(1);
    // 输入默认 a b w
    int a,b,w;
    while(cin>>a>>b>>w)
    {
        graph[a][b]=graph[b][a]=w;
    }
}

void Generating()
{
    // 默认less 大根堆
    // 使用greater 将其更改为小根堆
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    
}

int main()
{
    input();

}