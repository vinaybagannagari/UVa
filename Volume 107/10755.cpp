#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int t, A, B, C;
long long ppiped[25][25][25], matrix[25][25];

long long Max_2D_sum()
{
    long long r_sum[25], sum, ans = -1e10;
    for(int col1 = 0; col1 < B; col1++)
    {
        memset(r_sum, 0, sizeof(r_sum));
        for(int col2 = col1; col2 < B; col2++)
        {
            for(int row = 0; row < A; row++)
                r_sum[row] += matrix[row][col2];
            sum = 0;
            for(int i = 0; i < A; i++)   // kadane's algorithm
            {
                sum += r_sum[i];
                ans = max(ans, sum);
                if(sum < 0) sum = 0;
            }
        }
    }
    return ans;
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
        long long ans = -1e10;
        scanf("%d %d %d", &A, &B, &C);
        for(int i = 0;  i < A; i++)
            for(int j = 0; j < B; j++)
                for(int k = 0; k < C; k++)
                {
                    scanf("%lld", ppiped[i][j] + k);
                    if(k > 0) ppiped[i][j][k] += ppiped[i][j][k - 1];
                }
        for(int l = 0; l < C; l++)
            for(int r = l; r < C; r++)
            {
                for(int i = 0; i < A; i++)
                    for(int j = 0; j < B; j++)
                        if(l > 0) matrix[i][j] = ppiped[i][j][r] - ppiped[i][j][l - 1];
                        else matrix[i][j] = ppiped[i][j][r];
                ans = max(ans, Max_2D_sum());
            }
        printf("%lld\n", ans);
        if(t) printf("\n");
    }
}