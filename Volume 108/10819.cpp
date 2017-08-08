#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair

int m, n, p[110], f[110], dp[110][10010];

int favour(int id, int spentM)
{
    if(m <= 1800 && spentM > m) return -10000;
    if(spentM > m + 200) return -10000;
    if(id == n)
    {
        if(spentM > m && spentM <= 2000) return -10000;
        return 0;
    }
    if(dp[id][spentM] != -1) return dp[id][spentM];
    return dp[id][spentM] = max(favour(id + 1, spentM), f[id] + favour(id + 1, spentM + p[id]));
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d %d", &m, &n) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d %d", p + i, f + i);
        memset(dp, -1, sizeof dp); 
        printf("%d\n", favour(0, 0));
    }
}