#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isValid(string s) 
    {
        bool answer = true;
        int backNum;
        bool checkStart,checkEnd = false;

        

        while(s != "")
        {
            for (int i = 0; i < s.length();)
            {
                for (int j = 0; j < s.length(); j++)
                {
                    if (s[j] == ')' || s[j] == ']' || s[j] == '}') {
                        checkEnd = true;
                        break;
                    }
                    else
                    {
                        checkEnd = false;
                    }
                }
                for (int g = 0; g < s.length(); g++)
                {

                    if (s[g] == '(' || s[g] == '[' || s[g] == '{') {
                        checkStart = true;
                        break;
                    }
                    else
                    {
                        checkStart = false;
                    }
                }
                if( s[0] != ')' && s[0] != ']' && s[0] != '}' && checkEnd && checkStart )
                {
                    backNum = i - 1;
                    switch (s[i])
                    {
                    case ')':
                        if (s[backNum] == '(') 
                        {
                            s.erase(i,1);
                            s.erase(backNum,1);
                            i = 0;
                            break;
                        }
                        else
                        {
                            answer = false;
                            s = "";
                            break;
                        }
                        break;
                    case ']':
                        if (s[backNum] == '[') 
                        {
                            s.erase(i, 1);
                            s.erase(backNum, 1);
                            i = 0;
                            break;
                        }
                        else
                        {
                            answer = false;
                            s = "";
                            break;
                        }
                        break;
                    case '}':
                        if (s[backNum] == '{') 
                        {
                            s.erase(i, 1);
                            s.erase(backNum, 1);
                            i = 0;
                            break;

                        }
                        else
                        {
                            answer = false;
                            s = "";
                            break;
                        }
                        break;
                    default:
                        i++;
                        break;
                    }
                }
                else {
                    answer = false;
                    s = "";
                    break;
                }
            }
        }
        cout << answer;
        return answer;
    }
};
int main() {
    Solution a;
    a.isValid("({[(([[()]]))]})");
    return 0;
}