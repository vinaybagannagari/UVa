#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long ll;
#define MAX 10000000

ll A[MAX], L[MAX], L_id[MAX], P[MAX];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ll i = 0, pos, lis = 0, lis_end;
    while(scanf("%lld", A + i) != EOF)
    {
        pos = lower_bound(L, L + lis, A[i]) - L;
        L[pos] = A[i], L_id[pos] = i;
        P[i] = pos ? L_id[pos - 1] : -1;
        if(pos + 1 >= lis) lis = pos + 1, lis_end = i;
        i++;
    }
    printf("%lld\n-\n", lis);
    stack<ll> LIS;
    i = lis_end;
    while(i >= 0)
    {
        LIS.push(A[i]);
        i = P[i];
    }
    for(;!LIS.empty(); LIS.pop()) printf("%lld\n", LIS.top());
}
