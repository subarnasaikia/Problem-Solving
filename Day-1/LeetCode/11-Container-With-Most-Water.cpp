class Solution {
public:
    int maxArea(vector<int>& height) {
        int Max = 0;
        // for(int i = 0; i<height.size(); i++){
        //     for(int j = i+1; j<height.size(); j++){
        //         Max = max(Max,((j - i) * min(height[i], height[j])) );
        //     }
        // }

        // using two pointers
        int left = 0, right = height.size() - 1;
        while( left < right){
            if(height[left] < height[right]){
                Max = max(Max,( (right - left) * height[left]));
                left++;
            }else if(height[left] > height[right]){
                Max = max(Max,( (right - left) * height[right]));
                right--;
            }else {
                Max = max(Max,( (right - left) * height[left]));
                left++;
                right--;
            }
        }

        
        return Max;
    }
};