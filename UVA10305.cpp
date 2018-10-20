#include <bits/stdc++.h>
using namespace std;
#define mx 1005
#define pb push_back
vector <int> g[mx];
vector <int> vec;
bool vis[mx];
void topo(int u)
{
    vis[u] = true;
    for(int i =0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if(!vis[v])
        {
            topo(v);
        }
    }
    vec.push_back(u);
}
void Clear()
{
    for(int i = 0; i<mx; i++)
    {
        g[i].clear();
    }
    memset(vis, 0, sizeof(vis));
    vec.clear();

}
int main ()
{
    int n, m, u, v;
    while(1)
    {
        Clear();
        cin>>n>>m;
        if(n == 0 && m == 0)
        {
            break;
        }
        for(int i = 0; i<m; i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
        }
        for(int i = 1; i<=n; i++)
        {
            if(!vis[i])
            {
                topo(i);
            }
        }

        for(int i = vec.size()-1; i>=0; i--)
        {
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
