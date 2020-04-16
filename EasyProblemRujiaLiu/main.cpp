#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
int main() {
    int num_arr_elems = 0, num_queries;


    string curr_line;
    while(getline(cin, curr_line)) {
        sscanf(curr_line.c_str(), "%d %d", &num_arr_elems, &num_queries);

        getline(cin, curr_line);
        istringstream arr(curr_line);

        unordered_map<int, vector<int> > adj_list;
        int idx = 1;
        for (int i = 0; i < num_arr_elems; i++) {
            getline(arr, curr_line, ' ');
            int arr_elem = stoi(curr_line);
            if (adj_list.find(arr_elem) == adj_list.end()) {
                vector<int> occurrences{idx};
                adj_list[arr_elem] = occurrences;
            } else {
                adj_list[arr_elem].push_back(idx);
            }
            idx++;
        }

        int kth_occurence = 0, num = 0;
        for (int i = 0; i < num_queries; i++) {
            getline(cin, curr_line);
            sscanf(curr_line.c_str(), "%d %d", &kth_occurence, &num);
            if (adj_list.find(num) == adj_list.end() || adj_list[num].size() < kth_occurence) {
                printf("0\n");
            } else {
                printf("%i\n", adj_list[num][kth_occurence - 1]);
            }
        }
    }

    return 0;
}
