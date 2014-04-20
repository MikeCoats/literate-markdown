#include <iostream>
#include <vector>
#include <map>
using namespace std;

// trim from start
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}


bool isPrefixedWith(string line, string prefix)
{
    if(trim(line).substr(0,prefix.size()) == prefix)
        return true;
    else
        return false;
}
string getStringAfterPrefix(string line, string prefix)
{
    return trim(line).substr(prefix.size(),trim(line).size()-prefix.size());
}

// -
bool isUsage(string line)
{
    return isPrefixedWith(line,"- ");
}
string getUsage(string line)
{
    return getStringAfterPrefix(line,"- ");
}

// ######
bool isTitle(string line)
{
    return isPrefixedWith(line,"###### ");
}
string getTitle(string line)
{
    return getStringAfterPrefix(line,"###### ");
}

// ```
bool isBlockEdge(string line)
{
    return isPrefixedWith(line,"```");

}



int  main()
{
    vector<string> linesRead;
    string lineRead;

    vector<int> usages;
    vector<int> titles;
    vector<int> blockEdges;

    map<string, pair<int, int> > blockMap;


    while(getline(cin,lineRead))
    {
        linesRead.push_back(lineRead);

        if(isUsage(lineRead)) usages.push_back(linesRead.size()-1);
        if(isTitle(lineRead)) titles.push_back(linesRead.size()-1);
        if(isBlockEdge(lineRead)) blockEdges.push_back(linesRead.size()-1);
    }

    for(int i = 0; i < titles.size(); i ++)
    {
        int j = 0;
        while(titles.at(i) > blockEdges.at(j) && j < blockEdges.size()-1)
        {
            j++;
        }
        int blockStart = blockEdges.at(j)+1;
        int blockEnd = blockEdges.at(j+1);

        pair<int,int> startEnd(blockStart,blockEnd);
        blockMap[getTitle(linesRead.at(titles.at(i)))] = startEnd;
    }
    
    for(int i = 0; i < usages.size(); i ++)
    {
        pair<int,int> code = blockMap[getUsage(linesRead.at(usages.at(i)))];
        for(int j = code.first; j < code.second; j++)
        {
            cout << linesRead.at(j) << endl;
        }
    }
}
