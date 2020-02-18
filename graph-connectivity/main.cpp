#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

void find_maximal_graphs(const set<char>& vertices, vector<string> edges);
char find_parent(char child, unordered_map<char, char> &map);

int main() {

    char *input = nullptr;
    size_t size;

    getline(&input, &size, stdin);
    if(input == nullptr || isdigit(input[0]) == 0) return 0;
    int num_cases = atoi(input);

    getline(&input, &size, stdin);

    set<char> vertices;
    vector<string> edges;
    int count = 0;

    while(getline(&input, &size, stdin) >= 0){
        if(strlen(input) > 1 && input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        if(strcmp(input, "\n") == 0){
            if(count < num_cases){
                find_maximal_graphs(vertices, edges);
                vertices.clear();
                edges.clear();
                count++;
                if(count < num_cases){
                    printf("\n");
                }
            }

        } else if(strlen(input) == 1) {
            int i = 0;
            while(char('A' + i) != input[0]) {
                vertices.insert(char('A' + i));
                i++;
            }
            vertices.insert(char('A' + i));
        } else {
            edges.emplace_back(input);
            vertices.insert(input[0]);
            vertices.insert(input[1]);
        }
    }

    if(count < num_cases)
        find_maximal_graphs(vertices, edges);


    return 0;
}

char find_parent(char child, unordered_map<char, char> &map){
    if(map[child] == '\0') return child;
    return find_parent(map[child], map);
}

void find_maximal_graphs(const set<char>& vertices, vector<string> edges){
    unordered_map<char, char> disjoint_set;

    for (auto elem : vertices) {
        disjoint_set[elem] = '\0';
    }

    for(auto & edge : edges){
        char x = find_parent(edge[0], disjoint_set);
        char y = find_parent(edge[1], disjoint_set);
        if(x != y) disjoint_set[x] = y;
    }

    int num_sets = 0;
    for(auto element: disjoint_set){
        if(element.second == '\0') num_sets++;
    }

    printf("%d\n", num_sets);
}
