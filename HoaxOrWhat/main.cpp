#include <queue>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    char *input = nullptr;
    size_t size = 0;

    while(getline(&input, &size, stdin) != EOF){
        int num_lines = atoi(input);
        if(num_lines == 0) return 0;
        int res = 0;

        priority_queue<int> q1;
        priority_queue<int, vector<int>, greater<int>> q2;
        unordered_map<int, int> map;

        for(size_t i = 0; i < num_lines; i++){
            getline(&input, &size, stdin);

            char *tok = strtok(input, " ");
            int nums = atoi(tok);

            for(size_t num = 0; num < nums; num++){
                tok = strtok(nullptr ," ");
                int add = atoi(tok);
                map[add] = (map.find(add) != map.end()) ? map[add] + 1 : 1;
                q1.push(add);
                q2.push(add);
            }

            int q1_top = q1.top();
            int q2_top = q2.top();
            while(q1.size() > 1 && map.find(q1_top) == map.end()){
                q1.pop();
                q1_top = q1.top();
            }

            while(q2.size() > 1 && map.find(q2_top) == map.end()){
                q2.pop();
                q2_top = q1.top();
            }

            map[q1_top]--;
            if(map[q1_top] == 0) map.erase(q1_top);

            map[q2_top]--;
            if(map[q2_top] == 0) map.erase(q2_top);


            res += q1_top - q2_top;
        }
        printf("%d\n", res);
    }

    return 0;
}
