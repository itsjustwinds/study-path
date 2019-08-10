#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    freopen("D:\\C++\\TST\\w33b.inp","r",stdin);
    freopen("D:\\C++\\TST\\w33b.ans","w",stdout);
    int test;
    string s;
    cin>>test;
    while (test--)
    {
        cin>>s;
        bool a0 = false;
        bool a1 = false;
        int cnt = 0;
        for (int i = 0; i<(int) s.size(); i++)
        {
            char x=s[i];
            if (s[i] == '1')
            {
                if (a0) cnt++;
                a1 = true;
                a0 = false;
            }
            else
            {
                if (s[i] == '0')
                {
                    if (a1) a0 = true;
                }
                else
                {
                    a1 = false;
                    a0 = false;
                }
            }

        }
        cout<<cnt<<endl;
    }
    return 0;
}
