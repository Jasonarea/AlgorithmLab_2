#include <cstdio>
using namespace std;

// Division
int res[101];
int n;
int cot = 0;

void division(int index, int sum, int res[]) {
    // base condition
    if(sum == n) {
        for(int i = 0;i<index - 1;i++)
            printf("%d+", res[i]);
        printf("%d", res[index-1]);
        puts("");
        cot++;
        return;
    }
    else if(sum > n) return;

    // recursive
    for(int i = n - index;i>0;i--) {

        res[index] = i;
        sum += i;
        division(index + 1, sum, res);
        sum -= i;
    }
}

int main(void)
{
    scanf("%d", &n);

    int index = 0, sum = 0;
    division(index, sum, res);
    printf("%d\n", cot);

    return 0;
}