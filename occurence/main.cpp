#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {

    unordered_map<int,  vector<int> > node_map;
    int arr_elem = 0;

    while(scanf("%d", &arr_elem) != EOF) {
        int num_queries = 0;
        scanf("%d", &num_queries);

        int arr[arr_elem];

        for (int i = 0; i < arr_elem; i++) {
            scanf("%d", &arr[i]);
            if (node_map.find(arr[i]) != node_map.end()) {
                node_map[arr[i]].push_back(i + 1);
            } else {
                vector<int> a;
                a.push_back(i + 1);
                node_map[arr[i]] = a;
            }
        }

        for (int i = 0; i < num_queries; i++) {
            int num1 = 0, num2 = 0;
            scanf("%d", &num1);
            scanf("%d", &num2);
            if (node_map[num2].size() >= num1) {
                printf("%d\n", node_map[num2][num1 - 1]);
            } else {
                printf("%d\n", 0);
            }
        }
        node_map.clear();
    }


    return 0;
}

