#include<bits/stdc++.h>
using namespace std;
struct Tnode;
typedef Tnode* Pnode;
struct Tnode
{
        int val,sz;
        Pnode P,L,R;
};
Pnode root,nil;
int n;
inline void update(Pnode &x)//update size
{
        x->sz=x->L->sz+x->R->sz+1;
}

void setlink(Pnode &x,Pnode &y,bool R)// y to be x's P L or R
{
        y->P=x;
        R? x->R=y:x->L=y;
}

void uptree(Pnode &x)//push x one stage
{
        Pnode y=x->P;
        Pnode z=y->P;
        if (x==y->L)
        {
                setlink(y,x->R,false);
                setlink(x,y,true);
        }
        else
        {
                setlink(y,x->L,true);
                setlink(x,y,false);
        }
        setlink(z,x,z->R==y);
        update(x);
        update(y);
}

Pnode locate(Pnode T,int i)//find i'th in T tree
{
        while(true)
        {
                int Lsz=T->L->sz;
                if (Lsz+1==i) return T;// is it T ?
                if (i<=Lsz)
                {
                        T=T->L;
                        continue;
                }
                i-=Lsz+1;
                T=T->R;
                continue;
        }
}

void splay(Pnode &x)// push x to be root of tree
{
        while(x->P!=nil) uptree(x);
}

void visit(Pnode u)//for i=1 -> N
{
        if (u==nil) return;
        visit(u->L);
        cout<<u->val<<" ";
        visit(u->R);
        update(u);
}

void split(Pnode T,int i,Pnode &A,Pnode &B)
{
        if (i==0)
        {
                A=nil;
                B=T;
                return;
        }
        Pnode x=locate(T,i);
        splay(x);
        A=x;
        B=A->R;
        A->R=nil;
        B->P=nil;
        update(A);
}

void join(Pnode &A,Pnode B)
{
        if (A==nil)
        {
                A=B;
                return;
        }
        while(A->R!=nil) A=A->R;
        splay(A);
        setlink(A,B,true);
        update(A);
}
int main()
{
        freopen("CARDS.inp","r",stdin);
        freopen("CARDS.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        nil=new Tnode ;
        *nil={0,0,nil,nil,nil};
        root=nil;
        cin>>n;
        for (int i=1; i<=n; ++i)
        {
                Pnode x= new Tnode {i,i,nil,root,nil};
                root->P=x;
                root=x;
        }
        int test;
        cin>>test;
        //visit(root);
        while(test--)
        {
                int i,j,m;
                cin>>i>>m>>j;
                Pnode A,B,C;
                split(root,i-1,A,B);
                split(B,m,B,C);
                join(A,C);
                split(A,j-1,A,C);
                join(A,B);
                join(A,C);
                root=A;
        }
        visit(root);
}
