#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector< vector<int> > indices(256);
int Q, st, ed; //start and end indices
char s[1000001], qs[101];
bool match;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    scanf("%s", s);
    int n = strlen(s);
    for(int i = 0; i < n; i++)
        indices[s[i]].push_back(i);
    scanf("%d", &Q);
    while(Q--)
    {
        match = true;
        scanf("%s", qs);
        int qn = strlen(qs);
        vector<int> :: iterator it = upper_bound(indices[qs[0]].begin(), indices[qs[0]].end(), -1);
        if(it == indices[qs[0]].end())  {printf("Not matched\n"); continue;}
        st = *it;
        ed = st;
        for(int i = 1; i < qn; i++)
        {
            it = upper_bound(indices[qs[i]].begin(), indices[qs[i]].end(), ed);
            if(it == indices[qs[i]].end())  {match = false; break;}
            ed = *it;
        }
        if(match) printf("Matched %d %d\n", st, ed);
        else printf("Not matched\n");
    }

}