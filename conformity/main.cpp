#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <sstream>


int main() {

    std::unordered_map<int, int> map;
    int input[5];

    int x = 0;
    scanf("%d", &x);

    while(x != 0){
        int max = 0;
        for(int i = 0; i < x; i++){

            for(int y = 0; y < 5; y++){
                scanf("%d", &input[y]);
            }

            std::sort(input, input + 5);

            long long int num = 0;
            for (int w = 0; w < 5; w++) num = num * 1000 + input[w];


            if (map.find(num) != map.end()) {
                map[num]++;
            } else {
                map[num] = 1;
            }

            if(map[num] > max)
                max = map[num];


        }
        int ans = 0;
        for(const auto &k:  map){
            if(k.second == max) ans += max;
        }
        printf("%d\n", ans);

        scanf("%d", &x);

        map.clear();
    }


    return 0;
}