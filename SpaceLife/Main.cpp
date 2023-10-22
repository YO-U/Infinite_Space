#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        int endNum = num.length();
        bool answer = false;
        endNum--;
        for (int i = 0; i < num.length(); i++)
        {
            if (num[i] != num[endNum]) {
                answer = false;
                break;
            }
            else {
                answer = true;
            }
            endNum--;
        }
        cout << answer;
        return answer;
    }
};
int main() {
    Solution a;
    a.isPalindrome(1234321);
    return 0;
}