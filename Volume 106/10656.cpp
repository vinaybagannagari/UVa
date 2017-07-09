#include<cstdio>
using namespace std;

int N, arr[1000];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d", &N), N)
    {
        int sz = 0;
        for(int i = 0; i < N; i++)
        {
            int num;
            scanf("%d", &num);
            if(num != 0) arr[sz++] = num;
        }
        if(sz == 0) printf("0");
        else
            for(int i = 0; i < sz; i++)
            {
                if(i != sz - 1)  printf("%d ", arr[i]);
                else printf("%d", arr[i]);
            }
        printf("\n");
        
    }
}