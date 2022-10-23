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
        
        queue<string>q;
        int steps=1;
        q.push(startWord);
        mp.erase(startWord);
        
        while(q.size()!=0){
            int s=q.size();
            while(s--){
                 string top=q.front();
                 q.pop();
            
                 if(top==targetWord){
                return steps;
                 }
               
                for(int i=0;i<top.size();i++){
                    for(int j=0;j<=25;j++){
                        string word=top;
                        word[i]='a' + j;
                        if(mp.find(word)!=mp.end()){
                            q.push(word);
                            mp.erase(word);
                        }
                    }
                }
            }
            steps++;
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