#include <cstring>
#include <vector>
#include <stack>
#include <cstdio>
#include <set>
using namespace std;

int main() {
    char *input = nullptr;
    size_t size;

    int case_num = 1;
    while(getline(&input, &size, stdin) >= 0 && strcmp(input, "end") != 0){
        if(input[strlen(input) - 1] == '\n'){
            input[strlen(input) - 1] = '\0';
        }

        vector<stack<char> > stacks;

        for(size_t i = 0; i < strlen(input); i++){
            if(stacks.empty()){
                stack<char> tmp;
                tmp.push(input[i]);
                stacks.push_back(tmp);
            } else {
                size_t min_idx = -1;
                size_t min_dist = 100;

                for(size_t idx = 0; idx < stacks.size(); idx++){
                    size_t dist = stacks[idx].top() - input[i];
                    if(dist >= 0 && dist < min_dist){
                        min_dist = dist;
                        min_idx = idx;
                    }
                }

                if(min_idx != -1){
                    stacks[min_idx].push(input[i]);
                } else {
                    stack<char> tmp;
                    tmp.push(input[i]);
                    stacks.push_back(tmp);
                }
            }
        }

        set<char> unique_chars;
        for(size_t x = 0; x < strlen(input); x++)
            unique_chars.insert(input[x]);

        int res = unique_chars.size() < stacks.size() ? unique_chars.size() : stacks.size();
        printf("Case %d: %d\n", case_num, res);

        case_num++;
    }


    return 0;
}
