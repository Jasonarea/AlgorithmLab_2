#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int result[1000010];

int main(void)
{
    int T;
    scanf("%d", &T);

    for(int tt = 1;tt<=T;tt++) {
        int n;
        scanf("%d", &n);
        memset(result, 0, sizeof(result));

        int *arr = new int[n];

        for(int i = 0;i<n;i++)
            scanf("%d", &arr[i]);

        sort(arr, arr + n);


        int h = n;
        for(int i = 0;i<arr[0];i++)
            result[i] = h;
        for(int i = 0;i<n;i++) {
            if(!result[arr[i]]) {
                result[arr[i]] = h;
                for (int j = arr[i - 1] + 1; j < arr[i]; j++)
                    result[j] = h;
            }
            h--;
        }

        int ans = 0;
        for(int i = 1;i<=arr[n-1];i++) {
            if(result[i] >= i && i > ans)
                ans = i;
        }
        printf("#%d %d\n",tt, ans);
    }

    return 0;
}