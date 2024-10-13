#include <iostream>
using namespace std;

class Solution{
public:
    bool isPalindrome(int x){

        if(x < 0){
            return false;
        }
        string n = to_string(x);

        for(int i = 0; i < n.length() / 2; i++){
            if(n[i] != n[n.length() - i - 1]){
                return false;
            }
        }
        return true;
    }
};

int main(){
     
    Solution sol;
    int x = 121;

    cout << sol.isPalindrome(x);
}