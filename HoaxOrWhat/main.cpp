#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char *input = nullptr;
    size_t size = 0;

    while(getline(&input, &size, stdin) != EOF){
        int num_lines = stoi(input);
        if(num_lines == 0) return 0;
        unsigned long res = 0;

        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int> > min_heap;
        unordered_map<int, int> map;

        for(size_t i = 0; i < num_lines; i++){
            getline(&input, &size, stdin);

            char *tok = strtok(input, " ");
            int nums = stoi(tok);

            for(size_t num = 0; num < nums; num++){
                tok = strtok(nullptr ," ");
                int add = stoi(tok);
                map[add] = (map.find(add) != map.end()) ? map[add] + 1 : 1;
                max_heap.push(add);
                min_heap.push(add);
            }

            int q1_top = max_heap.top();
            max_heap.pop();
            while(map.find(q1_top) == map.end()){
                q1_top = max_heap.top();
                max_heap.pop();
            }

            int q2_top = min_heap.top();
            min_heap.pop();
            while(map.find(q2_top) == map.end()){
                q2_top = min_heap.top();
                min_heap.pop();
            }

            map[q1_top]--;
            if(map[q1_top] == 0) map.erase(q1_top);

            map[q2_top]--;
            if(map[q2_top] == 0) map.erase(q2_top);


            res += q1_top - q2_top;
        }
        printf("%lu\n", res);
    }

    return 0;
}
