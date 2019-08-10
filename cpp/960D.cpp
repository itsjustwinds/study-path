#include<bits/stdc++.h>
using namespace std;
vector<vector<int > > a;
vector<int > Size,Empty;
int n,queries;
int main(){
    cin>>n>>queries;
    for (int i=0;i<n;++i){
        int sl;
        cin>>sl;
        Size.push_back(sl);
        a.push_back(Empty);
        for (int j=0;j<sl;++j){
            int x;
            cin>>x;
            a[i].push_back(x);
        }
    }
    for (int i=0;i<queries;++i){
        int spot,num;
        cin>>spot>>num;
        cout<<a[spot][num]<<"\n";
    }
}
