#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main(void)
{
    int T;
    scanf("%d", &T);

    for(int tt = 1;tt<=T;tt++) {
        long long n;
        scanf("%lld", &n);

        vector<long long> res;

        int fiveIdx =0;
        int fiveMinIdx = 0;
        int curIdx = 2;
        long long choiyaksu = 0;

        while(choiyaksu < 1000000000) {
            for (int i = fiveMinIdx; i < curIdx; i++) {
                choiyaksu = pow(2, i) * pow(5, fiveIdx);
                res.push_back(choiyaksu);
            }
            curIdx++;
            fiveIdx++;
            if(fiveIdx >= 4) fiveMinIdx++;
        }

        int ans = 0;
        for(int i = 0;i<res.size();i++) {
            if(res[i] <= n)
                ans++;
        }
        printf("#%d %d\n", tt, ans);
    }

    return 0;
}