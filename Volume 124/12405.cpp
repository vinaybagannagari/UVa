#include<cstdio>
using namespace std;

int t, n;
char field[100];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    int CNo = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        scanf("%s", field);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(field[i] == '.')  ans++, i += 2;
        }
        printf("Case %d: %d\n", CNo++, ans);
    }
}