#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=int(1e5+1);
int n,m;ll budget;
int maxWeight=0;

struct Edge
{
    int v,w,c;
};
vector<Edge> G[maxn];

void addEdge(int u,int v,int w,int c)
{
    G[u].push_back({v,w,c});
    G[v].push_back({u,w,c});
    // 顺便确定搜索范围的边界
    maxWeight=max(maxWeight,w);
}

void getData()
{
    cin>>n>>m>>budget;//n个点
    int u,v,w,c;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w>>c;
        if(u==v) continue;
        addEdge(u,v,w,c);
    }
}

int vis[maxn];
ll dis[maxn];
// 检查运输weight能否成功
// Dijkstra算法
bool check(ll weight)
{
    memset(vis,0,sizeof(vis));
    memset(dis,127,sizeof(dis));
    dis[1]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    q.push(make_pair(0,1));

    while(!q.empty())
    {
        int now=q.top().second;
        q.pop();

        if(now==n) break; // 已经到达目标点

        if(vis[now]) continue;
        vis[now]=1;

        if(dis[now]>budget) return false;// 最短路径上的花费大于预算

        for(const Edge& e:G[now])
        {
            if(e.w < weight) continue;// 承重能力弱于给定重量
            if(dis[e.v] > dis[now]+e.c) // 松弛
            {
                dis[e.v]=dis[now]+e.c;
                // cout<<e.v<<" -- "<<dis[e.v]<<endl;
                q.push(make_pair(dis[e.v],e.v));
            }
        }
    }
    return dis[n]<=budget;
}

int main()
{
    getData();
    ll l=0,r=maxWeight;
    while(l+1<r)
    {
        int mid=(l+r)/2;
        if(check(mid)) // 可以尝试更重的
            l=mid;
        else // 应该尝试更轻的
            r=mid-1;
        
        // cout<<l<<" "<<r<<endl;
    }
    cout<<l<<endl;
}