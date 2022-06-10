int n = s.length();
        if(n == 0 || n == 1)
            return n;
        int ans = 1;
        fre[s[0]]++;
        int j = 0,i = 0;
        while(j<s.length()-1){
            if(fre[s[j+1]] == 0){
                fre[s[j+1]]++;
                j++;
            }
            else{
                fre[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;