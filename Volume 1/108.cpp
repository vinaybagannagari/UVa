#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N, r_sum[110], matrix[110][110], sum, ans;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    scanf("%d", &N);
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) scanf("%d", matrix[i] + j);
    ans = -100000;
    for(int col1 = 0; col1 < N; col1++)
    {
        memset(r_sum, 0, sizeof(r_sum));
        for(int col2 = col1; col2 < N; col2++)
        {
            for(int row = 0; row < N; row++)
                r_sum[row] += matrix[row][col2];
            sum = 0;
            for(int i = 0; i < N; i++)   // kadane's algorithm
            {
                sum += r_sum[i];
                ans = max(ans, sum);
                if(sum < 0) sum = 0;
            }
        }
    }
    printf("%d\n", ans);
}