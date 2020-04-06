int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int depth = 0;
    int p = 0, q = -1, r = -1;
    for(int i=1; i<A.size(); i++)
    {
        if(q < 0 && A[i] >= A[i-1])
        {
            q =  i - 1;
        }
            
        if((q >= 0 && r < 0) && ((A[i] <= A[i-1]) || i+1 == A.size()))
        {
            if(A[i] <= A[i+1])    
                r = i - 1;
            else
                r = i;
            depth = max(depth, min(A[p]-A[q], A[r]-A[q]));
            p = i - 1;
            q = -1;
            r = -1;
        }
    }
    
    if(depth == 0)
        depth = -1;
        
    return depth;
}

