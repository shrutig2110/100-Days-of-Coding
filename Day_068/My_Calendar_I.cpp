/*
PROBLEM: My Calendar I
*/ 
class MyCalendar {
public:
    map<int, int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) 
    {
        // For each start val should be 1 and end val should be -1, so that if sum = 0, then no overlapping occurs
         mp[start]++;
         mp[end]--;
         int sum = 0;
         for(auto it = mp.begin();it!=mp.end();it++)
         {
             sum += it->second;
            //  Sum will be greater than one if two events are overlapping
             if(sum>1)
             {
                 mp[start]--;
                 mp[end]++;
                 return false;
             }
         }
        return true;
    }
};

