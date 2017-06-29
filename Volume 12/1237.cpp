#include<cstdio>
#include<cstring>
using namespace std;

int t, D, Q, P, count, L[10000], H[10000];
char manf[20], M[10000][20];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &D);
        for(int i = 0; i < D; i++)
            scanf("%s %d %d", M[i], L + i, H + i);
        scanf("%d", &Q);
        while(Q--)
        {
            count = 0;
            scanf("%d", &P);
            for(int i = 0; i < D; i++)
            {
                if(P >= L[i] && P <= H[i])
                    if(count == 0)
                        count = 1, strcpy(manf, M[i]);
                    else {count++; break;}
            }
            if(count == 1)
                printf("%s\n", manf);
            else
                printf("UNDETERMINED\n");
        }
        if(t) printf("\n");
    }
}