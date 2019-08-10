#include<bits/stdc++.h>
#define base 10000
#define ll long long
using namespace std;
typedef vector<ll > Bignum;
Bignum a,b;
void fix(Bignum &a){
      a.push_back(0);
      for (int i=0;i<a.size()-1;++i){
            a[i+1]+=a[i]/base;
            a[i]%=base;
            if (a[i]<0){
                  a[i]+=base;
                  a[i+1]--;
            }
      }
      while(a.size()>1&&a.back()==0) a.pop_back();
}
Bignum operator +(Bignum a,const Bignum &b){
      a.resize(max(a.size(),b.size()));
      for (int i=0;i<b.size();++i)
            a[i]+=b[i];
      fix(a);
      return a;
}
Bignum operator -(Bignum a,const Bignum &b){
      for (int i=0;i<b.size();++i)
            a[i]-=b[i];
      fix(a);
      return a;
}
bool operator >=(Bignum a,Bignum b){
      if (a.size()!=b.size()) return a.size()>b.size();
      for (int i=a.size()-1;i>=0;--i)
      if (a[i]!=b[i]) return a[i]>b[i];
      return 1;
}
Bignum operator *(Bignum a,Bignum b){
      Bignum c;
      c.resize(a.size()+b.size());
      for (int i=0;i<a.size();++i)
            for (int j=0;j<b.size();++j)
                  c[i+j]+=a[i]*b[j];
      fix(c);
      return c;
}
istream& operator >>(istream& cin,Bignum &a){
      string s;
      cin>>s;
      a.clear();
      a.resize(s.size()/4+1);
      for (int i=0;i<s.size();++i){
            int pos=(s.size()-i-1)/4;
            a[pos]=a[pos]*10+s[i]-'0';
      }
      fix(a);
      return cin;
}
ostream& operator <<(ostream& cout,Bignum a){
      printf("%d",a.back());
      for (int i=a.size()-2;i>=0;--i)
            printf("%04lld",a[i]);
      return cout;
}
int main(){
      freopen("Bignum.inp","r",stdin);
      cin.tie(0);
      cout.tie(0);
      cin>>a;
      cin>>b;
      cout<<a+b<<"\n";
      if (a>=b)cout<<a-b<<"\n";
      else cout<<"-"<<b-a<<"\n";
      cout<<a*b;
      return 0;
}
