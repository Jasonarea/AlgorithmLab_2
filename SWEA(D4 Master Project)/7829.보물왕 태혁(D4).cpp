#include <cstdio>
#include <algorithm>
using namespace std;

int main(void)
{
    int T;
    scanf("%d", &T);

    for(int tt = 1;tt<=T;tt++) {
        int n;
        scanf("%d", &n);
        int *arr = new int[n];

        for(int i = 0;i<n;i++)
            scanf("%d", &arr[i]);

        sort(arr, arr + n);

        int ans = arr[0] * arr[n-1];
        printf("#%d %d\n", tt, ans);
    }

    return 0;
}