// hard
#include <algorithm>
#include <string>
#include <vector>
using std::string;
using std::swap;
using std::vector;

class Solution {
public:
    int totalNQueens(int n) {
        this->n = n;
        int res = 0;
        if (n == 0) {
            return res;
        }
        
        vector<int> v;
        int i;
        for (i = 0; i < n; ++i) {
            v.push_back(i);
        }
        diag.resize(2 * n - 1, false);
        anti_diag.resize(2 * n - 1, false);
        dfs(0, v, res);
        
        diag.clear();
        anti_diag.clear();
        
        return res;
    }
private:
    int n;
    vector<bool> diag;
    vector<bool> anti_diag;
    
    void dfs(int idx, vector<int> &v, int &res) {
        if (idx == n) {
            ++res;
            return;
        }
        int i;
        int val;
        for (i = idx; i < n; ++i) {
            val = v[i];
            if (diag[idx + val] || anti_diag[n - 1 + idx - val]) {
                continue;
            }
            
            swap(v[i], v[idx]);
            diag[idx + val] = true;
            anti_diag[n - 1 + idx - val] = true;
            
            dfs(idx + 1, v, res);
            
            anti_diag[n - 1 + idx - val] = false;
            diag[idx + val] = false;
            swap(v[i], v[idx]);
        }
    }
};
