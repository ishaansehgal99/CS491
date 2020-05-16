#include <iostream>
#include <string>

#include <vector>
#include <stack>

#include <cstdio>

using namespace std;

int main() {
    string input;


    int case_num = 1;
    while(getline(cin, input) && input != "end"){
        if(input[input.length() - 1] == '\n'){
            input[input.length() - 1] = '\0';
        }

        vector<string> stacks;

        for(char i : input){
            string in_char(1, i);
            if(stacks.empty() || in_char > stacks.back()) {
                stacks.push_back(in_char);
            } else {
                int idx = 0;

                while (idx < (int)stacks.size()) {
                    if(in_char <= stacks[idx]){
                        stacks[idx] = in_char;
                        break;
                    }
                    idx++;
                }
            }
        }

        printf("Case %d: %lu\n", case_num++, stacks.size());
    }


    return 0;
}
