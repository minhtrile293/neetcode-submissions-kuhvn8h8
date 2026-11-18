class KthLargest {
private:
    int kth;
    multiset<int> store;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(int i = 0; i < nums.size(); i++){
            store.insert(nums[i]);
        }
    }
    
    int add(int val) {
        store.insert(val);
        int k = kth;
        for(auto it = store.rbegin(); it != store.rend(); it++){
            k--;
            if(k == 0)
                return *it;
        }
    }
};
