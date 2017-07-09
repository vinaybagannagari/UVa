#include<cstdio>
#include<algorithm>
using namespace std;

int B, S, CNo, bach[10000], spin[10000];

int main()
{
    CNo = 1;
     #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d %d", &B, &S), B)
    {
        for(int i = 0; i < B; i++)
            scanf("%d", bach + i);
        for(int i = 0; i < S; i++)
            scanf("%d", spin + i);
        sort(bach, bach + B);
        if(S >= B) printf("Case %d: 0\n", CNo++);
        else printf("Case %d: %d %d\n", CNo++, B - S, bach[0]);
    }
}