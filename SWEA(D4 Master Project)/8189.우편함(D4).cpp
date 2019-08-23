#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
    int tc;
    scanf("%d", &tc);

    for (int tt = 1; tt <= tc; tt++) {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);
        // n : 편지 갯수 , a이상의 편지가 오거나 b시간이 지나면 현재까지 온 편지 / 2갯수의 편지를 읽는다.
        queue<int> q, post;
        for (int i = 0; i < n; i++) {
            int time;
            scanf("%d", &time);
            q.push(time); // 온 편지마다 queue에 푸쉬
            post.push(time);
        }

        // 시간이 지나간다
        int curTime = 0;
        vector<int> ans;
        queue<int> curPost;
        while (!q.empty()) {
            curTime++;
            if (!post.empty() && post.front() == curTime) {
                curPost.push(post.front());
                post.pop();
            }

            // 현재 쌓인 우편물이 A개 이상이거나 가장 오래된 우편물이 b시간이 지나면
            if (curPost.size() >= a || curTime - q.front() == b) {
                double len = (double)curPost.size()/2;
                for (int i = 0; i < len; i++) {
                    ans.push_back(curTime);
                    q.pop();
                    curPost.pop();
                }
            }
        }

        printf("#%d ", tt);
        for(int i = 0;i<ans.size();i++)
            printf("%d ", ans[i]);
        puts("");
    }

    return 0;
}