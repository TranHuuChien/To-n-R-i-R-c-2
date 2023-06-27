#include <stdio.h>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

vector<int> a[10];
bool visit[10]={false};
int d[10]; //one-based
int n, m;
// 5 7
// 1 2
// 1 3
// 2 3
// 2 4
// 2 5
// 3 4
// 4 5 
//    i :   1,  2,  3,  4,  5,
// d[i] :   1,  2,  2,  3,  3,
// số đường đi đến điểm chính từ điểm kia
// 1.Select the root of the graph.
// 2.Insert the root vertex into the queue.
// 3.Pop a vertex from the queue, mark it as visited, and output its value.
// 4.Visit its unvisited neighbor vertex, push them to the queue, and mark visited.
// 5.Repeat step 3 until the queue is empty.
// 6.When the queue is empty, end the program.
void bfs() {
    // duyet thao chieu sau dong thoi dem so bac cua dinh 
    int u, i, v;
    queue<int> qu;
    qu.push(1);
    d[1] = 1;

    while (qu.size()) {
        u = qu.front();
        qu.pop();

        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i];
            if (d[v] == 0) {
                d[v] = d[u] + 1;
                qu.push(v);
            }
        }
    }
}
void BFS(int u)
{
    queue<int>q;
    q.push(u);
    visit[u] = true;
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        for(int i = 0 ; i < a[v].size(); i++)
        {
            if(!visit[a[v][i]])
            {
                visit[a[v][i]] = true;
                q.push(a[v][i]);
            }
        }
    }
}
int main() {
    vector<int>a[10];// a[i] sẻ lưu danh sách kề cùa đỉnh i
    int n, m;
    cin>>n>>m;
    for(int i = 0 ; i < m ; i++)
    {
        int x, y; cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i = 1; i <= n ; i++)
    {
        cout<<"thu tu dinh "<<i<<" : ";
        for(int x : a[i]) cout<<x<<"  ";
        cout<<endl;
    }
    // scanf("%d%d", &n, &m);
    // while (m--) {
    //     int p, q;
    //     scanf("%d%d", &p, &q);
    //     a[p].push_back(q);
    //     a[q].push_back(p); // remove it in one-directional graph
    // }
    
    // bfs();
    // printf("   i : ");
    // for (int i = 1; i <= n; i++)
    //     printf("%3d,", i);
    // printf("\n");
    // printf("d[i] : ");
    // for (int i = 1; i <= n; i++)
    //     printf("%3d,", d[i]);
    // printf("\n");
}

// 9 9
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 3 9
// 8 9
//    i :   1,  2,  3,  4,  5,  6,  7,  8,  9,
// d[i] :   1,  2,  2,  3,  2,  3,  3,  3,  3,