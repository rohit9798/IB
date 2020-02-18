Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.


vector<int> stack1, stack2;

MinStack::MinStack() {
    stack1.clear();
    stack2.clear();
}

void MinStack::push(int x) {
    
    stack1.push_back(x);
    if(stack2.empty() || x < stack2.back())
    {
        stack2.push_back(x);
    }
}

void MinStack::pop() {
    
    if(!stack1.empty())
    {
        if(stack2.back() == stack1.back())
        {
            stack2.pop_back();
        }
        stack1.pop_back();
    }
    return;
}

int MinStack::top() {
    
    if(!stack1.empty())
    {
        return stack1.back();
    }
    return -1;
}

int MinStack::getMin() {
    
    if(!stack2.empty())
    {
        return stack2.back();
    }
    return - 1;
}

