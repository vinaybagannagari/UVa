#include<cstdio>
#include<algorithm>
using namespace std;

int f, r, F[10], R[10];
double max_r, ratio[100];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d", &f), f)
    {
        max_r = 0.0;
        scanf("%d", &r);
        for(int i = 0; i < f; i++)
            scanf("%d", F + i);
        for(int i = 0; i < r; i++)
            scanf("%d", R + i);
        int idx = 0;
        for(int i = 0; i < f; i++)
            for(int j = 0; j < r; j++)
                ratio[idx++] = ((double)R[j])/F[i];
        sort(ratio, ratio + (f * r));
        for(int i = 0; i < f * r - 1; i++)
            max_r = max(max_r, (ratio[i+1]/ratio[i]));
        printf("%.2f\n", max_r);
        // for(int i = 0; i < f*r - 1; i++)
        //     printf("%.2f ", ratio[i+1]/ratio[i]);
        // printf("\n");
    }
}