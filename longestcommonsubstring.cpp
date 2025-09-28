#include <iostream>
#include <string>
#include <vector>

using namespace std;


void longest_common_substring(string text1, string text2) {
    int len = text1.length(); 
    vector<vector<int>> table(len + 1, vector<int>(len + 1, 0));
    int longest_len = 0; // Track the longest substring length
    int end_pos = 0;     // Track where the substring ends in text1

    // Fill the table by comparing characters
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            // If chars match, add 1 to the previous diagonal value
            if (text1[i - 1] == text2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
                // Update if we found a longer substring
                if (table[i][j] > longest_len) {
                    longest_len = table[i][j];
                    end_pos = i;
                }
            }
            // If no match, just put 0 (no substring continues here)
            else {
                table[i][j] = 0;
            }
        }
    }

    cout << "DP Table:\n  "; // Empty space for top-left corner
    for (int j = 0; j < len; j++) {
        cout << text2[j] << " "; // Show text2 chars as column headers
    }
    cout << endl;
    for (int i = 0; i <= len; i++) {
        if (i > 0) {
            cout << text1[i - 1] << " "; // Show text1 chars as row headers
        } else {
            cout << "  "; // Empty space for (0,0)
        }
        for (int j = 0; j <= len; j++) {
            cout << table[i][j] << " "; // Print table values
        }
        cout << endl;
    }

    // Get one of the longest substrings
    string result = text1.substr(end_pos - longest_len, longest_len);

    // Show the final answer
    cout << "\nLongest Common Substring Length: " << longest_len << endl;
    cout << "One Longest Common Substring: " << result << endl;
}

int main() {
    // Test with the example strings
    string s1 = "ABAB";
    string s2 = "BABA";

    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl << endl;

    longest_common_substring(s1, s2);

    return 0;
}