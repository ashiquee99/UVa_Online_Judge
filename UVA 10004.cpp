#include <bits/stdc++.h>
using namespace std;
#define SIZE 1005
#define MX 100000000
vector <int> G[SIZE];
int bicolor[SIZE];
bool BFS(int source)
{
    queue <int> Q;
    Q.push(source);
    memset(bicolor, 0, sizeof(bicolor));
    bicolor[source] = 1;
    while(Q.size()!=0)
    {
        int u = Q.front();
        Q.pop();
        for(int v = 0; v<G[u].size(); v++)
        {
            int curr = G[u][v];
            if(bicolor[curr] == 0)
            {
                Q.push(curr);
                if(bicolor[u] == 1)
                {
                    bicolor[curr] = 2;
                }
                else
                {
                    bicolor[curr] = 1;
                }
            }
            if(bicolor[u] == bicolor[curr])
            {
                return false;
            }
        }
    }
    return true;
}

void Clear()
{
    for(int i=0; i<SIZE; i++) G[i].clear();
}

int main()
{
    int n, u, v, m;
    while(1)
    {
        Clear();
        cin>>n;
        if(n == 0)break;
        cin>>m;
        for(int i = 0; i<m; i++)
        {
            cin>>u>>v;
            G[u+1].push_back(v+1);
            G[v+1].push_back(u+1);
        }
        BFS(1);
        if(BFS(1))
        {
            cout<<"BICOLORABLE."<<endl;
        }
        else
        {
            cout<<"NOT BICOLORABLE."<<endl;
        }
    }

    return 0;
}
