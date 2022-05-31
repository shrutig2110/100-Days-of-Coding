// Leetcode
class Solution {
private:
    bool matches(char top, char bracket)
    {
        if((top == '(' && bracket == ')') || (top == '{' && bracket == '}') || (top == '[' && bracket == ']'))
        {
            return true;
        }
        else {
            return false;
        }
    }
public:
    bool isValid(string s) {
        stack<char> b;
        
        for(int i=0; i<s.length(); i++)
        {
            char bracket = s[i];
            if(bracket == '(' || bracket == '{' || bracket == '[')
            {
                b.push(bracket);
            }
            else{
                if(!b.empty())
                {
                    char top = b.top();
                    if(matches(top, bracket))
                    {
                        b.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(b.empty())
        {
            return true;
        }
        else{
            return false;
        }
        
    }
};