class SparseVector {
public:
    vector<int>num;
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++){
            this->num.push_back(nums[i]);
        }
        
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int product=0;
        for(int i=0;i<vec.num.size();i++){
            product+= this->num[i] * vec.num[i];
        }
        return product;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);