#include "linked_stack.h"

template<typename T>
void reverse_stack_recursively(Stack<T> &stack) {

    if(stack.is_empty()){
        return;
    }
    else{
        T popped = stack.peek();
        stack.pop();
        reverse_stack_recursively(stack);

        helper_reverse(stack, popped);
    }

}
template<typename T>
void helper_reverse(Stack<T> &stack, T lastPop){
    if(stack.is_empty()){
        stack.push(lastPop);
    }
    else{
        T popped = stack.peek();
        stack.pop();
        helper_reverse(stack, lastPop);
        stack.push(popped);
    }

}