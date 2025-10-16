#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:

    //leetcode 20: Valid Parentheses
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char, char> mp;
        mp['('] = ')';
        mp['['] = ']';
        mp['{'] = '}';

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else {
                if (st.empty() || s[i] != mp[st.top()]) return false;
                else {
                    st.pop();
                }
            }

        }
        if (st.empty()) return true;
        else return false;

    }

    //leetcode 387: First Unique Character in a String
    class Solution {
    public:
        int firstUniqChar(string s) {
            unordered_map<char, int> freq;
            queue<int> q;

            for (int i = 0; i < s.size(); i++) {
                freq[s[i]]++;
                q.push(i);

                while (!q.empty() && freq[s[q.front()]] > 1) {
                    q.pop();
                }
            }

            return q.empty() ? -1 : q.front();
        }
    };

};