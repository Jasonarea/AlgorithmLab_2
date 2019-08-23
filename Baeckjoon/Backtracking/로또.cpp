#include <cstdio>
#include <vector>
using namespace std;

//lotto
// backtracking에서 증가하는 수열을 만들때는 check와 for문을 사용하지 않는다.!

int *arr, n;
void lotto(int index, vector<int> &res) {
    // base condition
    if(res.size() == 6) {
        for(int i = 0;i<res.size();i++)
            printf("%d ", res[i]);
        puts("");
        return;
    }
    else if(index == n) return;

    // recursive
    res.push_back(arr[index]);
    lotto(index + 1, res);
    res.pop_back();
    lotto(index + 1, res);
}

int main(void)
{
    while(true) {
        scanf("%d", &n);
        if (n == 0) return 0;

        arr = new int[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        int index = 0;
        vector<int> res;

        lotto(index, res);
        puts("");
    }

    return 0;
}