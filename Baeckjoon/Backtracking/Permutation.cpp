#include <cstdio>
using namespace std;

int n, k;
bool check[101];

void permutation(int index, int *res) {
    // base condition
    if(index == k) {
        for(int i = 0;i<k;i++)
            printf("%c", 'a' + res[i]);
        puts("");

        return;
    }

    // recursive
    for(int i = 0;i<n;i++) {
        if(!check[i]) {
            res[index] = i;
            check[i] = true;
            permutation(index + 1, res);
            check[i] = false;
        }
    }

}

int main(void)
{
    scanf("%d %d", &n, &k);

    int *res = new int[k];
    int index = 0;

    permutation(index, res);

    return 0;
}