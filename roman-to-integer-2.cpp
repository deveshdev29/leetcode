#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanToInt = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}  
        };

        int total = 0;
        int prev = 0;

        for(char c : s){
            int current = romanToInt[c];

            if(current > prev){
                total += current - 2 * prev;
            }else{
                total += current;
            }
            prev = current;
        }
        return total;
    }
};

int main(){
    Solution sol;

    string s;
    getline(cin, s);

    cout << s << " is " << sol.romanToInt(s) << endl;
    return 0;
}