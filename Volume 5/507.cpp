#include<cstdio>
using namespace std;

int b, s, nice[20000];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    scanf("%d", &b);
    for(int r = 1; r <= b; r++)
    {
        scanf("%d", &s);
        for(int i = 0; i < s - 1; i++)
            scanf("%d", nice + i);
        int start = 1, end = 1, start_ans = 1, end_ans = 1, sum = 0, ans = -1000000000;
        for(int i = 0; i < s - 1; i++)
        {
            sum += nice[i];
            end++;
            if(ans < sum) { ans = sum; start_ans = start; end_ans = end;}
            if(ans == sum) if((end - start) > (end_ans - start_ans)) { start_ans = start; end_ans = end;} 
            if(sum < 0) {sum = 0; start = end;}
        }
        if(ans <= 0)
            printf("Route %d has no nice parts\n", r);
        else
            printf("The nicest part of route %d is between stops %d and %d\n", r, start_ans, end_ans);
        // printf("%d\n", ans);
    }
}