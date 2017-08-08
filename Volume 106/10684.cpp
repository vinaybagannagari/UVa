#include<cstdio>
#include<algorithm>
using namespace std;

int N, sum, ans;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d", &N), N)
    {
        ans = -10000, sum = 0;
        for(int i = 0; i < N; ++i)
        {
            int temp;
            scanf("%d", &temp);
            sum += temp;
            ans = max(sum, ans);
            if(sum < 0) sum = 0;
        }
        if(ans <= 0) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n", ans);
    }
}