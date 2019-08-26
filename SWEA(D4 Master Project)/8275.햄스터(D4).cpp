#include <iostream>
#include <vector>

using namespace std;
const int MAX = 15;

struct Condition {
    int start;
    int end;
    int val;
};

int cntOfHamsters[MAX];
int n, x, m;
vector<Condition> v;
vector<int> ans;

void dfs(int start) {
    // base condition
    if(start > n) {     // cntOfHamster에 n개의 우리의 값이 들어왔따면
        for(int i = 0; i < v.size(); i++) { // 기록들을 살펴보면서
            Condition c = v[i];
            int tmp = 0;
            for(int j = c.start; j <= c.end; j++)
                tmp += cntOfHamsters[j];

            if(tmp != c.val) return;
        }

        if(!ans.empty()) {
            int total = 0, totalAns = 0;

            for(int i = 0;i<ans.size();i++) totalAns += ans[i];
            for(int i = 1; i <= n; i++) total += cntOfHamsters[i];

            if(totalAns <= total) {
                ans.clear();        // 가장 합이 큰값으로 ans 세팅
                for(int i = 1; i <= n; i++)
                    ans.push_back(cntOfHamsters[i]);

            }
        }
        else {
            for(int i = 1; i <= n; i++)
                ans.push_back(cntOfHamsters[i]);
        }

        return;
    }


    // recursive
    for(int i = x; i >=0; i--) {
        cntOfHamsters[start] = i;
        dfs(start+1);
    }
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        v.clear();
        ans.clear();
        scanf("%d %d %d", &n, &x, &m);

        for(int i = 0 ; i < m; i++) {
            Condition c;
            int l, r, s;
            scanf("%d %d %d", &l, &r, &s);
            c.start = l;
            c.end = r;
            c.val = s;
            v.push_back(c);
        }       // 기록들을 struct 벡터 형태로 저장

        dfs(1); // 모든 케이스들을 살펴보면서 기록과 맞는것과 매칭

        printf("#%d ", tc);
        if(ans.size() == 0) {
            printf("-1");
        } else {
            for(int i = 0; i < ans.size(); i++) {
                printf("%d ", ans[i]);
            }
        }
        printf("\n");

    }


    return 0;
}