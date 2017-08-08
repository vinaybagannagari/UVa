#include<cstdio>
#include<algorithm>
using namespace std;

int t, n, H[100000], W[100000], W1[100000], W2[100000];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    scanf("%d", &t);
    for(int cno = 1; cno <= t; cno++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", H + i);
        for(int i = 0; i < n; i++)
            scanf("%d", W + i);
        int inc = 0, dec = 0;
        for(int i = 0; i < n; i++)
        {
            W1[i] = W2[i] = W[i];
            for(int j = 0; j < i; j++)
                if(H[i] > H[j]) W1[i] = max(W1[i], W[i] + W1[j]);
                else if(H[i] < H[j]) W2[i] = max(W2[i], W[i] + W2[j]);
            inc = max(inc, W1[i]); dec = max(dec, W2[i]);
        }
        // for(int i = 0; i < n; i++)
        //     printf("%d ", LDS[i]);
        if(inc >= dec) printf("Case %d. Increasing (%d). Decreasing (%d).\n", cno, inc, dec);
        else printf("Case %d. Decreasing (%d). Increasing (%d).\n", cno, dec, inc);
    }
}