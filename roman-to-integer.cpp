#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution{
public:
    int romanToInt(string s){
        unordered_map<char, int> romanToInt = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}  
        };
        int size = s.size();
        int integer = 0;

        for(int i = size - 1; i >= 0; i--){
            if(i==0){
                integer += romanToInt[s[i]];
            }else if(romanToInt[s[i-1]] >= romanToInt[s[i]]){
                integer += romanToInt[s[i]];
            }else{
                integer += romanToInt[s[i]];
                integer -= romanToInt[s[i-1]];
                i--;
            }
        }
        return integer;
    }
};

int main(){
    Solution sol;

    string s;
    getline(cin, s);

    cout << s << " is " << sol.romanToInt(s) << endl;
    return 0;
}