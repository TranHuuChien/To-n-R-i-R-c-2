#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int max = 10;
int n,m;// đinh va canh
vector<int>adj[10];
bool visited[10];
int dem = 0;
void dfs(int u)
{
    cout<<u <<"  ";
    visited[u] = true;
    dem++;
    for(int x : adj[u])
    {
        if(!visited[x]) dfs(x);
    }
}
void connectedComponent()
{
    int ans = 0;
    memset(visited,false,sizeof(visited));
    for(int i = 1 ; i <= n;i++)
    {
        if(!visited[i])
        {
            ++ans;
            cout<<"so thanh phan lien thong : "<<ans<<" :\n ";
            dfs(i);
            cout<<"\nso luong  "<<dem;
        }
        dem=0;
    }
    cout<<"so thanh phan lien thong cua do thi : "<<ans;
}
int main()
{
    cin>>n>>m;
    while(m--)
    {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    connectedComponent();
    system("pause");
    return 0;
}
// 10 8
// 1 2
// 2 3
// 2 4
// 3 6
// 6 7
// 3 7
// 5 8
// 8 9