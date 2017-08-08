#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int N, L, A[55], cost[55][55];
int cut(int l, int r)
{
    if(l + 1 == r) return 0;
    if(cost[l][r] != -1) return cost[l][r];
    int ans = 1000000;
    for(int i = l + 1; i < r; i++)
        ans = min(ans, cut(l, i) + cut(i, r) + A[r] - A[l]);
    return cost[l][r] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d", &L), L)
    {
        scanf("%d", &N);
        A[0] = 0, A[N + 1] = L;
        for(int i = 1; i < N + 1; i++)
            scanf("%d", A + i);
        memset(cost, -1, sizeof(cost));
        printf("The minimum cutting is %d.\n", cut(0, N + 1));
    }
}