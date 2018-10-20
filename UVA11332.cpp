#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    ll n;
    while(1){
    cin>>n;
    if(n == 0)break;
    ll sum = 0, rem;
    while(n!=0)
    {
        rem = n % 10;
        sum+=rem;
        n/=10;
        if(n == 0)
        {
            if(sum>=10)
            {
                n = sum;
                sum = 0;
            }
            else
            {
                cout<<sum<<endl;
                break;
            }
        }
    }
    }
    return 0;
}
