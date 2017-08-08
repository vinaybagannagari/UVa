#include<cstdio>
#include<vector>
using namespace std;

class BigInteger
{
    public:
        vector<int> value;
        int sign;
        BigInteger() : sign(0) {}

        BigInteger(long long num)
        {
            if(num == 0) {sign = 0; value.push_back(0);}
            if(num > 0) sign = 1;
            if(num < 0) sign = -1;
            num *= sign;
            while(num)
            {
                value.push_back(num%10);
                num /= 10;
            }
        }

        BigInteger(vector<int> arr, int sign) : value(arr), sign(sign) {}

        void set(long long num)
        {
            BigInteger temp(num);
            *this = temp;
        }

        bool operator < (BigInteger& num)
        {
            if(sign != num.sign || sign == 0) return sign < num.sign;
            if(value.size() != num.value.size())
            {
                if(sign < 0) return value.size() > num.value.size();
                else return value.size() < num.value.size();
            }
            for(int i = value.size() - 1; i >=0; i--)
                if(value[i] != num.value[i])
                {
                    if(sign < 0) return value[i] > num.value[i];
                    else return value[i] < num.value[i];
                }
        }

        bool operator > (BigInteger& num)
        {
            return num < *this;
        }

        bool operator <= (BigInteger& num)
        {
           return !(*this > num);
        }

        bool operator >= (BigInteger& num)
        {
            return !(*this < num);
        }

        bool operator == (BigInteger& num)
        {
            return *this <= num && *this >= num;
        }

        BigInteger operator * (BigInteger& num)
        {
            if(sign * num.sign == 0) return BigInteger(0ll);
            vector<int> temp(value.size() + num.value.size(), 0);
            int carry = 0, i, j;
            for(i = 0; i < value.size(); i++)
            {
                int digit = value[i];
                for(j = 0; j < num.value.size(); j++)
                {
                    int prod = digit * num.value[j] + temp[i + j] + carry;
                    temp[i + j] = prod % 10;
                    carry = prod/10;
                }
                temp[i + j] = carry; carry = 0;
            }
            if(temp.back() == 0) temp.pop_back();
            return BigInteger(temp, sign * num.sign);
        }

        BigInteger operator *= (BigInteger& num)
        {
            return *this = *this * num;
        }

        void print()
        {
            if(sign < 0) printf("-");
            for(int i = value.size() - 1; i >= 0; i--)
                printf("%d", value[i]);
        }
} dp[110][110];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    long long val;
    while(scanf("%lld", &val) != EOF)
    {
        int N = 0;
        BigInteger ans(-1000000);
        while(val != -999999)
        {
            dp[N][N].set(val);
            if(ans < dp[N][N]) ans = dp[N][N];
            scanf("%lld", &val);
            ++N;
        }
        // for(int i = 0; i < N; i++) {dp[i][i].print(); printf(" ");} printf("\n");
        for(int i = 0; i < N; i++)
            for(int j = i + 1; j < N; j++)
            {
                dp[i][j] = dp[i][j - 1] * dp[j][j];
                if(dp[i][j] > ans) ans = dp[i][j];
            }
        ans.print();
        printf("\n");
    }
}