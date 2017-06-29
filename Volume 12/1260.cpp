#include<cstdio>
using namespace std;

int t, n, sum, A[1000];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    scanf("%d", &t);
    while(t--)
    {
        sum = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", A + i);
        for(int i = 1; i < n; i++)
            for(int j = 0; j < i; j++)
                if(A[j] <= A[i])
                    sum++;
        printf("%d\n", sum);
    }
}