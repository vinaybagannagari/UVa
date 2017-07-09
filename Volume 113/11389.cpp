#include<cstdio>
#include<algorithm>
using namespace std;

int n, d, r, mrng[100], evng[100];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d %d %d", &n, &d, &r), n)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", mrng + i);
        for(int i = 0; i < n; i++)
            scanf("%d", evng + i);
        sort(mrng, mrng + n);
        sort(evng, evng + n);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int tm = mrng[i] + evng[n - i - 1];
            if(tm > d) ans += (tm - d) * r;
        }
        printf("%d\n", ans);
    }
}