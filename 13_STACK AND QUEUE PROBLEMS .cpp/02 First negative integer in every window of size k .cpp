vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    deque<long long int> dq;
    vector<long long> ans;
    int negative = -1;

    // process first window
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
            dq.push_back(i);
    }

    if (!dq.empty())
        ans.push_back(A[dq.front()]);

    else
        ans.push_back(0);

    // iterating for remaining windows
    for (int i = K; i < N; i++)
    {

        // removing index which are not in window
        if (!dq.empty() && i - dq.front() >= K)
            dq.pop_front();

        // pushing index
        if (A[i] < 0)
            dq.push_back(i);

        // pushing ans
        if (!dq.empty())
            ans.push_back(A[dq.front()]);

        else
            ans.push_back(0);
    }
    return ans;
}

// Link of this Problem -> https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
