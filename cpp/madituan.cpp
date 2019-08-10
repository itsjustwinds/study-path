#include <bits/stdc++.h>

using namespace std;

#define MAXX 65

int A[2][65];
int B[9][9];
int C[] = {1,2,-1,-2,1,2,-1,-2};
int D[] = {2,1,-2,-1,-2,-1,2,1};
int ok;
void ou()
{
    for(int i = 1; i <= 49; i++)
    {
        cout << "(" << A[0][i] << ',' << A[1][i] << ")" << "  ";
    }
}

void Try1(int t)
{
    if (ok==1) return ;
    for(int i = 0; i < 8; i++)
    {
        if (ok==1) return;
        if(A[0][t - 1] + C[i] < 8 && A[0][t - 1] + C[i] > 0 && A[1][t - 1] + D[i] < 8 && A[1][t - 1] + D[i] > 0&&B[A[0][t - 1] + C[i]][A[1][t - 1] + D[i]]==0)
        {
            A[0][t] = C[i] + A[0][t - 1];
            A[1][t] = D[i] + A[1][t - 1];
            //if(B[A[0][t]][A[1][t]]) continue;
            B[A[0][t]][A[1][t]] = 1;
            if(t == 49)
            {
                ou();
                ok=1;
                return;
            }
            else Try1(t + 1);
            B[A[0][t]][A[1][t]] = 0;
        }
    }
}

int main()
{
    //freopen("madituan.inp","r",stdin);
    freopen("madituan.out","w",stdout);
    A[0][1] = 5;
    A[1][1] = 5;
    B[5][5] = 1;
    Try1(2);
    return 0;
}
