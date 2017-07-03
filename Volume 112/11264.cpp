#include<cstdio>
#include<algorithm>
using namespace std;

int t, n, denom[1000];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", denom + i);
        int count = 1, sum = denom[0];
        for(int i = 1; i < n - 1; i++)
            if(sum + denom[i] < denom[i + 1]) sum += denom[i], count++;
        count += n == 1 ? 0 : 1;
        printf("%d\n", count);
    }
}