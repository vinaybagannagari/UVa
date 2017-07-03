#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, i, j, hts[20000], heads[20000];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d %d", &n, &m), n)
    {
        for(i = 0; i < n; i++)
            scanf("%d", heads + i);
        for(i = 0; i < m; i++)
            scanf("%d", hts + i);
        sort(heads, heads + n);
        sort(hts, hts + m);
        i = j = 0;
        int coins = 0;
        while(i < n && j < m)
        {
            while(j < m && hts[j] < heads[i]) j++;
            if(j < m)coins += hts[j++], i++;
        }
        if(i < n) printf("Loowater is doomed!\n");
        else printf("%d\n", coins);
    }
}