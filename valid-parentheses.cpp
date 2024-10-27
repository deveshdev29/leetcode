#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution{
    public:
    bool isValid(string s){
        stack<char> stack;
        unordered_map<char, char> brackets = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };

        for(char ch: s){
            if(brackets.count(ch)){ // count checks if ch is a key
                if(!stack.empty() && stack.top() == brackets[ch]){
                    stack.pop();
                }else{
                    return false;
                }
            }else{
                stack.push(ch);
            }
        }
        return stack.empty();
    }
};
int main(){

    Solution sol;

    string str;
    cin >> str;

    if(sol.isValid(str) == 1){
        cout << "Valid" << endl;
    }else{
        cout << "not valid" << endl;
    }

    return 0;
}