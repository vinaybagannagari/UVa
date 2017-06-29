/*
Ecological Bin Packing
A complete search algorithm get AC on UVaOJ
*/

#include<cstdio>
#include<string>
using namespace std;

unsigned int steps, Min, b[3][3];
int index;
const char* poss[] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%u", &b[0][0]) == 1)
    {
        steps = 0, Min = 1<<31;
        for(int i = 1; i < 9; i++)
            scanf("%u", &b[i/3][i%3]);
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(poss[i][j] == 'B')
                    if(j == 0)
                        steps += b[1][0] + b[2][0];
                    else if(j == 1)
                        steps += b[0][0] + b[2][0];
                    else
                        steps += b[0][0] + b[1][0];
                else if(poss[i][j] == 'G')
                    if(j == 0)
                        steps += b[1][1] + b[2][1];
                    else if(j == 1)
                        steps += b[0][1] + b[2][1];
                    else
                        steps += b[0][1] + b[1][1];
                else
                    if(j == 0)
                        steps += b[1][2] + b[2][2];
                    else if(j == 1)
                        steps += b[0][2] + b[2][2];
                    else
                        steps += b[0][2] + b[1][2];
            }
            if (Min > steps)
                Min = steps, index = i;
            steps = 0;
        }
        printf("%s %d\n", poss[index], Min);
    }
}
