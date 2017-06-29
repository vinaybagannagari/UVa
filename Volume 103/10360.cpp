#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int t, n, d, x, y, cnt, x_max, y_max, Max, kill[1025][1025];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &d, &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &x, &y, &cnt);
            for(int j = x - d; j <= x + d; j++)
                for(int k = y - d; k <= y + d; k++)
                    if(j >= 0 && k >=0 && j <=1024 && k <= 1024)
                        kill[j][k] += cnt;
        }
        cnt = 0;
        for(x = 0; x <= 1024; x++)
            for(y = 0; y <= 1024; y++)
                if(kill[x][y] > cnt)
                    x_max = x, y_max = y, cnt = kill[x][y];
        printf("%d %d %d\n", x_max, y_max, cnt);
        memset(kill, 0, sizeof(kill[0][0])*1025*1025);
    }
}