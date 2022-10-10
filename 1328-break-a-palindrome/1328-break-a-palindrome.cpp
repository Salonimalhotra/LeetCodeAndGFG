class Solution
{
    public:
        bool helper(string palindrome)
        {
            for (int i = 0; i < palindrome.size(); i++)
            {
                if (palindrome[i] != 'a') return true;
            }
            return false;
        }
    string breakPalindrome(string palindrome)
    {
        if (palindrome.size() == 0 || palindrome.size() == 1) return "";

        bool check = false;
        int i = 0;
        for (int i = 0; i < palindrome.size(); i++)
        {
            if (palindrome[i] != 'a')
            {
                char ch = palindrome[i];
                palindrome[i] = 'a';
                bool ans = helper(palindrome);
                if (ans == false)
                {
                    palindrome[i] = ch;
                }
                else
                {  
                     check = true;
                    return palindrome;
                }
            }
        }

        if (check != true)
        {
            for(int i=palindrome.size()-1;i>=0;i--){
                if(palindrome[i]=='a'){
                  palindrome[i]='b';
                  break;
                }
            }
        }
        return palindrome;
    }
};