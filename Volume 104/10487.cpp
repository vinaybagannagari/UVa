#include<cstdio>
#include<cmath>
using namespace std;

int n, clo_sum, diff, m, q, CNo, A[1000];

int main()
{
    CNo = 1;
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d", &n), n)
    {
        printf("Case %d:\n", CNo++);
        for(int i = 0; i < n; i++)
            scanf("%d", A + i);
        scanf("%d", &m);
        while(m--)
        {
            diff = 1000000000;
            scanf("%d", &q);
            for(int i = 1; i < n; i++)
                for(int j = 0; j < i; j++)
                    if(abs(A[i] + A[j] - q) < diff)
                    {
                        clo_sum = A[i] + A[j];
                        diff = abs(A[i] + A[j] - q);
                    }
            printf("Closest sum to %d is %d.\n", q, clo_sum);
        }
    }
}