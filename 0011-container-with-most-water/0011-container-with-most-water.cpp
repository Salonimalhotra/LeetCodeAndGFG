class Solution
{
    public:
        int maxArea(vector<int> &height)
        {
            int left = 0;
            int right = height.size() - 1;
            int maxAns = INT_MIN;
            while (left < right)
            {
                int area = min(height[left], height[right]) *(right - left);
                maxAns = max(maxAns, area);
                if (height[left] < height[right])
                {
                    left++;
                }
                else if (height[left] > height[right])
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
            return maxAns;
        }
};