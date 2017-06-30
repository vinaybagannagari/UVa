#include<cstdio>
#include<cmath>
using namespace std;

int p, q, r, s, t, u;
double mid, lo, hi;

double func(double x)
{
    double ans = (p * exp(-x)) + (q * sin(x)) + (r * cos(x)) + (s * tan(x)) + (t * x * x) + u;
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF)
    {
        lo = 0.0, hi = 1.0;
        if(func(lo) * func(hi) > 0) {printf("No solution\n"); continue;}
        for(int i = 0; i < 30; i++)
        {
            mid = (lo + hi)/2.0;
            if(func(mid) > 0)  lo = mid;
            else hi = mid;
        }
        printf("%.4f\n", mid);
    }
}
