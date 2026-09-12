class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>result(n);
        result[n - 1] = 0;

        for(int i = n - 2; i >= 0; i--){
            int indexS = i + 1;
            if(temperatures[i] < temperatures[indexS]){
                result[i] = 1;
                continue;
            }

            result[i] = 0;
            while(temperatures[i] >= temperatures[indexS] && result[indexS] != 0){
                indexS = indexS + result[indexS];
                if(temperatures[i] < temperatures[indexS]){
                    result[i] = indexS - i;
                    break;
                }
            }

        }
        return result;
    }
};
