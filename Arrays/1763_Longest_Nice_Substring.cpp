#include <iostream>
#include <string>
using namespace std;

class Solution 
{
public:
    std::string ans;
    string longestNiceSubstring(string s) 
    {
        longestNiceSubstring(s, 0, s.size()-1);
        return ans;
    }
    void longestNiceSubstring(string s, int start, int end) 
    {
        std::cout<<"Entring start: "<<start<<" End: "<<end<<std::endl;
        // Exit condition
        if(end-start <= 0)
        {
            return;
        }
        int status[26] = {};
        for(int it = start; it <= end; it++)
        {
            if(s[it] >= 65 && s[it] <= 90)
            {
                // upper case
                status[s[it] - 65] |= 1;
            }
            else
            {
                //lower case
                status[s[it] - 97] |= 2;
            }
        }
        for(int it = 0; it < 26; it++)
        {
            std::cout<<status[it];
        }
        std::cout<<std::endl;
        int first_it = start;
        while(first_it <= end && status[tolower(s[first_it])-97] == 3)
        {
            first_it++;
            
        }
        std::cout<<first_it<<std::endl;
        if(first_it > end)
        {
            std::cout<<"Here"<<std::endl;
            if(ans.size() < end - start +1)
            {
                ans = s.substr(start, end - start +1);
            }
            return;
        }
        else//if(first_it < end)
           longestNiceSubstring(s, start, first_it-1);
        while(first_it < end && status[tolower(s[first_it])-97] != 3)
        {
            first_it++;
        }
        if(first_it >= end)
        {
            return;
        }
        longestNiceSubstring(s, first_it, end);
    }
};