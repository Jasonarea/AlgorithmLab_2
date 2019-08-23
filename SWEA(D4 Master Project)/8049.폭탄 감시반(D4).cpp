#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#define FIRST   "FF"
#define SECOND  "FC"

using namespace std;

int main(void)
{
    int tc;
    scanf("%d", &tc);

    bool start;

    for(int tt = 1;tt<=tc;tt++) {
        printf("#%d ", tt);
        string str;
        cin >> str;
        bool ans = true;
        int idx = 0;

        while(idx < str.length()) {
            string substr = str.substr(idx, 2);
            if (substr == FIRST) start = true;    // true : 위에 폭탄
            else if (substr == SECOND) start = false;         //false : 아래 폭탄
            else {
                ans = false;
                puts("NOTHING"); // 폭탄이 아닌경우
                break;
            }

            if (start) {
                string base = "MCM";
                int i, j;
                for (i = idx + 2; i< str.length() && str[i] != 'M'; i++) {
                    if (str[i] != 'F') {
                        ans = false;
                        break;
                    }
                }
                string substring = str.substr(i, 3);
                if (substring != base) ans = false;

                for (j = i + 3; j < str.length() && str[j] != 'F'; j++) {
                    if (str[j] != 'M') {
                        ans = false;
                        break;
                    }
                }

                idx = j;
            }
            else {
                string base = "MF";
                int i;
                for (i = idx + 2; i < str.length() && str[i] != 'M'; i++) {
                    if (str[i] != 'C') {
                        ans = false;
                        break;
                    }
                }
                string substring = str.substr(i, 2);
                if (substring != base) ans = false;
                idx = i + 2;
            }
            if (!ans) {
                puts("NOTHING!");
                break;
            }
        }
        if(ans) puts("DETECTED!");
    }

    return 0;
}