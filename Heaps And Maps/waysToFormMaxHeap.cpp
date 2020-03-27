Max Heap is a special kind of complete binary tree in which for every node the value present in that node is greater than the value present in it’s children nodes. If you want to know more about Heaps, please visit this link

So now the problem statement for this question is:

How many distinct Max Heap can be made from n distinct integers

In short, you have to ensure the following properties for the max heap :

Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible. )
Every node is greater than all its children
Let us take an example of 4 distinct integers. Without loss of generality let us take 1 2 3 4 as our 4 distinct integers

Following are the possible max heaps from these 4 numbers :

         4 
       /  \ 
      3   2 
     / 
    1
         4 
       /  \ 
      2   3 
     / 
    1
        4 
       /  \ 
      3   1 
     / 
    2
These are the only possible 3 distinct max heaps possible for 4 distinct elements.

Implement the below function to return the number of distinct Max Heaps that is possible from n distinct elements.

As the final answer can be very large output your answer modulo 1000000007

Input Constraints : n <= 100

 NOTE: Note that even though constraints are mentioned for this problem, for most problems on InterviewBit, constraints are intentionally left out. In real interviews, the interviewer might not disclose constraints and ask you to do the best you can do. 
 
 
 
 
 int com[100][100];
int d[100];
long long combination(int n, int k)
{
    if(n < k)
        return 0;
    if(n <= 1)
        return 1;
    if(k == 0)
        return 1;
    if(com[n][k] != -1)
        return com[n][k];
    com[n][k] = (combination(n - 1, k - 1) + combination(n - 1, k)) % 1000000007;    
    return com[n][k];
}
int getLeft(int n)
{
    int h = log10(n)/log10(2);
    int maximum = 1 << h;
    int last = n - ((1 << h) - 1);
    if(last >= maximum / 2)
        return maximum - 1;
    else
        return maximum - 1 - ((maximum / 2) - last);
    
}
long long numberOfHeaps(int n)
{
    if(n <= 1)
        return 1;
    if(d[n] != -1)
        return d[n];
    int k = getLeft(n);
    d[n] = (((numberOfHeaps(k) * numberOfHeaps(n - k - 1)) % 1000000007) * combination(n - 1, k)) % 1000000007;
    return d[n];
}

int Solution::solve(int A) {
    
    for(int i = 0; i <= A; i++)
        d[i] = -1;
    for(int i = 0; i <= A; i++)
    {
        for(int j = 0; j <= A; j++)
        {
            com[i][j] = -1;
        }
    }
    int result = numberOfHeaps(A);
    return result % 1000000007;
}
