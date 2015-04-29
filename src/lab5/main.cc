//Use wget -O text.txt <Link> to rename the src code from the link to text.txt and download to your workspace
//Using typedef
//typedef std::map<std::string,std::vector<char>>::iterator Name
//Then all you have have to do is type Name it, since Name is kind of like a 
//place holder.
#include <map>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

std::map<std::string, unsigned int> freq_map(std::vector<std::string> words);

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        cout << "Usage: <a.out> <filename>" << endl;
        return 1;
    }
    fstream inf(argv[1], fstream::in);
    
    if(!inf)
    {
        cout << "Failed to open file!" << endl;
        return 1;
    }
    
    vector<string> wordList;
    string nextWord;
    inf >> nextWord;
    wordList.push_back(nextWord);
    
    while(!inf.eof())
    {
        inf >> nextWord;
        wordList.push_back(nextWord);
    }
    
    map<string, unsigned int> mappp = freq_map(wordList);
    
    return 0;
}

std::map<std::string, unsigned int> freq_map(std::vector<std::string> words)
{
    map<string, unsigned int> myMap;
    for(unsigned i = 0; i < words.size(); i++)
    {
        //if(myMap.find(words.at(i)) != myMap.end())
        myMap[words.at(i)]++;
    }
    
    return myMap;
}

std::vector<std::string> 
top_n(std::map<std::string, unsigned int> freq_map, unsigned int n = 5)
{
    for(unsigned i = 0; i < freq_map.size(); i++)
    {
        
    }
}