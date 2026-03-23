// https://leetcode.com/problems/implement-queue-using-stacks/description/

#include <vector>

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        in_stack.push_back(x);
    }
    
    int pop() {
        if(out_stack.empty()) {
            Refill();
        }
        int res = out_stack.back();
        out_stack.pop_back();
        return res;
    }
    
    int peek() {
        if(out_stack.empty()) {
            Refill();
        }
        int res = out_stack.back();
        return res;
    }
    
    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }

private:
    std::vector<int> in_stack;
    std::vector<int> out_stack;

    void Refill() {
        while(!in_stack.empty()) {
            int element = in_stack.back();
            in_stack.pop_back();
            out_stack.push_back(element);
        }
    }
};