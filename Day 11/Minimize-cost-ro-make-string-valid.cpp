#include <stack>
int findMinimumCost(string str) {
    //odd condition
  if(str.length()%2 == 1)
  {
      return -1;
  }
  stack<char> s;
    //removng valid parenthesis
   for(int i=0;i<str.length();i++)
   {
       char ch =str[i];
       if(ch == '{')
       {
           s.push(ch);
       }
       else
       {
           if(!s.empty() && s.top()=='{' )
           {
               s.pop();
           }
           else{
               s.push(ch);
           } 
       }
   }
    //find cost of invalid parenthesis
       int a=0,b=0;
       while(!s.empty())
       {
           if(s.top()=='{') 
               a++;
           else 
               b++;
           s.pop();
       }
    int ans = (a+1)/2 + (b+1)/2;
       return ans;
 
}