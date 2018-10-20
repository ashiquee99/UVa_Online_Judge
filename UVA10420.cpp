#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        string s1, s2;
        map<string, int>mp;
        map<string, int>::iterator it;
        for(int i = 0; i<n; i++)
        {
            cin>>s1;
            getline(cin, s2);
            mp[s1]++;
        }
        for(it = mp.begin(); it!=mp.end(); it++)
        {
           cout<<it->first<<" "<<it->second<<endl;
        }
    }
    return 0;
}
