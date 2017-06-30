#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n, m, prc1, prc2, i, j, prices[10000];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d", &n) != EOF)
    {
        for(i = 0; i < n; i++)
            scanf("%d", prices + i);
        sort(prices, prices + n);
        scanf("%d", &m);
        i = 0, j = n-1 , prc1 = prices[0], prc2 = prices[n-1];
        while(i < j)
        {
            if(prices[i] + prices[j] > m)
                j--;
            else if(prices[i] + prices[j] < m)
                i++;
            else
                prc1 = prices[i++], prc2 = prices[j--];
        }
        memset(prices, 0, sizeof(prices));
        printf("Peter should buy books whose prices are %d and %d.\n\n", prc1, prc2);
    }
}