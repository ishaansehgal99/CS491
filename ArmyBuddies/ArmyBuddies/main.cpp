//
//  main.cpp
//  ArmyBuddies
//
//  Created by Ishaan Sehgal on 2/4/20.
//  Copyright © 2020 Ishaan Sehgal. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

struct node {
    int data;
    node* prev;
    node* next;
};

int main(int argc, const char * argv[]) {
    std::unordered_map<int, node*> soldiers;
    
    int S, B;
    while(scanf("%d %d", &S, &B) != EOF){
        if(S == 0 && B == 0){
            return 0;
        }
        node n[S+2];
        for(int i = 1; i <= S; i++){
            node *curr = &n[i];
            curr->data = i;
            curr->prev = &n[i-1];
            curr->next = &n[i+1];
            
            if(i == 1) curr->prev->data = -1;
            else curr->prev->data = i - 1;
            
            if(i == S) curr->next->data = -1;
            else curr->next->data = i + 1;
            
            soldiers[i] = curr;
        }
        int L, R;
        for(int rep = 0; rep < B; rep++){
            scanf("%d %d", &L, &R);
            node *left = soldiers[L];
            node *right = soldiers[R];
            
            node *left_prev = left->prev;
            node *right_next = right->next;
            
            left_prev->next = right_next;
            right_next->prev = left_prev;
            
            
            if (left_prev-> data == -1){
                std::cout << "*";
            } else {
                std::cout << left_prev->data;
            }
            
            std::cout << " ";
            
            if (right_next-> data == -1){
                std::cout << "*";
            } else {
                std::cout << right_next->data;
            }
            std::cout << std::endl;
        }
        
        soldiers.clear();
        std::cout << "-" << std::endl;
    }
    
    return 0;
}
