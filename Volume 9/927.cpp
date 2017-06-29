#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
typedef unsigned long long ull;

int t, d, k, deg, n, sum, coeff[22];
ull b;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    scanf("%d", &t);
    while(t--)
    {
        b = 0, sum = 0;
        memset(coeff, 0, sizeof(coeff));
        scanf("%d", &deg);
        for(int i = 0; i < deg+1; i++)
            scanf("%d", coeff + i);
        scanf("%d %d", &d, &k);
        n = 1;
        while(sum < k)
        {
            sum += n * d;
            n++;
        }
        n--;    
        // printf("%d\n", n);
        for(int i = 0; i < deg + 1; i++)
        {
            b += coeff[i] * pow(n, i);
            // printf("%llu ", b);
        }
        // printf("\n");
        printf("%llu\n", b);
    }
} 