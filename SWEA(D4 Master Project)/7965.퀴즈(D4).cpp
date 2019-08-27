#include <stdio.h>
#define MOD 1000000007
long long result[1000001];

long long power(long long x, long long y) {
    long long r = 1;
    while(y) {
        if(y & 1) {
            if(r * x > MOD) r = (r * x ) % MOD;
            else r *= x;
        }
        if(x * x > MOD) x = (x * x) % MOD;
        else x*= x;
        y >>= 1;
    }

    return r;
}


int main(void)
{
    int T;
    result[1] = 1;
    result[2] = 5;
    for (long long i = 3; i <= 1000000; i++)
        result[i] = (result[i - 1] + power(i, i)) % MOD;

    scanf("%d", &T);
    for (int ab = 1; ab <= T; ab++) {
        int N;
        scanf("%d", &N);
        printf("#%d %lld\n", ab, result[N]);
    }
}