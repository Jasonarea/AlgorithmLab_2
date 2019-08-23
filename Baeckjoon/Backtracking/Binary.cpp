#include <cstdio>
using namespace std;

// binary
int res[101];
int n, k;

void binary(int index, int oneCo, int res[]) {
    //base condition
    if(oneCo == k) {
        for(int i = 0;i<n;i++)
            printf("%d", res[i]);
        puts("");
        return;
    }
    else if(index >= n) return;

    // recursive
    res[index] = 1;
    binary(index + 1, oneCo + 1, res);
    res[index] = 0;
    binary(index + 1, oneCo, res);
}

int main(void)
{
    scanf("%d %d", &n, &k);

    int index = 0, oneCo = 0;
    binary(index, oneCo, res);

    return 0;
}