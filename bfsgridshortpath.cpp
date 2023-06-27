#include<iostream>
#include<cstring>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[100][100];
bool visited[100][100];

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int cnt = 0; // đếm số thành phần liên thông trên lưới
void dfs(int i , int j)
{
    visited[i][j] = true;
    cout<<endl<<i<<"  "<<j;
    for(int k = 0 ; k < 4;k++)
    {
        int i1 = i + dx[k];
        int y1 = j + dy[k];
        // dieu kien de no phai nam tren luoi va cai ô đấy đã được thăm
        if(i1 >=1 && i1 <= n && y1 >= 1&& y1<=m && a[i1][y1] =='x' && !visited[i1][y1])
        {
            dfs(i1,y1);
        }
    }
}
void bfs(int i , int j)
{
	a[i][j] = 'o';
	queue<pair<int,int>>q;
	q.push({i,j});
    while(!q.empty())
    {
        pair<int,int> top = q.front(); q.pop();
        for(int k = 0 ; k < 4 ;k++)// so sanh voi 2 mang dx va dy
        {
            int i1 = top.first + dx[k];
            int y1= top.second + dy[k];
            if(i1 >=1 && i1 <= n && y1 >= 1&& y1<= m && a[i1][y1]=='x')
            {
                q.push({i1,y1});
                a[i1][y1] ='o';
            }
        }
    }
}
void inp()
{

    cin>>n>>m;
    for(int i = 1; i <=n;i++)
    {
        for(int j = 1; j <= m ;j++)
        {
            cin>>a[i][j];
        }
    }
    memset(visited,false,sizeof(visited));
    for(int i = 1 ; i <= n; i++)
    {
        for(int j = 1 ; j <=m; j++)
        {
            if(a[i][j]=='x' && !visited[i][j])
            {
                bfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt;
}
// 6 6
// xxxooo
// ooxooo
// oxxxxo
// ooooox
// xxoxox
// xoxxox
// 4
int main()
{
    inp();
    return 0;
}