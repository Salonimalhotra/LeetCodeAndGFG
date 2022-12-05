class Solution
{
    public:
        long long dividePlayers(vector<int> &skill)
        {
            sort(skill.begin(), skill.end());
            int sum = skill[0] + skill[skill.size() - 1];
            long long chem = skill[0] *skill[skill.size() - 1];
            int start = 1;
            int end = skill.size() - 2;
            while (start < end)
            {
                if (skill[start] + skill[end] != sum)
                {
                    return -1;
                }
                else
                {
                    chem += skill[start] *skill[end];
                    start++;
                    end--;
                }
            }
          return chem;
        }
};