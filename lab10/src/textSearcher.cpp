#include "textSearcher.h"

void TextSearcher::loadTextFromFile(const string& name)
{
    ifstream file (name);
    if (file.is_open())
    {

        string buff;
        while (!file.eof())
        {
           getline(file,buff);
           txt+=buff;
           txt+="\n";
        }

    }
    else
    {
        cout << "[ERROR] Nie mozna otworzyc pliku: " << name << endl;
    }
    file.close();
}

vector<int> TextSearcher::multiThreadedSearch(const string& name, int count)
{
    vector<future<int>> results;
    vector<int> results_ints;
    if (txt.empty())
    {
        cout << "[ERROR] Bufor jest pusty!"<<endl;
    }
    else
    {
        int segmentSize = txt.size()/count;
        for (int i = 0; i<count;i++)
        {
            int begin = i*segmentSize;
            int end = (i!=count-1) ? begin+segmentSize : txt.size();
         
            results.push_back(async(launch::async, [&, begin, end](){
                int cnt = 0;
                auto p = search(txt.begin()+begin, txt.begin()+end, name.begin(),name.end());
                while (p!=txt.begin()+end)
                {
                    cnt++;
                    p = search(p+name.size(),txt.begin()+end,name.begin(),name.end());
                }
                return cnt;
            }));
        }
    }
    for (auto& el: results)
       results_ints.push_back(el.get());
    
    return results_ints;
}

int TextSearcher::countResults(vector<int>&vec) const
{
    return accumulate(vec.begin(),vec.end(),0);
}
void TextSearcher::printResults(vector<int>&vec) const
{
    for (int i =0;i<vec.size();i++)
    {
        cout << "Watek " << i+1 << ": " << vec.at(i) << endl;
    }
}