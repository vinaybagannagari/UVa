#include<cstdio>
#include<cstdlib>
#include<bitset>
#include<algorithm>
using namespace std;

int k, sum, Max, board[8][8];
bitset<20> row, ld, rd;

void backtrack(int c)
{
    if(c == 8)
    {
        Max = max(sum, Max);
        return;
    }
    for(int r = 0; r < 8; r++)
        if(!row[r] && !ld[r - c + 7] && !rd[r + c]) // checking if current row, column and both diagonals are occupied
        {
            row[r] = ld[r - c + 7] = rd[r + c] = true; 
            sum += board[r][c];
            backtrack(c + 1); 
            sum -= board[r][c];
            row[r] = ld[r - c + 7] = rd[r + c] = false;  // backtracking
        }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    scanf("%d", &k);
    while(k--)
    {
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                scanf("%d", *(board + i) + j);
        Max = 0, sum = 0;
        backtrack(0);
        printf("%5d\n", Max);
    }
}