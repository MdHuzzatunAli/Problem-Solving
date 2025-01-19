#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zero = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) {
                zero++;
                continue;
            }
            product *= nums[i];
        }

        if(zero>1){
            for(int i=0; i<nums.size(); i++)    nums[i] = 0;
            return nums;    
        }

        if(zero==1){
            for(int i=0; i<nums.size(); i++) {
                if(nums[i]!=0)   nums[i] = 0;
                else            nums[i] = product;
            }
            return nums;    
        }

        for(int i=0; i<nums.size(); i++)    nums[i] = product / nums[i];
        return nums;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 2, 3, 4};
    bool first = true;

    Solution solution;

    vector<int> result = solution.productExceptSelf(nums);
    
    cout << "Result for {" << nums[0];
    for(int num : nums) {
        if(first){
            first = false;
            continue;
        }
        cout << ", " << num;
    }
    cout << "}: ";

    for (int num : result)     cout << num << " ";
    
    cout << endl;
}