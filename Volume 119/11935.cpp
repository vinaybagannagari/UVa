#include<cstdio>
#include<algorithm>
using namespace std;

double cons_rate, leak, consumed, prev_consumed; //prev_consumed stores fuel consumed before gas station is reached
int Prev, cur, n; // previous and current checkpoint 
char event[20];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d %*s %*s %d", &Prev, &n), n)
    {
        cons_rate = n/100.0;
        leak = consumed = prev_consumed = 0.0;
        while(scanf("%d %s", &cur, event) && event[1] != 'o') // event is Goal
        {
            if(event[0] == 'F') // event is fuel consumption
            {
                scanf("%*s %d", &n);
                consumed += (leak + cons_rate) * (cur - Prev);
                Prev = cur;
                cons_rate = n/100.0;
            }
            else if(event[0] == 'L') // event is leak
            {
                consumed += (leak + cons_rate) * (cur - Prev);
                Prev = cur;
                leak++;
            }
            else if(event[0] == 'G') // event is gas station
            {
                scanf("%*s");
                consumed += (leak + cons_rate) * (cur - Prev);
                prev_consumed = max(consumed, prev_consumed);
                consumed = 0.0;
                Prev = cur;
            }
            else // event is mechanic
            {
                consumed += (leak + cons_rate) * (cur - Prev);
                Prev = cur;
                leak = 0.0;
            }
        }
        consumed += (leak + cons_rate) * (cur - Prev);
        consumed = max(consumed, prev_consumed);
        printf("%.3f\n", consumed);
    }
}