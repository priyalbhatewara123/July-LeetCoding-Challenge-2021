class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        priority_queue<int> pq; //to store frequencies in decreasing order
        unordered_map <int, int> mp; // to map characters with their frequency

        for (int a : arr)
            mp[a]++;

        for (auto p : mp)
            pq.push(p.second);

        int size = n;
        int ans = 0;

        while (size > n / 2) {
            ans++;
            size -= pq.top();
            pq.pop();
        }
        return ans;
    }
};