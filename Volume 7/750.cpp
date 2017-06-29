#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int t, a, b, line, row[8];

bool attacked(int r, int c)
{
    for(int prev = 0; prev < c; prev++)
        if(row[prev] == r || abs(row[prev] - r) == (c - prev))
            return true;
    return false;
}

void solution(int c)
{
    if(c == 8)
    {
        printf("%2d      %d", ++line, row[0] + 1);
        for(int i = 1; i < 8; i++)
            printf(" %d", row[i] + 1);
        printf("\n");
    }
    for(int r = 0; r < 8; r++)
    {
        if(!attacked(r, c) && (c != b)|(r == a))
        {
            row[c] = r;
            solution(c + 1);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &a, &b); a--; b--;
        memset(row, 0, sizeof(row));
        line = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        solution(0);
        if(t) printf("\n");
    }
}