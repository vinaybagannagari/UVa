#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int t, N, matrix[160][160];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &N);
        for(int i = 0; i < 2*N; i++) for(int j = 0; j < 2*N; j++)
        {
            if(i < N && j < N)
            {
                scanf("%d", matrix[i] + j);
                matrix[i + N][j] = matrix[i][j + N] = matrix[i + N][j + N] = matrix[i][j];
            } 
            if(j > 0) matrix[i][j] += matrix[i][j - 1];
        }
        int sum = 0, ans = -10000, length = 0;
        for(int i = 0; i < 2*N; i++)
        {
            for(int j = i; j < 2*N; j++)
            {
                sum = length = 0;
                if(j - i + 1 > N) break;
                for(int k = 0; k < 2*N; k++)
                {
                    if(i > 0) sum += matrix[k][j] - matrix[k][i - 1];
                    else sum += matrix[k][j];
                    length++;
                    //if(ans < sum) 
                    // printf("%d %d %d %d %d\n", sum, length, i, j, k);
                    ans = max(ans, sum);
                    if(length == N || sum < 0) length = sum = 0;
                }
            }
        }
        printf("%d\n", ans);
        /*
        for(int i = 0; i < 2 * N; i++)
        {
            for(int j = 0; j < 2 * N; j++)
                printf("%d ",  matrix[i][j]);
                // else printf("%d ",  matrix[i][j] - matrix[i][j-1]);
            printf("\n");
        }
        */
    }
}