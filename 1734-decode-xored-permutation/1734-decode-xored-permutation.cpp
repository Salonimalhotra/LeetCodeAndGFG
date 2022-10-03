class Solution
{
    public:
        vector<int> decode(vector<int> &encoded)
        {
            int n = encoded.size();
            vector<int> perm(n + 1, 0);

            int x = 1;
            for (int i = 2 ; i<=n+1; i++) x = x ^ i;

            for (int i = 1; i < encoded.size(); i += 2) x = x ^ encoded[i];

            perm[0] = x;
            for (int i = 1; i < encoded.size() + 1; i++)
            {
                perm[i] = encoded[i - 1] ^ perm[i - 1];
            }
            return perm;
        }
};