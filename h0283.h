//
// Created by 项雅丽 on 2019/11/19.
//

#ifndef NOWCODER_283_H
#define NOWCODER_283_H
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

namespace h0283{
    class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int countZero = 0;
            for (int i=0;i<nums.size();i++){
                if (nums[i]==0){
                    countZero++;
                } else{
                    nums[i-countZero] = nums[i];
                }
            }
            while (countZero>0){
                nums[nums.size()-countZero]=0;
                countZero--;
            }
        }
    };
}


using namespace std;

#endif //NOWCODER_283_H
