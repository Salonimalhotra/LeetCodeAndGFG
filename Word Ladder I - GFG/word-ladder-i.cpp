//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_map<string,int>mp;
        for(auto i:wordList){
            mp[i]++;
        }
        
        
        queue<pair<string,int>>q;
        q.push(make_pair(startWord,1));
        mp.erase(startWord);
        
        while(q.size()!=0){
            pair<string,int> topElement=q.front();
            string str=topElement.first;
            int len=topElement.second;
            q.pop();
            if(str==targetWord){
                return len;
            }
            int s=q.size();
                for(int j=0;j<str.size();j++){
                    string word=str;
                    for(int k=0;k<=25;k++){
                        word[j]='a' + k;
                        if(mp.find(word)!=mp.end()){
                            q.push(make_pair(word,len+1));
                            mp.erase(word);
                        }
                    }
                }
            
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends