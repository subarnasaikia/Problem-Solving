//  Worst time complexity O(n^2)

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> pref_sum(arr.size());
        int ans  = 0, odd = 3;
        pref_sum[0] = arr[0];
        for(int i=1; i<arr.size(); i++){
            pref_sum[i] = pref_sum[i-1] + arr[i];
        }
        ans = pref_sum[arr.size()-1];
        if(arr.size() <3) return ans;

        while(odd <= arr.size()){
            ans += pref_sum[odd-1];
            int k = odd;
            while(k < arr.size()){
                ans += (pref_sum[k] - pref_sum[k-odd]);
                k++;
            }
            odd += 2;
        }
        return ans;

    }
};

// Time Complexity O(n)

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += (((n-i)*(i+1) + 1)/2) * arr[i];
        }
        return ans;
    }
};