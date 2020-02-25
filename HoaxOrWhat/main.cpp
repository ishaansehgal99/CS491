#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    char *input = nullptr;
    size_t size = 0;

    while(getline(&input, &size, stdin) != EOF){
        int num_lines = strtol(input, nullptr, 10);
        if(num_lines == 0) return 0;
        int res = 0;

        vector<int> bills;
        for(size_t i = 0; i < num_lines; i++){
            getline(&input, &size, stdin);

            char *tok = strtok(input, " ");
            int nums = strtol(tok, nullptr, 10);

            for(size_t num = 0; num < nums; num++){
                tok = strtok(nullptr ," ");
                int add = strtol(tok, nullptr, 10);
                bills.push_back(add);
            }

            sort(bills.begin(), bills.end());

            res += bills.back() - bills.front();
            bills.erase(bills.begin(), bills.begin() + 1);
            bills.pop_back();
        }
        printf("%d\n", res);
    }

    return 0;
}
