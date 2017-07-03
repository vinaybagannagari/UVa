#include<cstdio>
#include<cstdlib>
#include<cmath>
#define EPS 1e-9
using namespace std;

int n, l, w;
struct interval
{
    double left;
    double right;
};

int comp(const void* a, const void* b)
{
    interval i1, i2;
    i1 = *(interval*)a, i2 = *(interval*)b;
    return i1.left > i2.left ? 1 : -1;
}
interval itrvls[10000];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    while(scanf("%d %d %d", &n, &l, &w) != EOF)
    {
        int pos, r, sz = 0;
        double w1 = (w * w)/4.0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &pos, &r);
            if(2 * r > w)
            {
                itrvls[sz].left = pos - sqrt(double(r)*r - w1);
                itrvls[sz].right = pos + sqrt(double(r)*r - w1);
                sz++;
            }
        }
        qsort(itrvls, sz, sizeof(interval), comp);
        double rt = 0.0, bestr = 0.0;
        int ans = 0;
        for(int i = 0; i < sz;)
        {
            while(i < sz && itrvls[i].left <= rt)
            {
                if(itrvls[i].right > bestr)
                    bestr = itrvls[i].right;
                i++;
            }
            rt = bestr;
            ans++;
            bestr = 0.0;
            if(itrvls[i].left > rt || rt + EPS > l) break;
        }
        printf("%d\n", rt + EPS > l ? ans : -1);
    }
}