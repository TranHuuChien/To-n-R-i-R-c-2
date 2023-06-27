#include<iostream>
#include<fstream>
using namespace std;
int a[10][10]={0};
void BieudienMaTranke(ifstream &in, ofstream &out)
{
    
    int n,m; in>>n>>m;
    for(int i = 0 ; i < m; i++)
    {
        int x,y;
        in>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }
    for(int i = 1 ; i <=n ; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            out<<a[i][j]<<" ";
        }
        out<<endl;
    }
    for(int i = 1 ; i <=n ; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    ifstream in;
    ofstream out;
    in.open("input.txt",ios::in);
    out.open("output.txt",ios::out);
    BieudienMaTranke(in, out);
    in.close();
    out.close();
}