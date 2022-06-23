// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++
#include<string>
string reverseWord(string str){
    
  //Your code here
  //Brute force Approach:-
  // time - O(n) && space is O(n)
//   string ans;
//   for(int i=str.size()-1;i>=0;i--){
//       ans.push_back(str[i]);
//   }

//   return ans;
// optimised - time -O(n) && space is O(1)
  int i=0;
  int j=str.size()-1;
  while(i<=j){
      char temp=str[i];
      str[i]=str[j];
      str[j]=temp;
      i++;
      j--;
  }
  return str;
}