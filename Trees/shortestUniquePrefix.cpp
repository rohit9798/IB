Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov



typedef struct TrieNode
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
vector<string> Solution::prefix(vector<string> &A) {
    
    TrieNode *root = getNode();
    vector<string> result;
    string temp = "";
    int count = 0, index;
    for(int i = 0; i < A.size(); i++)
    {
        insert(root, A[i]);
    }
    TrieNode *ptr = root, *qtr = root;
    for(int i = 0; i < A.size(); i++)
    {
        ptr = root;
        qtr = root;
        for(int j = 0; j < A[i].length(); j++)
        {
            for(int k = 0; k < 26; k++)
            {
                if(ptr -> children[k] != NULL)
                    count++;
            }
            if(count > 1)
            {
                qtr = ptr;
            }
            ptr = ptr -> children[A[i][j] - 'a'];
            count = 0;
        }
        int j = 0;
        ptr = root;
        while(1)
        {
            temp += (A[i][j]);
            if(ptr == qtr)
                break;
            ptr = ptr -> children[A[i][j] - 'a'];
            j++;
        }
        result.push_back(temp);
        temp = "";
    }
    return result;
}
