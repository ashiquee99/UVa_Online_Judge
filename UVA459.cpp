#include <bits/stdc++.h>
using namespace std;
#define SIZE 1005
vector <int> g[SIZE];
bool vis[SIZE];
void dfs(int curr)
{
    vis[curr] = true;
    for(int i = 0; i<g[curr].size(); i++)
    {
        if(!vis[g[curr][i]])
        {
            dfs(g[curr][i]);
        }
    }
}

void Clear()
{
    memset(vis, false, sizeof(vis));
    for(int i=0; i<SIZE; i++) g[i].clear();
}

int main ()
{
    int tc;
    cin>>tc;
    //cout<<endl;
    for(int t = 1; t<=tc; t++)
    {
        //cout<<endl;
        Clear();
        memset(vis, false, sizeof(vis));
        char MXNODE;
        cin>>MXNODE;
        int mxnode = MXNODE - 'A' + 1;
        string s;
        int cnt = 0;
        getchar();
        while(getline(cin, s))
        {
            if(s.size() == 0)
            {
                break;
            }
            int node1, node2;
            node1 = s[0] - 'A' + 1;
            node2 = s[1] - 'A' + 1;
            g[node1].push_back(node2);
            g[node2].push_back(node1);
        }
        for(int i = 1; i<=mxnode; i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i);
            }
        }
        if(t!=1){
        cout<<endl;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
