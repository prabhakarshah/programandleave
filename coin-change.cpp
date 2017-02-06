/*
* Dynamic Programming SOlution for coin change problem
*/
int CoinChange(vector<int> C, int change)
{
    vector<int> S(change + 1,INT_MAX);
    S[0] = 0;
    for(int i = 1; i <= change ; i++)
    {
        for(int j =0;j<C.size(); j++)
        {
            if(i >= C[j] && 1 + S[i-C[j]] < S[i])
            {
                S[i] = 1 + S[i - C[j]];
            }
        }
    }
    return S[change];
}
/*
* Code to print the change
*/
int CoinChange(vector<int> C, int change)
{
    vector<int> S(change + 1,1000);
    vector<int> seq(change + 1);
    S[0] = 0;
    for(int i = 1; i < change + 1; i++)
    {
        for(int j =0;j<C.size(); j++)
        {
            if(i >= C[j] && 1 + S[i-C[j]] < S[i])
            {
                S[i] = 1 + S[i - C[j]];
                seq[i] = j;
            }
        }
    }

    cout<<"Coins: ";
    int j = change;
    while(j)
    {
        cout<<" "<<C[seq[j]];
        j = j - C[seq[j]];
    }
    cout<<endl;
    return S[change];
}
