#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int t, M, C, costs[25][25], dp[25][210];

int max_money(int money, int garment)
{
    if(money < 0) return -100000;
    if(garment == C) return M - money;
    if(dp[garment][money] != -1) return dp[garment][money];
    int ans = -100000;
    for(int i = 1; i <= costs[garment][0]; i++)
        ans = max(ans, max_money(money - costs[garment][i], garment + 1));
    return dp[garment][money] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    scanf("%d", &t);
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%d %d", &M, &C);
        for(int i = 0; i < C; i++)
        {
            scanf("%d", costs[i]);
            for(int j = 1; j <= costs[i][0]; j++)
                scanf("%d", costs[i] + j);
        }
        int ans = max_money(M, 0);
        if(ans > 0) printf("%d\n", ans);
        else printf("no solution\n");
    }
}