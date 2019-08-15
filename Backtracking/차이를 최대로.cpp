#include <cstdio>
using namespace std;

int n;
int arr[10];
bool check[10];
int ans = 0;

int abs(int a) {
    return (a<0)?-a:a;
}

int diff(int *res) {
    int sum = 0;

    for(int i = 0;i<n - 1;i++)
        sum += abs(res[i] - res[i + 1]);

    return sum;
}

void solve(int index, int *res) {
    // base condition
    if(index == n) {
        int temp = diff(res);
        if(ans < temp) {
            ans = temp;
            return;
        }
    }


    // recursive
    for(int i = 0;i<n;i++) {
        if(!check[i]) {
            res[index] = arr[i];
            check[i] = true;
            solve(index + 1, res);
            check[i] = false;
        }
    }
}

int main(void)
{
    scanf("%d", &n);
    for(int i = 0;i<n;i++)
        scanf("%d", &arr[i]);

    int index = 0;
    int *res = new int[n];

    solve(index, res);

    printf("%d\n", ans);

    return 0;
}