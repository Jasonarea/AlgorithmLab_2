#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <iostream>
using namespace std;


int main(void)
{
    int T;
    scanf("%d", &T);

    for(int tt = 1;tt<=T;tt++) {
        int n;
        scanf("%d ", &n);
        vector<string> classmate;
        vector<pair<string, int>> findLeader;

        for(int i = 0;i<n;i++) {
            string name;
            getline(cin, name);
            classmate.push_back(name);
        }
        sort(classmate.begin(), classmate.end()); // classmate 사전순 소팅

        for(int i = 0;i<n;i++) {
            string name = classmate[i];
            vector<char> alpha;
            for(int j = 0;j<name.length();j++) {
                alpha.push_back(name[j]);
            }
            sort(alpha.begin(), alpha.end());
            alpha.erase(unique(alpha.begin(), alpha.end()), alpha.end());
            string alphaCo;
            for(int j = 0;j<alpha.size();j++) {
                if(isalpha(alpha[j]))
                    alphaCo += alpha[j];
            }
            findLeader.emplace_back(alphaCo, i);
        }


        int maxAlpha = 0;
        string ansAlpha;
        int resIndex = 0;
        for(int i = 0;i<findLeader.size();i++) {
            if(maxAlpha < findLeader[i].first.length()) {
                ansAlpha = findLeader[i].first;
                resIndex = findLeader[i].second;
                maxAlpha = findLeader[i].first.length();
            }
        }

        cout << "#" << tt << ' ' << classmate[resIndex] << '\n';
    }

    return 0;
}