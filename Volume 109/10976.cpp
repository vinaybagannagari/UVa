#include<cstdio>
#include<cstring>
using namespace std;

int k, count, x, y, X[10001], Y[10001];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d", &k) == 1)
    {
        count = 0;
        for(x = k+1; x <= 2 * k; x++)
            if((x * k) % (x - k) == 0)
            {
                y = (x * k) / (x - k);
                X[count] = x;
                Y[count] = y;
                count++;
            }
        printf("%d\n", count);
        for(int i = 0; i < count; i++)
            printf("1/%d = 1/%d + 1/%d\n", k, Y[i], X[i]);
    }
}