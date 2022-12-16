class MyQueue {
public:
    MyQueue() {
    }
    
    void push(int x) {
        push_stack.push( x );
    }
    
    int pop() {
        if ( pop_stack.empty() )
        {
            while ( ! push_stack.empty() )
            {
                pop_stack.push( push_stack.top() );
                push_stack.pop();
            }
        }
        int result = pop_stack.top();
        pop_stack.pop();
        return result;
    }
    
    int peek() {
        if ( pop_stack.empty() )
        {
            while ( ! push_stack.empty() )
            {
                pop_stack.push( push_stack.top() );
                push_stack.pop();
            }
        }
        int result = pop_stack.top();
        return result;
    }
    
    bool empty() {
        return push_stack.empty() && pop_stack.empty();
    }
private:
    std::stack<int> push_stack;
    std::stack<int> pop_stack;
};