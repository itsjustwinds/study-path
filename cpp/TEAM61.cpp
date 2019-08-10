#include<bits/stdc++.h>
using namespace std;
int N,M,P,R,B[100],C[100],S[100],T[100],V[100],H[100],A[100][100],X,K,Have[100];
int Having,ok;
struct data{
    int Type,Need,Get,Left,Status,Cal,ID;
};
struct CT{
    int TypeCT,TypeSP,Left;
};
struct Plan{
    int Get,Time;
    double ADV;
    int Type,ID;
};
bool cmpR(data a,data b){
    if (a.Status!=b.Status) return a.Status>b.Status;
    return a.Cal>b.Cal;
}
bool cmpPlan(Plan a,Plan b){
    return a.ADV>b.ADV;
}
data aR[100];
CT aCT[100];
Plan aPlan[100];
int main(){
    freopen("INPUT.inp","r",stdin);
    freopen("MOVE.out","w",stdout);
    cin>>N>>M>>P>>R;
    for (int i=1;i<=M;++i)
        cin>>B[i]>>C[i];

    for (int i=1;i<=P;++i)
        cin>>S[i]>>T[i]>>V[i]>>H[i];

    for (int i=1;i<=P;++i)
        for (int j=1;j<=P;++j)
        cin>>A[i][j];

    for (int i=1;i<=R;++i){
        int Type,Need,Get,Left,Status,ID;
        cin>>Type>>Need>>Get>>Left>>Status>>ID;
        aR[i]={Type,Need,Get,Left,Status,ID};
    }

    cin>>X>>K;

    for (int i=1;i<=N;++i){
        int TypeCT,TypeSP,Left;
        cin>>TypeCT>>TypeSP>>Left;
        aCT[i]={TypeCT,TypeSP,Left};
        if (TypeCT!=0) ok=1;
    }

    for (int i=1;i<=P;++i){
        aCT[S[i]].TypeSP=i;
    }

    for (int i=1;i<=P;++i){
        cin>>Have[i];
        if (Have[i]>0) ++Having;
    }
/////////////////////////////////////////////////////////////////////////////
    for (int i=1;i<=R;++i){
        if (X-aR[i].Need*H[aR[i].Type]<0) {
            aR[i].Cal=-1000000000;
            continue;
        }
        aR[i].Cal=aR[i].Get-aR[i].Need*H[aR[i].Type];
    }
    sort(aR+1,aR+R+1,cmpR);
    if (aR[1].Cal>0) {
        if (aR[1].Need<=Have[aR[1].Type]) {
            cout<<"G "<<aR[1].ID;
            return 0;
        }
        cout<<"B "<<aR[1].Type<<" "<<aR[1].Need;
    }
//////////////////////////////////////////////////////////////////////////////
    if (Having==K){
        for (int i=1;i<=P;++i)
        if (Have[i]>0) {
            cout<<"S "<<i<<" "<<Have[i];
            return 0;
        }
    }
//////////////////////////////////////////////////////////////////////////////
    if (!ok)
    for (int i=1;i<=M;++i){
        if (X<C[i]) {
                aPlan[i].ADV=-1000000000;
                continue;
        }
        int Time,Type,Get;
        Time=1;
        Get=0;
        Type=aCT[i].TypeSP;
        for (int j=1;j<=P;++j)
        if (i!=j&&A[j][Type]>0) {
            ++Time;
            Get-=A[j][Type]*H[j];
        }
        aPlan[i].ID=i;
        Time=max(Time,T[Type]+1);
        aPlan[i].Time=Time;
        Get+=V[Type];
        if (Get<0) continue;
        aPlan[i].ADV=(double)Get*((double)K/Time);
    sort(aPlan+1,aPlan+M+1,cmpPlan);
    if (aPlan[1].ADV<0) {
        cout<<"I";
        return 0;
    }
    cout<<"C "<<aPlan[1].ID;
    }
    else {
        int Type;
        for (int i=1;i<=M;++i)
        if (aCT[i].TypeCT!=0) Type=aCT[i].TypeSP;
        for (int i=1;i<=P;++i)
        if (Have[i]==0&&i!=Type) {
            cout<<"B "<<i;
            return 0;
        }
    }
}
