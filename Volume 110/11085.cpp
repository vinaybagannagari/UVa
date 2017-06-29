#include<cstdio>
#include<bitset>
#include<algorithm>
#include<cstring>
using namespace std;

int steps, Min, CNo, row[8], ini[8];
bitset<20> rw, ld, rd;

void backtrack(int c)
{
    if(c == 8)
    {
        for(int i = 0; i < 8; i++)
            if(row[i] + 1 != ini[i])
                steps++;
        Min = min(Min, steps);
        steps = 0;
        return;
    }
    for(int r = 0; r < 8; r++)
        if(!rw[r] && !ld[r - c + 7] && !rd[r + c])
        {
            rw[r] = ld[r - c + 7] = rd[r + c] = true;
            row[c] = r;
            backtrack(c + 1);
            rw[r] = ld[r - c + 7] = rd[r + c] = false;
        }
}

int main()
{
    CNo = 1;
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d", ini) == 1)
    {
        memset(row, 0, sizeof(row));
        for(int i = 1; i < 8; i++)
            scanf("%d", ini + i);
        Min = 10, steps = 0; 
        backtrack(0);
        printf("Case %d: %d\n", CNo++, Min);
    }
}