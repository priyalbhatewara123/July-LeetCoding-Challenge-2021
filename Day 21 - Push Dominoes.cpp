class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> l(n, 0) , r(n, 0);

        char prev = '.';
        int count = 1;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'L')
                prev = 'L';
            else if (dominoes[i] == 'R') {
                prev = 'R';
                count = 1;
            }
            if (dominoes[i] == '.' and prev == 'R')
                r[i] = count++;
        }

        prev = '.';
        count = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'R')
                prev = 'R';
            else if (dominoes[i] == 'L') {
                prev = 'L';
                count = 1;
            }
            else if (dominoes[i] == '.' and prev == 'L')
                l[i] = count++;
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (l[i] == 0 and r[i] != 0) ans += 'R';
            else if (l[i] != 0 and r[i] == 0) ans += 'L';
            else if (l[i] != 0 and r[i] != 0) {
                if (l[i] == r[i])
                    ans += '.';
                else if (l[i] < r[i])
                    ans += 'L';
                else
                    ans += 'R';
            }
            else
                ans += dominoes[i];
        }

        return ans;
    }
};

/*
Time Complexity - O(n)
Space Complexity - O(n)
*/