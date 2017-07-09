#include<cstdio>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("output.out", "w", stdout);
    #endif
    for(int a = 1; 4 * a < 2000; a++)
        for(int b = a; a + 3 * b < 2000; b++)
            for(int c = b; a + b + c + c < 2000; c++)
            {
                long long p = 1LL * a * b * c, s = a + b + c;
                if(p <= 1000000) continue;
                if((s * 1000000) % (p - 1000000))
                    continue;
                int d = (s * 1000000) / (p - 1000000);
                if(s + d > 2000 || d < c) continue;
                printf("%.2f %.2f %.2f %.2f\n", a/100.0, b/100.0, c/100.0, d/100.0);
            }
}