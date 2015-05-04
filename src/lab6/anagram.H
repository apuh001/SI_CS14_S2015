#include <vector>
#include <map>

using namespace std;

class Anagram{
    private:
        map<string, vector<string>> a;
    public:
        
        string sort(string s)
        {
            vector<char>wordVec;
            for(unsigned i = 0; i < s.size(); i++)
                wordVec.push_back(s.at(i));
            
            for(unsigned y = 0; y < wordVec.size(); y++)
            {
                unsigned currMin = y;
                for(unsigned z = y + 1; z < wordVec.size(); z++)
                {
                    if(wordVec[z] < wordVec[y])
                        currMin = z;
                }
                char temp = wordVec[y];
                wordVec[y] = wordVec[currMin];
                wordVec[currMin] = temp;
            }
            
            string newS = wordVec.at(0);
            return newS;
        }
        
        const vector<string> get_anagrams(string s)
        {
            string sortedWord = sort(c);
            if(a.find(s) == end())
            {
               if(sortedWord != end())
                   a[sortedWord].push_back(s);
               else
                   a[sortedWord];
            }
            
            return a[sortedWord];
        }
};