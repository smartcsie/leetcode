# 🧩 演算法模板 Pattern

常用演算法片段的模板庫，直接存在 `pattern/` 資料夾底下，
跟題解（`docs/problems/*.md`）不同，這裡只是零散的程式碼片段，
不是完整可編譯的題解，複習時方便直接複製貼上。

---

## Binary_Search.cpp

```cpp
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
        
    // 區間閉合 [left, right]，因此使用 <=
    while (left <= right) {
        int mid = left + ((right - left) / 2);
        if (nums[mid] == target) {
             return mid; // 找到目標
        } else if (nums[mid] > target) {
             right = mid - 1; // 目標在左半區
        } else {
                left = mid + 1; // 目標在右半區
        }
    }
    return -1; // 找不到
}
```

## Binary_Search_Open.cpp

```cpp
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + ((right - left) / 2);
        if (nums[mid] == target) {
             return mid; // 找到目標
        } else if (nums[mid] > target) {
             right = mid; // 目標在左半區
        } else {
             left = mid + 1; // 目標在右半區
        }
    }
    return nums[left] == target ? left : -1;
}
```

## Bitmask_Subset_Enumeration.cpp

```cpp
for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            // 第 i 個元素被選中
        }
    }
}
```

## Brian_Kernighan.cpp

```cpp
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1); // Clears the rightmost set bit
        count++;
    }
    return count;
}
```

## Combination.cpp

```cpp
long C(int n, int k) {
    if(k == 0 || k == n) return 1;
    long res = 1;
    if (k > n / 2) k = n - k;
    for(int i = 1; i <= k; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}
```

## Factor_Enumeration.cpp

```cpp
vector<int> factor(int n) {
    vector<int> res;
	  for(int i =1; i * i <=n; i++) {
		  if(n % i == 0) res.push_back(i);
	  }
	  for (int i = (int)sqrt(n); i >= 1; i--) {
		  if (n % i == 0 && i * i != n) res.push_back(n / i);
	  }
	  return res;
}
```

## GCD.cpp

```cpp
int gcd(int a, int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}
```

## Is_Subsequence.cpp

```cpp
bool isSubsequence(const string& s, const string& t) {
    int i = 0, n = s.size();
    for (char c : t) {
        if (s[i] == c) {
            i++;
            if (i == n) return true; 
        }
    }
    return false;
}
```

## LCS

```cpp
 int longestCommonSubsequence(string text1, string text2) {
        string& s = text1;
        string& t = text2;
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i  - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
```

## Permutation

```cpp
void permute(vector<int>& nums, int start, vector<vector<int>>& res) {
        if(start == nums.size()) {
            res.emplace_back(nums);
        }
        for(int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            permute(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
```

## Transport_Matrix.cpp

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
```

## Tree_BFS.cpp

```cpp
//不需要處理每一個level
vector<int> levelOrder(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    vector<int> vec;
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();              
        vec.push_back(node->val); 
        if (node->left) q.push(node->left); 
       	if (node->right) q.push(node->right); 
    }
    return vec;
}


//需要處理每一個level
vector<int> levelOrder(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    vector<int> vec;
    while (!q.empty()) {
        // 每一個level 開始
	      for(int = q.size() - 1; i >=0; i--) {
            TreeNode *node = q.front();
            q.pop();              
            vec.push_back(node->val); 
            if (node->left) q.push(node->left); 
       	    if (node->right) q.push(node->right); 
	      }
    }
    return vec;
}
```

## getPrimeFactor

```cpp
unordered_set<int> getPrimeFactor(int n) {
    unordered_set<int> fators;
    for(int p = 2; p * p <= n; x++) {
        while(n % x == 0) {
            fators.insert(p);
            n /= p;
        }
    }
    if(n > 1) fators.insert(n);
    return fators;
}
```

## getPrimeFactors

```cpp
std::vector<int> getPrimeFactors(long long n) {
    std::vector<int> result;
    // 處理 2
    while (n % 2 == 0) {
        result.push_back(2);
        n /= 2;
    }
    // 處理奇數因子
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            result.push_back(i);
            n /= i;
        }
    }
    // 處理剩下的質數
    if (n > 1) result.push_back(n); 
    return result;
}
```

## getPrimes.cpp

```cpp
vector<bool> getPrimes(int n) {
    bitset<n + 1> isPrime;
    isPrime.set();
    isPrime.reset(0);
    isPrime.reset(1);
    for(int p = 2; p *p <= n; p++) {
        if(isPrime[p]) {
            for(int i = p*p; i <= n; i += p) {
                isPrime.reset(i);;
            }
        }
    }
    return isPrime;
}
```

## isPalindrome

```cpp
bool isPalindrome(const std::string &s) {
    if (s.empty()) return true; // 空字串通常被定義為回文
    int left = 0;
    int right = static_cast<int>(s.length()) - 1;
    while (left < right) {
        if (s[left++] != s[right--]) {
            return false;
        }
    }
    return true;
}
```

## isPrime.cpp

```cpp
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false; 
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
```

## isVowel.cpp

```cpp
static bool isVowel(char c) {
    int lower = c | 0x20;
    return (0x104111 >> (c - 'a')) & 1;
}
```

## longestOnes.cpp

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ones = 0;
        int ones = 0;
        for(const int& num : nums) {
            ones = (num & 1) ? ones + 1 : 0;
            max_ones = max(max_ones, ones);
        }
        return max_ones;
    }
};
```

## prefixSum

```cpp
vector<int> prefixes(n + 1, 0);
for(int i = 0; i < n; i++) {
    prefixes[i + 1] = prefixes[i] + nums[i];
}
```

