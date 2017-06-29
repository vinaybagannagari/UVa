#include<cstdio>
#include<cstdlib>
#include<bitset>
#include<cstring>
using namespace std;

bitset<30> rw, ld, rd;
int n, ans, CNo;
char board[15][15];

void backtrack(int c)
{
    if(c == n)
    {
        ans++;
        return;
    }
    for(int r = 0; r < n; r++)
        if(board[r][c] != '*' && !rw[r] && !ld[r - c + n - 1] && !rd[r + c])
        {
            rw[r] = true; ld[r - c + n - 1] = true; rd[r + c] = true;
            backtrack(c + 1);
            rw[r] = false; ld[r - c + n - 1] = false; rd[r + c] = false;
        }
}

int main()
{
    CNo = 1;
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d", &n), n)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                scanf("%c", &board[i][j]);
                if(board[i][j] == '\n')
                    j--;
            }
        ans = 0;
        backtrack(0);
        printf("Case %d: %d\n", CNo++, ans);
    }
}