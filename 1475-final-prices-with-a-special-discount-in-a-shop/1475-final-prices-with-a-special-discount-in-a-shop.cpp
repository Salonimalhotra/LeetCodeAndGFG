class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>finalAns(n,0);
        finalAns[n-1]=prices[n-1];
        stack<int>st;
        st.push(prices[n-1]);
        int i=n-2;
        while(i>=0){
            if(st.size()==0){
                finalAns[i]=prices[i];
                st.push(prices[i]);
                i--;
            }
            else{
                if(st.top()<=prices[i]){
                    finalAns[i]=prices[i]-st.top();
                    st.push(prices[i]);
                    i--;
                }
                else if(st.top()>prices[i]){
                    while(st.size()!=0 && st.top()>prices[i]){
                        st.pop();
                    }
                    if(st.size()==0){
                      finalAns[i]=prices[i];
                      st.push(prices[i]);
                    }
                    else{
                     finalAns[i]=prices[i]-st.top();
                     st.push(prices[i]);
                    }
                    i--;
                }
            }
        }
        
        return finalAns;
        
    }
};