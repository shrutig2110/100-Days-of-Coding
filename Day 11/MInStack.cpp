class MinStack {
public:
    stack<int> s;
        stack<int> mins;
        int min_ele = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(!mins.empty())
        {
            if(mins.top()>val)
                mins.push(val);
            else{
                mins.push(mins.top());
            }
        }
        else{
            mins.push(val);
        }
        
    }
    
    void pop() 
    {
           s.pop(); 
           mins.pop();
        
    }
    
    int top() {
        if(!s.empty())
        {
            return s.top();
           // s.pop(); 
        }
        else{
            return -1;
        }
    }
    
    int getMin() {
        return mins.top(); 
    }
};
