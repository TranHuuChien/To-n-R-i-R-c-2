#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define N 10
vector<int>vt[N];
int cnt, n, m;
bool visit[N]={false};
bool Visited[N],parent[N];
void inf()
{
     cin>>n>>m;
    for(int i = 0 ; i < m; i++)
    {
        int x, y; cin>>x>>y;
        vt[x].push_back(y);
        vt[y].push_back(x);
    }
}
void dfs1(int u)
{
    cout<<u<<"  ";
    Visited[u]=++cnt;
    for(int i = 0 ; i < vt[u].size();i++)
    {
        int v = vt[u][i];
        if(v != parent[u])// kiem tra xem da duoc tham chua
        {
            if(!Visited[v])
            {
                parent[v] = u;
                dfs1(v);
            }
        }
    }
}
/*void DFSStack(int u)
{
    stack<int>st;
    st.push(u);
    visit[u] = true;
    while(!st.empty())
    {
        int v = st.top(); st.pop();
        for(int i = 0 ; i < vt[v].size();i++)
        {
            if(!visit[v][i])
            {
                visit[v][i]= true;
                st.push(visit[v][i]);
            }
        }
    }
}*/
void DFS(int u)
{
    cout<<u<<" ";
    visit[u] = true;
    for(int i = 0 ; i < vt[u].size();i++)
    {
        if(!visit[vt[u][i]])
        {
            visit[vt[u][i]]= true;
            DFS(vt[u][i]);
        }
    }
}

int main()
{
    inf();
    dfs1(1);
    return 0;
}
//Input
// 9 9
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 3 9
// 5 8
// 8 9