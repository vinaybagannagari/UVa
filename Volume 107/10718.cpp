#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;

ll n, l, u;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%lld %lld %lld", &n, &l, &u) != EOF)
    {
        int bit = log2(u);
        ll ans = 0;
        while(bit >= 0)
        {
            if(n & (1LL << bit))
            {
                if((ans | ((1 << bit) - 1)) < l)
                    ans |= 1LL << bit;
            }
            else
                if((ans | (1LL << bit)) <= u)
                    ans |= 1LL << bit;
            bit--;
            // printf("%d\n", bit);
        }
        printf("%lld\n", ans);
    }
}