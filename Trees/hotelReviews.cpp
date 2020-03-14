Given a set of reviews provided by the customers for different hotels and a string containing “Good Words”, you need to sort the reviews in descending order according to their “Goodness Value” (Higher goodness value first). We define the “Goodness Value” of a string as the number of “Good Words” in that string.

Note: Sorting should be stable. If review i and review j have the same “Goodness Value” then their original order would be preserved.

 You are expected to use Trie in an Interview for such problems 

Constraints:

1.   1 <= No.of reviews <= 200
2.   1 <= No. of words in a review <= 1000
3.   1 <= Length of an individual review <= 10,000
4.   1 <= Number of Good Words <= 10,000
5.   1 <= Length of an individual Good Word <= 4
6.   All the alphabets are lower case (a - z)
Input:

S : A string S containing "Good Words" separated by  "_" character. (See example below)
R : A vector of strings containing Hotel Reviews. Review strings are also separated by "_" character.
Output:

A vector V of integer which contain the original indexes of the reviews in the sorted order of reviews. 

V[i] = k  means the review R[k] comes at i-th position in the sorted order. (See example below)
In simple words, V[i]=Original index of the review which comes at i-th position in the sorted order. (Indexing is 0 based)
Example:

Input: 
S = "cool_ice_wifi"
R = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]

Output:
ans = [2, 0, 1]
Here, sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]



/**/vector<string> split(string str)
{
    std::stringstream ss(str);
    vector<string> out;
    const char delimiter = '_';
    std::string s;
    while (std::getline(ss, s, delimiter)) {
        out.push_back(s);
    }
    return out;
}

struct TrieNode
{
    struct TrieNode* children[26];
    bool isEnd;
};
TrieNode* getNode()
{
    TrieNode *temp = new TrieNode();
    for(int i = 0; i < 26; i++)
    {
        temp -> children[i] = NULL;
    }
    temp -> isEnd = false;
    return temp;
}
void insert(TrieNode* root, string data)
{
    TrieNode *search = root;
    for(int i = 0; i < data.length(); i++)
    {
        int index = data[i] - 'a';
        if(!search -> children[index])
        {
            search -> children[index] = getNode();
        }
        search = search -> children[index];
    }
    search -> isEnd = true;
}
bool search(struct TrieNode* root, string key)
{
    int i;
    struct TrieNode* search = root;
    for(i = 0; i < key.length(); i++)
    {
        int index = key[i]-'a';
        if(search->children[index])
            search = search->children[index];
        else
            return 0;
    }
    return (search->isEnd);
}
vector<int> Solution::solve(string A, vector<string> &B) {
    
    vector<string> string_split;
    multimap<int, int, greater<int>> m;
    vector<int> result;
    string_split = split(A);
    TrieNode* root = getNode();
    for(int i = 0; i < string_split.size(); i++)
    {
        insert(root, string_split[i]);
    }
    string_split.clear();
    for(int i = 0; i < B.size(); i++)
    {
        string_split = split(B[i]);
        int count = 0;
        for(int j = 0; j < string_split.size(); j++)
        {
            bool flag = search(root, string_split[j]);
            if(flag)
                count++;
        }
        m.insert(make_pair(count, i));
    }
    multimap<int, int> :: iterator itr;
    for(itr = m.begin(); itr != m.end(); itr++)
    {
        result.push_back(itr -> second);
    }
    return result;
}
    /*vector<string> result;
    result = split(A); 
    multimap<int, int, greater<int>> m;
    int count = 0, k = 0, l = 0;
    vector<string> temp;
    vector<int> final;
    for(int i = 0; i < B.size(); i++)
    {
        temp = split(B[i]);
        for(l = 0; l < temp.size(); l++)
        {
            for(k = 0; k < result.size(); k++)
                if(temp[l] == result[k])
                {
                    count++;
                    break;
                }
        }
        m.insert(make_pair(count, i));
        count = 0;
    }
    multimap<int, int> :: iterator itr;
    
    for(itr = m.begin(); itr != m.end(); itr++)
    {
        final.push_back(itr -> second);
    }
    return final;
    }
    */
    
    
    
    
    
