#include<cstdio>
#include<cstring>
using namespace std;

#define MOD 1000000
int N, K, ways[110][110];

int No_Ways(int sum, int var)
{
    int ans = 0;
    if(var == 1) return 1;
    if(ways[sum][var] != -1) return ways[sum][var];
    for(int i = 0; i <= sum; i++)
        ans += No_Ways(sum - i, var - 1) % MOD;
    return ways[sum][var] = ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d %d", &N, &K), N)
    {
        memset(ways, -1, sizeof(ways));
        printf("%d\n", (No_Ways(N, K)) % MOD);
    }
}