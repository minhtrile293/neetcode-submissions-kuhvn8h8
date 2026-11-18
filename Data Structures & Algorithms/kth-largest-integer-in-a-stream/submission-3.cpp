class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(int num : nums){
            minHeap.push(num);
            if(minHeap.size() > k)
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > kth)
            minHeap.pop();
        return minHeap.top();
    }
};
