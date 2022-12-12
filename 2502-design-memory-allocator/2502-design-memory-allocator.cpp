class Allocator {
public:
    int * arr;
    int capacity;
    
    Allocator(int n) {
        arr=new int[n];
        for(int i=0;i<n;i++){
          arr[i]=0;
        }
        capacity=n;
      
    }
    
    int allocate(int size, int mID) {
        if(size>capacity){
          return -1;
        }
        int i=0;       
        while(i<capacity){
          if(arr[i]==0){
            int temp=0;
            while(temp!=size && i<capacity && arr[i]==0){
              i++;
              temp++;
            }
            if(temp==size){              
              while(temp!=0){
                arr[--i]=mID;
                temp--;
              }
              return i;
            }
            else{
              i++;
            }
          }
          else{
            i++;
          }
        }
      return -1;
    }
    
    int free(int mID) {
    int cnt=0;
     for(int i=0;i<capacity;i++){
       if(arr[i]==mID){
         arr[i]=0;
         cnt++;
       }
     }   
      return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */