#include<cstdio>
using namespace std;

int k, s[13];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    bool first = true;
    while(scanf("%d", &k), k)
    {
        if(!first) printf("\n");
        first = false;
        for(int i = 0; i < k; i++)
            scanf("%d", s + i);
        for(int a = 0; a <= k - 6; a++)
            for(int b = a + 1; b <= k - 5; b++)
                for(int c = b + 1; c <= k - 4; c++)
                    for(int d = c + 1; d <= k - 3; d++)
                        for(int e = d + 1; e <= k - 2; e++)
                            for(int f = e + 1; f <= k - 1; f++)
                                printf("%d %d %d %d %d %d\n", s[a], s[b], s[c], s[d], s[e], s[f]);
        
    }
}