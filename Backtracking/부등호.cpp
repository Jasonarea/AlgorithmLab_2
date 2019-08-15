#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
char letter[10];
bool check[10];
vector<string> ans;

bool isPossible(int *res) {

    for(int i = 0;i<n;i++) {
        if(res[i] > res[i+1] && letter[i] == '<')
            return false;
        else if(res[i] < res[i + 1] && letter[i] == '>')
            return false;
    }

    return true;
}

void solve(int index, int *res) {
    // base condttion
    if(index == n + 1) {
        if(isPossible(res)) {
            string temp;
            for(int i = 0;i<n + 1;i++)
                temp += to_string(res[i]);
            ans.push_back(temp);
            return;
        }
    }
    if(index > n + 1) return;


    // recursive
    for (int i = 0; i < 10; i++) {
        if(!check[i]) {
            res[index] = i;
            check[i] = true;
            solve(index + 1, res);
            check[i] = false;
        }
    }
}


int main(void)
{
    cin >> n;

    for(int i = 0;i<n;i++)
        cin >> letter[i];

    int index = 0;
    int *res = new int[15];
    solve(index, res);

    cout << ans[ans.size() - 1] << '\n' << ans[0] << '\n';

    return 0;
}