class MinStack {
private:
    vector<int> mStack;
    int min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(!mStack.empty()){
            if(val < min)
                min = val;
        } else
            min = val;
        mStack.push_back(val);
    }
    
    void pop() {
        if(!mStack.empty())
        {
            int top = mStack.back();
            mStack.pop_back();
            if(top == min && !mStack.empty()){
                min = mStack[0];
                for(int i = 1; i < mStack.size(); i++){
                    if(mStack[i] < min)
                        min = mStack[i]; 
                }
            }
        }
    }
    
    int top() {
        if(!mStack.empty())
            return mStack.back();
    }
    
    int getMin() {
        return min;
    }
};
