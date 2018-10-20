#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll a, b;
    while(1)
    {
        cin>>a>>b;
        if(a == 0 && b == 0)
        {
            break;
        }
        ll rem, REM;
        vector <ll> v1, v2;
        while(a!=0)
        {
            rem = a % 10;
            v1.push_back(rem);
            a/=10;
        }
        while(b!=0)
        {
            REM = b % 10;
            v2.push_back(REM);
            b/=10;
        }
        if(v1.size()>v2.size())
        {
            ll vv = v1.size()-v2.size();
            for(ll x = 0; x<vv; x++)
            {
                v2.push_back(0);
            }
        }
        if(v1.size()<v2.size())
        {
            ll vv = v2.size()-v1.size();
            for(ll x = 0; x<vv; x++)
            {
                v1.push_back(0);
            }
        }
        ll cnt = 0, res;
        bool flag = false;
        for(ll i = 0; i<v1.size(); i++)
        {
            res = v1[i] + v2[i];

            if(flag)
            {
                res++;
            }
            if(res>=10)
            {
                cnt++;
                flag = true;
            }
            else
            {
                flag = false;
            }
        }
        if(cnt==0)cout<<"No carry operation."<<endl;
        else if(cnt == 1)cout<<"1 carry operation."<<endl;
        else cout<<cnt<<" carry operations."<<endl;
    }

    return 0;
}
