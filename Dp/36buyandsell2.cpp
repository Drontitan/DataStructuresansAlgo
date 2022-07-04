#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// ********Here we can buy and sell as many times we want *********
// rest all the question same

// here if we but one item then before buying the other item we have to sell the 1st one

// B S B S ✅
// B B S S ❌

// recursion    TC:-O(2^n)   SC :- O(N)

// i have to carry the variable it will tell if i have buy previously then i cant again buy
int buyandsellstock(int i, int buy, vector<int> &vec)
{

    if (i == vec.size())
        return 0;

    long profit = 0;
    if (buy)
    {
        profit = max(-vec[i] + buyandsellstock(i + 1, 0, vec), 0 + buyandsellstock(i + 1, 1, vec)); // profit1
                                                                                                    // in the buy we have checked two conditions either to buy on that day or not buy on that
                                                                                                    // we are buying so there is -  negative sign
    }
    else
    {
        // selling so the added value is +  positive
        profit = max(vec[i] + buyandsellstock(i + 1, 1, vec), 0 + buyandsellstock(i + 1, 0, vec)); // profit2
    }

    return profit;
}

// memoization   TC O(N*2)  SC:-O(N*2) + auxialryspace
int buyandsellstockmemo(int i, int buy, vector<int> &vec, vector<vector<int>> &dp)
{

    if (i == vec.size())
        return 0;
    long profit = 0;
    if (dp[i][buy] != -1)
        return dp[i][buy];
    if (buy)
    {
        profit = max(-vec[i] + buyandsellstockmemo(i + 1, 0, vec, dp), 0 + buyandsellstockmemo(i + 1, 1, vec, dp)); // profit1
                                                                                                                    // in the buy we have checked two conditions either to buy on that day or not buy on that
                                                                                                                    // we are buying so there is -  negative sign
    }
    else
    {
        // selling so the added value is +  positive
        profit = max(vec[i] + buyandsellstockmemo(i + 1, 1, vec, dp), 0 + buyandsellstockmemo(i + 1, 0, vec, dp)); // profit2
    }
    return dp[i][buy] = profit;
}

// tabulation
int buyandsellstockitertive(int n, vector<int> vec, vector<vector<int>> &dp)
{

    dp[n][0] = dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {
            long profit = 0;
            if (j)
            {
                profit = max(-vec[i] + dp[i + 1][0], 0 + dp[i + 1][1]); // profit1
                                                                        // in the buy we have checked two conditions either to buy on that day or not buy on that
                                                                        // we are buying so there is -  negative sign
            }
            else
            {
                // selling so the added value is +  positive
                profit = max(vec[i] + dp[i + 1][1], 0 + dp[i + 1][0]); // profit2
            }
            dp[i][j] = profit;
        }
    }
    return dp[0][1];
}

// space optimizatoin
int buyandsellstockspaceopti(int n, vector<int> vec)
{

    vector<int>ahead(2,0),curr(2,0);
    // just 4 variables to calculate 
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {
            long profit = 0;
            if (j)
            {
                profit = max(-vec[i] + ahead[0], 0 + ahead[1]); // profit1
                                                                        // in the buy we have checked two conditions either to buy on that day or not buy on that
                                                                        // we are buying so there is -  negative sign
            }
            else
            {
                // selling so the added value is +  positive
                profit = max(vec[i] + ahead[1], 0 + ahead[0]); // profit2
            }
            curr[j] = profit;
        }
        ahead=curr;
    }
    return ahead[1];
}
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));      // 2 because we can buy or not is taken as two steps
    vector<vector<int>> dpit(n + 1, vector<int>(2, 0)); // 2 because we can buy or not is taken as two steps
    cout << buyandsellstock(0, 1, prices) << endl;
    cout << buyandsellstockmemo(0, 1, prices, dp) << endl;
    cout << buyandsellstockitertive(n, prices, dpit) << endl;
    cout << buyandsellstockspaceopti(n, prices) << endl;
    return 0;
}