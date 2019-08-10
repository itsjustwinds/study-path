#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
struct Tnode;
typedef Tnode* Pnode;
struct Tnode
{
        char s;
        int sz;
        Pnode P,L,R;
};
Pnode root1,root2,nil;
int n;
char s[maxn];
template<typename T> inline void read(T &x)
{
        char c;
        bool neg = false;
        while (!isdigit(c = getchar()) && c != '-');
        x = 0;
        if (c == '-')
        {
                neg = true;
                c = getchar();
        }
        do
        {
                x = x * 10 + c - '0';
        }
        while (isdigit(c = getchar()));
        if (neg) x = -x;
}
template<typename T> inline void write(T x)
{
        if (x < 0)
        {
                putchar('-');
                write(-x);
                return;
        }
        if (x < 10)
        {
                putchar(char(x + 48));
        }
        else
        {
                write(x/10);
                putchar(char(48 + x%10));
        }
}
template<typename T> inline void writeln(T x)
{
        write(x);
        putchar('\n');
}
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
        //cout<<u->s;
        putchar(u->s);
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
        freopen("SO.inp","r",stdin);
        freopen("SO.out","w",stdout);
        //ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>(s+1);
        //scanf("%c",&s+1);
        n=strlen(s+1);
        nil=new Tnode;
        *nil={0,0,nil,nil,nil};
        root1=nil;
        root2=nil;
        for (int i=1;i<=n;++i)
        {
                Pnode x;
                x=new Tnode {s[i],i,nil,root1,nil};
                root1->P=x;
                root1=x;
        }
        for (int i=n;i>=1;--i)
        {
                Pnode x;
                x=new Tnode {s[i],n-i+1,nil,root2,nil};
                root2->P=x;
                root2=x;
        }
        int test;
        read(test);
        while(test--)
        {
                int i,j;
                read(i);
                read(j);
                int d=j-i+1;
                Pnode A,B,C,D,E,F;
                split(root1,j,A,C);
                split(A,i-1,A,B);
                split(root2,n-j,D,F);
                split(F,d,E,F);
                join(A,E);
                join(A,C);
                join(D,B);
                join(D,F);
                root1=A;
                root2=D;
        }
        visit(root1);
        return 0;
}
