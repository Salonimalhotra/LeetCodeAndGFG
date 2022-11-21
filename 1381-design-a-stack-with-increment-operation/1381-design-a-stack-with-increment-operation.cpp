class CustomStack
{
    public:
        stack<int> st;
    int size;
    int capacity;
    CustomStack(int maxSize)
    {
        size = 0;
        capacity = maxSize;
    }

    void push(int x)
    {
        if (size != capacity)
        {
            st.push(x);
            size++;
        }
    }

    int pop()
    {
        if (st.size() == 0)
        {
            return -1;
        }
        else
        {
            int topElement = st.top();
            st.pop();
            size--;
            return topElement;
        }
    }

    void increment(int k, int val)
    {

        stack<int> st1;
        if (st.size() < k)
        {
            stack<int> st1;
            while (st.size() != 0)
            {
                st1.push(st.top() + val);
                st.pop();
            }
            while (st1.size() != 0)
            {
                st.push(st1.top());
                st1.pop();
            }
        }
        else
        {
            int required = st.size() - k;
            while (st.size() != 0)
            {
                st1.push(st.top());
                st.pop();
            }
            while (st1.size() != required)
            {
                st.push(st1.top() + val);
                st1.pop();
            }
            while (st1.size() != 0)
            {
                st.push(st1.top());
                st1.pop();
            }
        }
    }
};

/**
 *Your CustomStack object will be instantiated and called as such:
 *CustomStack* obj = new CustomStack(maxSize);
 *obj->push(x);
 *int param_2 = obj->pop();
 *obj->increment(k,val);
 */