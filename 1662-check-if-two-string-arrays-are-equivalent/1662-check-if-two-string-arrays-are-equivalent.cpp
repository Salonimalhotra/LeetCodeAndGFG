class Solution
{
    public:
        bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
        {
            string finalans1 = "";
            string finalans2 = "";

            for (int i = 0; i < word1.size(); i++)
            {
                finalans1.append(word1[i]);
            }
            for (int i = 0; i < word2.size(); i++)
            {
                finalans2.append(word2[i]);
            }
           
            if(finalans1==finalans2){
              return true;
            }
            
            else{
              return false;
            }
        }
  
};