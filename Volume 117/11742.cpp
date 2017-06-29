#include<stdio.h>
#include<algorithm>
using namespace std;

int a[20], b[20], c[20];

int position(int arr[], int p)
{
    int i;
    for(i = 0; i < 8; i++)
        if(arr[i] == p)
            break;
    return i;
}

int main()
{
    int n, m;
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(true)
    {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0)
            break;
        int p[8] =  { 0, 1, 2, 3, 4, 5, 6, 7 };
        int count = 0;
        for(int i = 0; i < m; i++)
            scanf("%d %d %d", a+i, b+i, c+i);
        do
        {
            bool flag = false;
            for(int i = 0; i < m; i++)
            {
                int pos1 = position(p, a[i]);
                int pos2 = position(p, b[i]);
                if(c[i] > 0)
                    if(abs(pos1 - pos2) > c[i])
                    {
                        flag = true;
                        break;
                    }
                        
                if(c[i] < 0)
                    if(abs(pos1 - pos2) < -c[i])
                    {
                        flag = true;
                        break;
                    }
                        
            }
            if(!flag)
                count++;
        }
        while(next_permutation(p, p+n));
        printf("%d\n", count);
    }
}