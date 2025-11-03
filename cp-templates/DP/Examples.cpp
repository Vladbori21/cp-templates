class Solution {
public:

    
    -------------HASH TABLE(MEMORISATION)-----------
    int helper(int n, unordered_map<int,int>& tab){
        if(n<=1) return 1;
        if(tab.count(n)) return tab[n];
        return tab[n] = helper(n-1, tab) + helper(n-2, tab);
    }

    int climbStairs(int n) {
        unordered_map<int, int> tab;
        return helper(n, tab);
    }
    

    
   ------------ VECTOR(MEMORIZATION) MEMORY O(N)----------
    int helper(int n,vector<int>& mem){
        if(n<=1) return 1;
        if(mem[n]!=-1) return mem[n];
        return mem[n] = helper(n-1, mem) + helper(n-2, mem);
    }

    int climbStairs(int n) {
        vector<int> mem(n+1, -1);
        return helper(n, mem);    
    }
    

    
    ----------VECTOR(MEMORIZATION) MEMORY(O(1))-------------
    int helper(int n,vector<int>& mem){
        if(n<=1) return 1;
        if(mem[n%3]!=-1) return mem[n%3];
        return mem[n%3] = helper(n-1, mem) + helper(n-2, mem);
    }

    int climbStairs(int n) {
        vector<int> mem(3, -1);
        return helper(n, mem);    
    }
    

    
   ---------------VECTOR(TABULATION) MEMORY(O(1))-------------------
    int climbStairs(int n) {
        if(n<=1) return 1;
        int mem[3];
        mem[0]=1;
        mem[1]=1;
        int i=2;
        for(;i<=n;i++){
            mem[i%3] = mem[(i-1)%3]+mem[(i-2)%3];
        }
        return mem[(i-1)%3];
    }
    
};
