#include <iostream>
#include <climits>

using namespace std;

int main() {


    int participants;
    int budget;
    int hotels;
    int weeks;

    while(scanf("%d %d %d %d", &participants, &budget, &hotels, &weeks) != EOF){
        int min_price = INT_MAX;

        int price;
        int beds[weeks];
        for(int i = 0; i < hotels; i++){
            scanf( "%d", &price);
            for(int x = 0; x < weeks;x++){
                scanf( "%d", &beds[x]);
            }

            for (int y = 0; y < weeks; y++){
                if (beds[y] >= participants){
                    if(participants * price < min_price){
                        min_price = participants * price;
                    }
                }
            }
        }

        if(min_price < budget){
            printf("%d\n", min_price);
        } else {
            printf("%s\n", "stay home");
        }

    }

    return 0;
}