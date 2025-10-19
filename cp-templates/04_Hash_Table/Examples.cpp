#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
public:

    //Leetcode 383. Ransom Note
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> mp;
        int n = ransomNote.size();
        int m = magazine.size();


        if (n > m) return false;

        for (int i = 0; i < m; i++) {
            mp[magazine[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (--mp[ransomNote[i]] < 0) return false;
        }

        return true;

    }

    //Leetcode 242. Valid Anagram
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        int n = s.size();

        if (s.size() != t.size()) return false;

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (--mp[t[i]] < 0) return false;
        }

        return true;
    }

    //Leetcode 3005. Count Elements With Maximum Frequency
    int maxFrequencyElements(vector<int>& nums) {

        unordered_map<int, int> freq;
        int answer = 0, max = 0;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            if (freq[nums[i]] > max) max = freq[nums[i]];
        }

        for (auto& num : freq) {
            if (num.second == max) {
                answer += max;
            }
        }
        return answer;
    }

};