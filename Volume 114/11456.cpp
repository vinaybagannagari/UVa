#include<cstdio>
#include<algorithm>
using namespace std;

int t, n, A[2100], lds[2100], lis[2100];

void LDS(int idx)
{
    for(int i = n-1; i > idx; i--)
        if(A[i] > A[idx])
            lds[idx] = max(lds[idx], lds[i] + 1);
}

void LIS(int idx)
{
    for(int i = n-1; i > idx; i--)
        if(A[i] < A[idx])
            lis[idx] = max(lis[idx], lis[i] + 1);
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
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", A + i);
        int ans = 0;
        fill_n(lis, n, 1); fill_n(lds, n, 1);
        for(int i = n - 1; i >= 0; i--)
        {
            LDS(i); LIS(i);
            ans = max(ans, lds[i] + lis[i] - 1);
        }
        printf("%d\n", ans);
        //for(int i = 0; i < n; i++)
        //    printf("%d %d\n", lds[i], lis[i]);
    }
}