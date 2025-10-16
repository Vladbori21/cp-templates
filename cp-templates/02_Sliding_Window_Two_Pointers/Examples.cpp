#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

public:

    //leetcode 167: two pointers(array is sorted)
    vector<int> twoSum(vector<int>& numbers, int target) {

        int i = 0, j = numbers.size() - 1;
        int sum = numbers[i] + numbers[j];

        while (sum != target && i < j) {

            if (sum > target)  j--;
            else  i++;

            sum = numbers[i] + numbers[j];

        }

        return { i + 1,j + 1 };
    }

    //leetcode 3: sliding window
    int lengthOfLongestSubstring(string s) {

        int count = 0;
        int left = 0, right = 0;
        unordered_map<char, int> mp;

        for (; right < s.size(); left++) {//"closing" window

            while (right < s.size() && !mp.count(s[right])) {
                mp[s[right++]] = 1;//"opening" window
            }

            count = max(count, right - left);
            mp.erase(s[left]);

        }
        return count;
    }

    //leetcode 1004: Sliding window
    int longestOnes(vector<int>& nums, int k) {
        int maxlength = 0;
        int r = 0, l = 0;
        while (r < nums.size()) {

            if (nums[r] == 0) {
                k--;
            }

            while (k < 0) {//"closing" window
                if (nums[l] == 0) k++;
                l++;
            }

            maxlength = max(maxlength, r - l + 1);
            r++;//"opening" window


        }
        return maxlength;
    }


};
