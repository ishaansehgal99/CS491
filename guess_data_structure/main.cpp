#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int num_lines = 0;

    while(scanf("%d", &num_lines) != EOF){
        stack<int> nums_stack;
        queue<int> nums_queue;
        priority_queue<int> nums_pqueue;
        int is_queue = 0, is_stack = 0, is_pqueue = 0;

        for(int i = 0; i < num_lines; i++){
            int in_out = 0, num = 0;
            scanf("%d %d", &in_out, &num);

            if(in_out == 1){
                nums_stack.push(num);
                nums_queue.push(num);
                nums_pqueue.push(num);
            } else {
                if(nums_stack.size() == 0 || nums_pqueue.size() == 0|| nums_queue.size() == 0){
                    is_queue = 2; is_stack = 2; is_pqueue = 2;
                    int x = 0;
                    while(x < num_lines){
                        scanf("%d %d", &in_out, &num);
                        x++;
                    }
                    break;
                }

                int stack_top = nums_stack.top();
                nums_stack.pop();

                int queue_top = nums_queue.front();
                nums_queue.pop();

                int pqueue_top = nums_pqueue.top();
                nums_pqueue.pop();

                if (is_stack == 0)
                    is_stack = (stack_top == num) ? 1 : 2;
                if (is_queue == 0)
                    is_queue = (queue_top == num) ? 1 : 2;
                if(is_pqueue == 0)
                    is_pqueue = (pqueue_top == num) ? 1 : 2;

                if (is_stack == 1)
                    is_stack = (stack_top == num) ? 1 : 2;
                if (is_queue == 1)
                    is_queue = (queue_top == num) ? 1 : 2;
                if(is_pqueue == 1)
                    is_pqueue = (pqueue_top == num) ? 1 : 2;

            }
        }

        if(is_queue == 0 || is_stack == 0 || is_pqueue == 0){
            printf("not sure\n");
        } else if(is_queue == 2 && is_stack == 2 && is_pqueue == 2){
            printf("impossible\n");
        } else {
            if((is_stack == 1 && is_queue == 1) || (is_stack == 1 && is_pqueue == 1)
            || (is_queue == 1 && is_pqueue == 1)){
                printf("not sure\n");
            } else {
                if(is_stack == 1){
                    printf("stack\n");
                } else if(is_queue == 1){
                    printf("queue\n");
                } else {
                    printf("priority queue\n");
                }
            }
        }

    }

    return 0;
}
