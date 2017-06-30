#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, Q, L, U, side, height[500][500];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d %d", &n, &m), n)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", height[i] + j);
        scanf("%d", &Q);
        while(Q--)
        {
            scanf("%d %d", &L, &U);
            side = 0;
            for(int i = 0; i < n; i++)
            {
                int* low = lower_bound(height[i], height[i] + m, L);
                int y = low - height[i];
                for(int j = side; j < n; j++)
                    if(i + j >= n || y + j >= m || height[i + j][y + j] > U) break;
                    else if(j + 1 > side)  side = j + 1;
            }
            printf("%d\n", side);
        }
        printf("-\n");
    }
}