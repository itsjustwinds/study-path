#include <iostream>

#include <fstream>

#include <stack>

#define maxN 1000

#define maxM 500000

using namespace std;

ifstream fi (“songlt.inp”);

ofstream fo (“songlt.out”);

pair<int,int> edg;

stack< pair<int,int> > S;

int N, M, count_,Bcc, p, q;

int Number[maxN], Low[maxN];

bool a[maxN][maxN];

void read_input()    // Đọc dữ liệu vào, lưu dưới dạng ma trận kề
{

    int x, y;

    fi >> N >> M;

    for (int i=1; i<=M; i++)
    {

        fi >> x >> y;

        a[x][y]=true;
        a[y][x]=true;

    }

}

int min2(int x, int y)
{

    if (x<y) return x;
    else return y;

}

void DFS(int u)    // Thăm từ đỉnh u
{

    int i, v;

    count_ ++;

    Number[u]=count_; // Thừ tự thăm đến u

    Low[u]=maxN + 1;  // Khởi trị Low[u]

    for (int v=1; v<=N; v++)// Duyệt các đỉnh v

        if (a[u][v])     // v kề với u
        {

            a[v][u]=false; // Định chiều cung (u; v) bằng xóa cung (v;u)

            if (Number[v]!=0) // Nếu đã thăm v thì cập nhật lại Low[u] do thêm Number[v]

                Low[u]=min2(Low[u], Number[v]);

            else   // Nếu v chưa thăm
            {

                S.push(make_pair(u,v)); // Nạp cung (u,v) vào ngăn xếp

                DFS(v); // Thăm tiếp từ v

                Low[u]=min2(Low[u], Low[v]); // Thăm xong v, cập nhật Low[u] do có Low[v]

                if (Low[v]>= Number[u])   // Cung (u,v) là cung chốt
                {

                    Bcc++; // Thêm một thành phần song liên thông

                    do    // Lấy khỏi ngăn xếp các cung hậu duệ của cung (u;v)
                    {

                        edg = S.top();
                        S.pop ();

                        p = edg.first;
                        q = edg.second;

                        fo << q << ” “; // Hiện các đỉnh thuộc thành phần song liên thông

                    }
                    while (! ((p==u)&&(q==v)));

                    fo << u << endl;

                }

            }

        }

}

void process()
{

    int l_c;

    S.empty();

    for (int u=1; u<=N; u++)

        if (Number[u]==0)   // đỉnh u chưa thăm
        {

            l_c = count_;  // Lưu lại thứ tự thăm đến đỉnh u

            DFS(u); // Thuật toán tìm thành phần song liên thông

            if (count_ == l_c+1)   // Nếu u là đỉnh cô lập
            {

                Bcc++; // thì u là một thành phần song liên thông

                fo << u << endl;

            }

        }

}

int main()
{

    read_input();

    process();

    return 0;

}
