#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:


    //leetcode 523(subarray >=2,subarray sum is multiple of k)
    bool checkSubarraySum(vector<int>& nums, int k) {

        long long pref = 0;//better to use long long type
        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < nums.size(); i++) {

            pref += nums[i];//pref can be just a variable, not array
            long long r = (pref % k + k) % k;//math modulo(>=0)

            if (mp.count(r)) {
                if (i - mp[r] > 1)
                    return true;
            }
            else
                mp[r] = i;

        }

        return false;
    }

    //leetcode974(amount subarrays multiple of k)
    int subarraysDivByK(vector<int>& nums, int k) {

        int pref = 0, count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {

            pref += nums[i];
            int r = (pref % k + k) % k;

            if (mp.find(r) != mp.end()) {
                count += mp[r];
            }

            mp[r]++;

        }

        return count;
    }

    //leetcode560(amount subarrays sums equal k)
    int subarraySum(vector<int>& nums, int k) {

        int count = 0;
        unordered_map<int, int> mp;
        vector<int> pref;//here pref is a array
        pref.push_back(0);

        for (int i = 0; i < nums.size(); i++) {
            pref.push_back(nums[i] + pref[i]);
        }

        mp[0] = 1;

        for (int i = 1; i < pref.size(); i++) {
            if (mp.find(pref[i] - k) != mp.end()) {
                count += mp[pref[i] - k];
            }
            mp[pref[i]]++;
        }

        return count;
    }

};
