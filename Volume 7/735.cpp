#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int n;
bool used[61][61][61];

int main()
{
    vector<int> scores;
    bool first = true;
    for(int i = 0; i <= 60; i++)
        if(i <= 20 || (i % 2 == 0 && i/2 <=20) || i % 3 == 0)
            scores.push_back(i);
    scores.push_back(50);
    int sz = scores.size();
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d", &n), n > 0)
    {
        memset(used, false, sizeof(used));
        if(first) first = false;
        else
        {
            for(int i = 0; i < 70; i++)
                printf("*");
            printf("\n");
        }
        int perm = 0, comb = 0;
        for(int i = 0; i < sz; i++)
            for(int j = 0; j < sz; j++)
                for(int k = 0; k < sz; k++)
                    if(scores[i] + scores[j] + scores[k] == n)
                    {
                        int a = scores[i], b = scores[j], c = scores[k];
                        perm++;
                        if(!used[a][b][c])
                           comb++;
                        used[a][b][c] = used[a][c][b] = used[b][a][c] = used[b][c][a] = used[c][a][b] = used[c][b][a] = true;
                    }
            if(perm == 0)
                printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
            else
            {
                printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, comb);
                printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, perm);
            }
    }
    for(int i = 0; i < 70; i++)
        printf("*");
    printf("\nEND OF OUTPUT\n");
}