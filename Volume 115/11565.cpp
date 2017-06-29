#include<stdio.h>
using namespace std;

int main()
{
    int n, A, B, C;
    // freopen("se.in", "r", stdin);
    // freopen("se.out", "w", stdout);
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d %d", &A, &B, &C);
        bool sol = false;
        int x, y, z;
        for(x = -69; x <= 69 && !sol; ++x)
            if(x*x <= C)
                for(y = -100; y <= 100 && !sol; ++y)
                    if(y != x && x * x + y * y <= C)
                        for(z = -100; z <= 100 && !sol; ++z)
                            if(x != y && y != z && z != x && x + y + z == A && x * y * z == B &&
                             x * x + y * y + z * z == C)
                            {
                                sol = true;
                                printf("%d %d %d\n", x, y, z);
                             }
        if(!sol)
            printf("No solution.\n");
    }
}