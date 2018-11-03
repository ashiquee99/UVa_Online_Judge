    #include <bits/stdc++.h>
    using namespace std;
    typedef                long long int ll;
    #define                MX 1000006
    #define                FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL)
    #define                exit() return 0;
     
    using namespace std;
     
    int f[MX];//the failure array
    int ok;
    void failure_function(string& pattern)
    {
        f[0] = 0;
        int k = 1, len = 0, len_p = pattern.size();
     
        while (k < len_p)
        {
            if (pattern[k] == pattern[len])
            {
                len++;
                f[k] = len;
                k++;
            }
            else
            {
                if (len)//here len is non zero
                {
                    len = f[len - 1];
                }
                else
                {
                    f[k++] = 0;
                }
            }
     
        }
        return;
    }
     
    void KMP_match(string& txt, string& pattern)
    {
        int i = 0, j = 0, ret = -1;
        int len_t = txt.size(), len_p = pattern.size();
     
        while (i < len_t)
        {
            if (txt[i] == pattern[j])
            {
                i++;
                j++;
                ok = j;
                if (j == len_p)
                {
                    ret = i - len_p;
                    // printf("A match found from index %d\n", ret);
                    j = f[j - 1];
                }
            }
            else
            {
                if (j)
                {
                    j = f[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
    }
     
    bool chkpal(string STR)
    {
        string REV = STR;
        reverse(STR.begin(), STR.end());
        if(STR == REV)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
     
    int main()
    {
        string S;
        while (cin>>S)
        {
            if(chkpal(S))
            {
                cout<<S<<endl;
            }
            else
            {
                string PT = S;
                reverse(PT.begin(), PT.end());
                failure_function(PT);
                KMP_match(S, PT);
                cout<<S;
                int vv = S.size() - ok;
                for(int i = vv-1; i>=0; i--)
                {
                    cout<<S[i];
                }
                cout<<endl;
            }
        }
    }
     
