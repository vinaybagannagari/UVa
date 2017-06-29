#include<cstdio>
using namespace std;
typedef long long ll;
int t, n, p, rods[20];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    scanf("%d", &t);
    ll mask = 0;
    while(t--)
    {
        bool possible = false;
        scanf("%d %d", &n, &p);
        for(int i = 0; i < p; i++)
            scanf("%d", rods + i);
        while(mask < 1<<p && !possible)
        {
            int sum = 0;
            for(int i = 0; i < p; i++)
                if(mask & 1<<i)
                    sum += rods[i];
            if (sum == n)
                possible = true;
            mask++;
        }
        mask = 0;
        if(possible)
            printf("YES\n");
        else
            printf("NO\n");
    }
}