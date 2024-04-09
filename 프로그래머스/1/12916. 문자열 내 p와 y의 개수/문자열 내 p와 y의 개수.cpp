#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = false;
    int cntp = 0, cnty = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'p' || s[i] == 'P'){cntp++;}
        else if(s[i] == 'y' || s[i] == 'Y'){cnty++;}
    }
    if (cntp == cnty){return answer = true;}
    
    return answer;
}