#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll rand(int l,int r){
        return l+((ll)rand()*(RAND_MAX+1)*(RAND_MAX+1)*(RAND_MAX+1)+
                  (ll)rand()*(RAND_MAX+1)*(RAND_MAX+1)+
                  (ll)rand()*(RAND_MAX+1)+
                  rand())%(r-l+1);

}
int main(){
    int ttt=100;
    srand(time(NULL));
    for (int iii=1;iii<=ttt;++iii){
        ofstream out ("D:\\c++\\SAFENET2.inp");
        int n,m;
        n=rand(1,10);
        m=rand(1,10);
        out<<n<<" "<<m<<"\n";
        while(m){
            int u=rand(1,n);
            int v=rand(1,n);
            if (v==u) continue;
            m--;
            out<<u<<" "<<v<<"\n";
        }
        out.close();
        system("D:\\c++\\SAFENET2.exe");
        system("D:\\c++\\SAFENET2_trau.exe");
        if (system("fc D:\\c++\\SAFENET2.out D:\\c++\\SAFENET2.ans")!=0){
            cout<<"WRONG "<<iii;
            return 0;
        }
        else cout<<"CORRECT "<<iii<<"\n";
    }
}
