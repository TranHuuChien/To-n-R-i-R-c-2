#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
vector<int>adj[10];
int parent[10];
bool visited[10];
vector<int>path;
void dfs(int u)
{
    visited[u] = true;
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            parent[v] = u;//danh dau dinh truoc cua v la dinh u 
            dfs(v);
        }
    }
}
void bfs(int u)
{
    queue<int>q;
    q.push(u);
    visited[u] = true;
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        for(int x :adj[v])
        {
            if(!visited[x])
            {
                q.push(x);
                parent[x] = v;
                visited[x] = true;
            }
        }
    }
}
void Path(int s, int t)
{
    memset(visited,false,sizeof(visited));
    memset(parent,0,sizeof(parent));
    bfs(s);// tim thanh phan lien thong tu dinh s
    if(!visited[t])//khong co duong di tu s -->t
    {
        cout<<"khong co duong di!\n";
    }
    else{
        while(t!=s)// di nguoc tu dinh t
        {
            path.push_back(t);
            t =parent[t];// lat nguoc lai
        }
        path.push_back(s);
        reverse(path.begin(),path.end());
    }
    for(int x : path)
    {
        cout<<x<<" ";
    }
}

int main()
{
    cin>>n>>m>>s>>t;
    while(m--)
    {
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    Path(s,t);
    return 0;
    
}

//input
// 10 8 1 7
// 1 2 
// 2 3
// 3 6
// 3 7
// 6 7
// 5 8
// 8 9
// 2 4
//output dfs
// 1 2 3 6 7
// output bfs