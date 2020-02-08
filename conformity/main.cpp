#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <sstream>


int main() {

    std::unordered_map<std::string, int> map;
    int max = 0;
    int input[5];

    int x = 0;
    scanf("%d", &x);

    while(x != 0){
        for(int i = 0; i < x; i++){

            for(int y = 0; y < 5; y++){
                scanf("%d", &input[y]);
            }

            std::sort(input, input + 5);
            std::stringstream ss;

            for(int z : input){
                ss << z;
            }

            std::string res = ss.str();


            if (map.find(res) != map.end()) {
                map[res] += 1;
                if(map[res] > max)
                    max = map[res];
            } else {
                map[res] = 1;
            }
        }

        if(max == 0){
            printf("%d\n", x);
        } else {
            printf("%d\n", max);
        }

        scanf("%d", &x);
        max = 0;
        std::fill_n(input, 5, 0);
        map.clear();
    }


    return 0;
}