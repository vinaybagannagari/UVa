#include<cstdio>
using namespace std;

int t, N, M, max_area, ar, row1;
long long price[110][110], min_price, K, pri;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    scanf("%d", &t);
    for(int cno = 1; cno <= t; cno++)
    {
        scanf("%d %d %lld", &N, &M, &K);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
            {
                scanf("%lld", price[i] + j);
                if(j > 0) price[i][j] += price[i][j - 1];
            }
        max_area = -10000; min_price = 10000;
        for(int i = 0; i < M; i++)
            for(int j = i; j < M; j++)
            {
                row1 = ar = pri = 0;
                for(int row2 = 0; row2 < N; row2++)
                {
                    pri += price[row2][j];
                    if(i > 0) pri -= price[row2][i - 1];
                    while(pri > K && row1 <= row2)
                    {
                        pri -= price[row1][j];
                        if(i > 0) pri += price[row1][i - 1];
                        row1++;
                    }
                    ar = (row2 - row1 + 1) * (j - i + 1);
                    if(ar > max_area) min_price = pri, max_area = ar;
                    if(ar == max_area && pri < min_price) min_price = pri;
                }
            }
        printf("Case #%d: %d %lld\n", cno, max_area, min_price);
    }
}