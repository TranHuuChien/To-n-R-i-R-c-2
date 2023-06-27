#include<bits/stdc++.h>
using namespace std;
int n,m, s,t;
char a[100][100];
bool visited[100][100];

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int cnt = 0; // đếm số thành phần liên thông trên lưới
bool dfs(int i , int j)
{
    if(a[i][j]=='B')
    return true;
    a[i][j] ='x';//khong co duong di
    cout<<endl<<i<<" "<<j;
    for(int k = 0 ; k < 4;k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        // dieu kien de no phai nam tren luoi va cai ô đấy đã được thăm
        if(i1 >=1 && i1 <= n && j1 >= 1&& j1<=m && a[i1][j1] !='x')
        {
            if(dfs(i1,j1));
            return true;
        }
    }
    return false;
}
void inp()
{

    cin>>n>>m;
    for(int i = 1; i <=n;i++)
    {
        for(int j = 1; j <= m ;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='A')// diem bat dau cua duong di
            {
                s = i; t = j;
            }
            // else if(a[i][j]=='B')
            // {
            //     x2 = i;
            //     y2 = j;
            // }
        }
    }
    if(dfs(s,t))
    {
        cout<<"YES\n";
    }
    else
    cout<<"NO\n";
    
}

int main()
{
     inp();
     return 0;
}
//input
// 6 6
// Aooxoo
// oxoooo
// oxoooo
// ooooxx 
// Boooxo
// oooxxx
//output
// 1 1
// 1 2
// 1 3
// 2 3
// 2 4
// 2 5
// 1 5
// 1 6
// 2 6
// 3 6
// 3 5
// 3 4
// 3 3
// 4 3
// 4 2
// 4 1
// 3 1
// 2 1
// YES