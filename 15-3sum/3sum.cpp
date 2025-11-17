class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        //BubbleSort algo to sort the array
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - i - 1; j++) {
                if(nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }

        for(int i = 0; i < n-2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            //if the smmalest number is +ve
            if(nums[i] > 0){
                break;
            }

            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];

            while(left < right) {
                int currSum = nums[left] + nums[right];

                if(currSum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
              
                    //Skip value for left
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    //Skip value for right
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }
                else if(currSum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return result;
    }
};