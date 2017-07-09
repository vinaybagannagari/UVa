#include<cstdio>
#include<algorithm>
using namespace std;

int n, bags[10000];

int main()
{
    bool first = true;
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d", &n), n)
    {
        if(!first) printf("\n");
        else first = false;
        for(int i = 0; i < n; i++)
            scanf("%d", bags + i);
        sort(bags, bags + n);
        int i = 0, j = 0, max_freq = 0;
        while(i < n)
        {
            i = upper_bound(bags, bags + n, bags[i]) - bags;
            // printf("%d\n", i);
            max_freq = max(max_freq, i - j);
            j = i;
        }
        printf("%d\n", max_freq);
        for(i = 0; i < max_freq; i++)
        {
            j = i;
            while(j < n)
            {
                printf("%d", bags[j]);
                j += max_freq;
                if(j < n) printf(" "); 
            }
            printf("\n");
        }
    }
}