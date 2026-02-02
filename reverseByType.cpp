#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string reverseByType(string s) {
        int n = s.length();

        //1. Reverse Latters
        string letters = "";
        for (char c: s) {
            if (islower(c)) letters += c;
        }
        reverse(letters.begin(), letters.end());

        int letterIdx = 0;
        for (int i = 0; i < n; i++) {
                if (islower(s[i])) {
                    s[i] = letters[letterIdx++];
            }
        }
        string specials = "";
        for (char c : s) {
            if (!islower(c)) specials += c;
        }
            reverse(specials.begin(), specials.end());

            int specialIdx = 0;
            for (int i = 0; i < n; i++) {
                if (!islower(s[i])) {
                    s[i] = specials[specialIdx++];
                }
            }
        
            return s;
    }
};
int main() {
    Solution sol;
    string s = "a!b@c#d$e%f^";
    string result = sol.reverseByType(s);
    cout << result << endl; // Output: "f!e@d#c$b%a^"
    return 0;
}