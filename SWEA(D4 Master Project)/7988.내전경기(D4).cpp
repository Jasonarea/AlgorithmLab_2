#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int color[101];
vector<int> a[101];
int temp;

void dfs(int node, int c) {
    color[node] = c;

    for (int i = 0; i < a[node].size(); i++) {
        int next = a[node][i];
        if (color[next] == 0) {
            dfs(next, 3 - c);
        }
    }
}

int main(void)
{
    int tc;
    scanf("%d", &tc);

    for(int tt = 1;tt<=tc;tt++) {
        int combiNum;
        vector<pair<string, string>> combi;
        scanf("%d", &combiNum);

        for(int i = 0;i<temp;i++) {
            a[i].clear();
            color[i] = 0;
        }

        vector<string> list;
        while(combiNum--) {
            string u, v;
            cin >> u >> v;
            list.push_back(u);
            list.push_back(v);
            combi.emplace_back(u, v);
        }
        sort(list.begin(), list.end());
        list.erase(unique(list.begin(), list.end()), list.end());


        for(int i = 0;i<combi.size();i++) {
            string u = combi[i].first;
            string v = combi[i].second;
            int first = 0, second = 0;

            for(int j = 0;j<list.size();j++) {
                if(list[j] == u) first = j;
                else if(list[j] == v) second = j;
            }
            a[first].push_back(second);
            a[second].push_back(first);
        }

        for(int i = 0;i<list.size();i++) {
            if(color[i] == 0)
                dfs(i, 1);
        }

        bool ok = true;
        for(int i = 0;i<list.size();i++) {
            for(int j = 0;j<a[i].size();j++) {
                int k = a[i][j];
                if(color[i] == color[k])
                    ok = false;
            }
        }
        temp = list.size();
        printf("#%d ", tt);
        puts(ok?"Yes":"No");
    }

    return 0;
}