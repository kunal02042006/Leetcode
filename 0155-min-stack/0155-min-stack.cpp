class MinStack {
    stack<long long> s;
    long long mini;

public:
    MinStack() {
        // Constructor
    }

    void push(int val) {
        if(s.empty()) {
            s.push(val);
            mini = val;
        }
        else {
            if(val < mini) {
                s.push(2LL * val - mini);
                mini = val;
            }
            else {
                s.push(val);
            }
        }
    }

    void pop() {
        if(s.empty()) {
            return;
        }

        long long curr = s.top();
        s.pop();

        if(curr < mini) {
            mini = 2 * mini - curr;
        }
    }

    int top() {
        if(s.empty()) {
            return -1;
        }

        long long curr = s.top();

        if(curr < mini) {
            return mini;
        }
        else {
            return curr;
        }
    }

    int getMin() {
        if(s.empty()) {
            return -1;
        }

        return mini;
    }
};