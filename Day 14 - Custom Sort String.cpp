/*
Solution 1 - Using custom comparator
Time Complexity -> O(nlogn)
Space Complexity -> O(1)
*/

string s;
bool cmp(char a , char b ) {
	return s.find(a) < s.find(b);
}

class Solution {

public:

	string customSortString(string order, string str) {
		s = order;
		sort(str.begin(), str.end(), cmp);

		return str;
	}
};

/*
Solution 2 - Using unordered map (much much faster)
Time Complexity -> O(n)
Space Complexity -> O(n)
*/

class Solution {
public:
	string customSortString(string order, string str) {
		unordered_map <char, int> mp;
		for (char c : str)
			mp[c]++;

		string ans;
		for (char c : order) {
			if (mp.find(c) != mp.end()) {
				ans += string(mp[c], c);
				mp.erase(c);
			}
		}
		for (auto p : mp)
			ans += string(p.second, p.first);
		return ans;
	}
};