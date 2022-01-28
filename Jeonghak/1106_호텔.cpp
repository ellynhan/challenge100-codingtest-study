int C, N, DP[100001]={0}, money=0;

int main()
{
    int Max=0, c=0;
    cin >> C >> N;
    for(int i=0; i<N; i++)
    {
        int a, b;
        cin >> a >> b;
        if(DP[a] < b)
            DP[a] = b;
    }
    for(int c=1; c<=100000; c++){
        Max = DP[c];
        for(int j=1; j<=c/2; j++){
            Max = max(DP[c-j] + DP[j], Max);
            if(j==c/2)
                Max = max(DP[j]*2, Max);
        }
        DP[c] = Max;
        money++;
        if(DP[c] >= C) {
            cout << money << endl;
            break;
        }
    }
    return 0;
}
