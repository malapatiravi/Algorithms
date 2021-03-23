#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

class AuthenticationManager {
public:
    int timeToLive = 0;
    std::unordered_map<std::string, int> database;
    AuthenticationManager(int _timeToLive) 
    {
        timeToLive = _timeToLive;
        database.clear();
    }
    
    void generate(string tokenId, int currentTime) 
    {
        database[tokenId] = currentTime + timeToLive;
    }
    
    void renew(string tokenId, int currentTime) 
    {
        if(database.find(tokenId) != database.end() )
        {
            if(database[tokenId] <= currentTime)
            {
                database.erase(tokenId);
            }
            else
            {
                database[tokenId] = currentTime + timeToLive;
            }            
        }
    }
    
    int countUnexpiredTokens(int currentTime) 
    {
        int count = 0;
        for(std::unordered_map<std::string, int>::iterator it = database.begin(); it != database.end(); it++)
        {
            if(it->second > currentTime)
            {
                count++;
                std::cout<<"UnExpired: "<<it->first<<std::endl;
            }
            else
            {
                std::cout<<"Expired: "<<it->first<<std::endl;
                database.erase(it->first);
            }
        }
        return count;
    }
};
