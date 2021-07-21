/*
Edge case : Many-to-one relation between s and t , when 2 characters of s maps to same character in t.
*/

//Solution 1
class Solution {
	bool helper(string s , string t) {
		unordered_map <char, char> mp;

		for (int i = 0; i < s.length(); i++) {
			if (mp.find(s[i]) != mp.end()) {
				if (mp[s[i]] != t[i])
					return false;
			}
			else {
				mp[s[i]] = t[i];
			}
		}
		return true;
	}

public:
	bool isIsomorphic(string s, string t) {
		return helper(s, t) && helper(t, s); //to avoid many-to-one relation check both ways
	}
};

//Solution 2
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map <char, char> mp;
		unordered_set <char> st;  //maintain a set of charaters in t which are already mapped
		for (int i = 0; i < s.length(); i++) {
			if (mp.find(s[i]) != mp.end()) {
				if (mp[s[i]] != t[i])
					return false;
			}
			else {
				if (st.count(t[i]))  return false;
				mp[s[i]] = t[i];
				st.insert(t[i]);
			}
		}
		return true;
	}
};