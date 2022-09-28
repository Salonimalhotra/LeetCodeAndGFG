class Solution
{
    public:
        bool isOneBitCharacter(vector<int> &bits)
        {

            bool check = false;
            for (int i = 0; i < bits.size(); i++)
            {
                if (check == true)
                {
                    if (i == bits.size() - 1)
                    {
                        return false;
                    }
                    else
                    {
                        check = false;
                    }
                }
                else if(check==false){
                    if(i==bits.size()-1){
                        return true;
                    }
                    else{
                        if(bits[i]==0){
                            check=false;
                        }
                        else{
                            check=true;
                        }
                    }
                }
            }
            return true;
        }
};