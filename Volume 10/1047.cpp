#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int N, P, M, t, tower[20];

void print(int num)
{
    for(int i = 0; i < N; i++)
        if(num & 1 << i)
            printf(" %d", i + 1);
}

int main()
{
    int CNo = 1;
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    // printf("Test\n");
    while(scanf("%d %d", &N, &P), N)
    {
        
        for(int i = 0; i < N; i++)
            scanf("%d", tower + i);
        scanf("%d", &M);
        vector< pair<int, int> > intersect(M);
        for(int i = 0; i < M; i++)
        {
            scanf("%d", &t);
            int temp = 0;
            for(int j = 0; j < t; j++)
            {
                int tow; scanf("%d", &tow); tow--;
                temp |= 1 << tow;
            }
            int val; scanf("%d", &val);
            intersect[i] = make_pair(temp, val);
        }
        int max_ = -1000000000, tows_placed;
        for(int i = 1; i < (1 << N); i++)
            if(__builtin_popcount(i) == P)
            {
                int popl = 0;
                for(int j = 0; j < N; j++)
                    if(i & 1 << j)
                        popl += tower[j];
                for(int j = 0; j < M; j++)
                    if(__builtin_popcount(i & intersect[j].first) > 1)
                    {
                        int common = __builtin_popcount(i & intersect[j].first);
                        popl -= (common - 1) * intersect[j].second;
                    }
                if(popl > max_) max_ = popl, tows_placed = i;
                else if(popl == max_)
                    for(int j = 0; j < N; j++)
                    {
                        if((tows_placed & 1 << j) && !(i & 1 << j)) break;
                        else if(!(tows_placed & 1 << j) && (i & 1 << j))
                        {
                            max_ = popl, tows_placed = i;
                            break;
                        }
                    }
            }
        printf("Case Number  %d\n", CNo++);
        printf("Number of Customers: %d\n", max_);
        printf("Locations recommended:");
        print(tows_placed);
        printf("\n\n");
    }
}