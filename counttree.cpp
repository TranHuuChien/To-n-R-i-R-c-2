#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<int>vt[], int u , int v)
{
    vt[u].push_back(v);
    vt[v].push_back(u);
}
void DFSCount(vector<int>vt[], vector<bool>visited, int u)
{
    visited[u] = true;
    for(int i = 0 ; i < vt[u].size(); i++)
    {
        int k = vt[u][i];
        if(visited[k]==false)
        {
            DFSCount(vt,visited,k);
        }
    }
}
void countTree(vector<int>vt[], int dinh)
{
    int cnt = 0;
    vector<bool>visited;
    for(int i = 0 ; i < dinh; i++)
    {
        if(!visited[i])
        {
            DFSCount(vt,visited,i);
            cnt++;
        }
    }
}
int main()
{
    
    countTree(vt,1);
}