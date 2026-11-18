class KthLargest {
private:
    vector<int>store;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        sort(nums.begin(), nums.end());
        store = nums;
    }
    
    int add(int val) {
        store.push_back(val);
        sort(store.begin(), store.end());
        return store[store.size() - kth];
    }
};
