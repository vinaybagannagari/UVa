#include<cstdio>
#include<cstring>
#include<algorithm>
#include<numeric>
#include<cmath>
using namespace std;

int c, s, CNo, M[10];
double AM;

double imbalance()
{
    double imbal = 0.0;
    for(int i = 0; i < c; i++)
        imbal += abs(M[i] + M[2 * c - i - 1] - AM);
    return imbal;
}

int main()
{
    CNo = 1;
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d %d", &c, &s) != EOF)
    {
        printf("Set #%d\n", CNo++);
        memset(M, 0, sizeof(M));
        for(int i = 0; i < s; i++)
            scanf("%d", M + i);
        sort(M, M + 2 * c);
        AM = (1.0 * accumulate(M, M + 2 * c, 0))/c;
        for(int i = 0; i < c; i++)
        {
            printf(" %d:", i);
            if(M[2 * c - i -1] == 0) {printf("\n"); continue;}
            else if (M[i] == 0) printf(" %d\n", M[2 * c - i - 1]);
            else printf(" %d %d\n", M[i], M[2 * c - i -1]);
        }
        printf("IMBALANCE = %.5f\n\n", imbalance());
    }
}