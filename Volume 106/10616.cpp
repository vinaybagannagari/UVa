#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int N, Q, A[210], D, M, sno;
long long dp[210][20][30];

long long divSums(int id, int cnt, int sum)
{
    if(cnt == M)
    {
        if(sum == 0) return 1LL;
        else return 0LL;
    }
    if(id == N) return 0LL;
    if(dp[id][cnt][sum] != -1) return dp[id][cnt][sum];
    int temp = A[id] - D * floor((double)A[id]/D);
    return dp[id][cnt][sum] = divSums(id + 1, cnt + 1, (sum + temp)%D) + divSums(id + 1, cnt, sum);
}

int main()
{
    sno = 1;
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d %d", &N, &Q), N)
    {
        for(int i = 0; i < N; ++i)
            scanf("%d", A + i);
        printf("SET %d:\n", sno++);
        for(int qno = 1; qno <= Q; ++qno)
        {
            scanf("%d %d", &D, &M);
            memset(dp, -1, sizeof dp);
            printf("QUERY %d: %lld\n", qno, divSums(0, 0, 0));
        }
    }
}