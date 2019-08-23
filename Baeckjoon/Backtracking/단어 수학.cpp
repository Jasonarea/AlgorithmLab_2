#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int Max = 0;
int n;
bool check[9];
bool alpha[26];

vector<char> alphabet;

int getSum(map<char, int> &map, vector<string> &str) {

    int sum = 0;

    for(int i = 0;i<n;i++) {
        int num = 0;
        for(int j = 0;j<str[i].length();j++) {
            num *= 10;
            num += map[str[i][j]];
        }
        sum += num;
    }

    return sum;

}

void wordMath(int index, map<char, int> &map, vector<string> &str) {

    if(index == alphabet.size()) {
        int sum = getSum(map, str);
        if(Max < sum)
            Max = sum;
        return;
    }


    int len = alphabet.size();

    for(int i = 9;i>9-len ;i--) {
        if(!check[i]) {
            check[i] = true;
            map.insert(make_pair(alphabet[index], i));
            wordMath(index + 1, map, str);
            check[i] = false;
            map.erase(alphabet[index]);
        }
    }
}

int main(void)
{
    scanf("%d", &n);

    vector<string> str(n);

    for(int i = 0;i<n;i++)
        cin >> str[i];

    for(int i = 0;i<str.size();i++) {   // 사용하는 알파벳만 추려내서 벡터에 넣기.
        for(int j = 0;j<str[i].length();j++)
            if(!alpha[str[i][j] - 'A']) {
                alphabet.push_back(str[i][j]);
                alpha[str[i][j]-'A'] = true;
            }
    }

    map<char, int> map;
    sort(alphabet.begin(), alphabet.end());
    int index = 0;
    wordMath(index, map, str);

    printf("%d\n", Max);

    return 0;
}