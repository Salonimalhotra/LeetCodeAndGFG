class Solution {
public:
    long  long int mySqrt(int x) {
     int s=0;
     int e=x;
	  long long int ans;
	while(s<=e){
		long long int mid=(s+(e-s)/2);
        if(mid*mid==x){
            return mid;
        }
		else if(mid*mid>x){
			e=mid-1;
		}
		else if(mid*mid<x){
			ans=mid;
			s=mid+1;
		}
	}
	
	return ans;
    }
};