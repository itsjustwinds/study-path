#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>

#define PI M_PI
#define LL long long
#define INF 2123123123
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)

int x4[4] = { 0, 0,-1, 1};
int y4[4] = {-1, 1, 0, 0};
int x8[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
int y8[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

using namespace std;

#define MAXN 5005

int n,m;
int ar1[MAXN];
int ar2[MAXN];
int DP[MAXN];
vector<pair<int,int> > possible[MAXN]; //first = row, second = value
int mxCnt;
int ans;
int col;
vector<int> seq;

void reset()
{
	memset(DP,0,sizeof(DP));
	seq.clear();
	ans = col = 0;
	for (int i = 0;i<MAXN;i++) possible[i].clear();
}

int main()
{
        freopen("D:\\c++\\LCIS.inp","r",stdin);
        freopen("D:\\c++\\LCIS.ans","w",stdout);
	reset();
	scanf("%d",&n);
	for (int i = 0;i<n;i++) scanf("%d",&ar1[i]);
	scanf("%d",&m);
	for (int i = 0;i<m;i++) scanf("%d",&ar2[i]);

	for (int i = 0;i<n;i++)
	{
		int mxCnt = 0;
		for (int j = 0;j<m;j++)
		{
			if (ar1[i] == ar2[j])
			{
				possible[j].PB(MP(i, mxCnt+1));
				DP[j] = max(mxCnt+1, DP[j]);
				if (mxCnt+1 > ans)
				{
					ans = mxCnt+1;
					col = j;
				}
			}
			else if (ar2[j] < ar1[i])
			{
				mxCnt = max(mxCnt, DP[j]);
			}
		}
	}

	printf("%d\n",ans);
	if (ans == 0) return 0;

	int lastVal = INF;
	int lastPos = INF;
	for (int j = col;j>=0;j--)
	{
		if (ar2[j] < lastVal)
		{
			for (int p = 0;p<possible[j].size();p++)
			{
			    int i = possible[j][p].first;
			    int mxCnt = possible[j][p].second;

				if (i < lastPos && mxCnt == ans)
				{
					seq.PB(ar2[j]);
					lastPos = i;
					lastVal = ar2[j];
					ans--;
					break;
				}
			}
		}
	}

	/*for (int i = seq.size()-1;i>=0;i--)
	{
		if (i == seq.size()-1) printf("%d ",seq[i]);
		else printf("%d ",seq[i]);
	}*/
 	return 0;
}
