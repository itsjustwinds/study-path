#include<bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator() (int a,int b) {
        return (a>b);
    }
};


int main()
{
    priority_queue <int,vector<int>,cmp >  myPriorityQueue ;
    // creat priority_queue
    myPriorityQueue.push(2) ;
    myPriorityQueue.push(3) ;
    myPriorityQueue.push(5) ;
    myPriorityQueue.push(4) ;
    myPriorityQueue.push(1) ;
    // print priority_queue
   while(!myPriorityQueue.empty()) {
    cout<<myPriorityQueue.top()<<" "  ;
    myPriorityQueue.pop() ;
   }
    return 0;
}
