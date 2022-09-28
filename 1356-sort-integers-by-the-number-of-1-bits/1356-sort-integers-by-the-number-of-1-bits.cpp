class Solution
{
    public:
        bool static helper(int i1, int i2)
        {
            int cnt1 = 0;
            int cnt2 = 0;
            for (int i = 0; i < 32; i++)
            {
                int m = 1 << i;
                if ((i1 & m) != 0) cnt1++;
                if ((i2 & m) != 0) cnt2++;
            }
            if (cnt1 < cnt2)
            {
                return true;
            }
            else if(cnt1==cnt2){
                if(i1<i2) return true;
                else{
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), helper);
        return arr;
    }
};