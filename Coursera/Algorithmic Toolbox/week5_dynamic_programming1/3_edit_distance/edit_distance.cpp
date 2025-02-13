#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int edit_distance(const string &str1, const string &str2)
{
  int dp[str1.size() + 1][str2.size() + 1];
  dp[0][0] = 0;
  for (int i = 1; i <= str1.size(); i++)
  {
    dp[i][0] = dp[i - 1][0] + 1;
  }
  for (int i = 1; i <= str2.size(); i++)
    dp[0][i] = dp[0][i - 1] + 1;
  for (int i = 1; i <= str1.size(); i++)
  {
    for (int j = 1; j <= str2.size(); j++)
    {
      dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + ((str1[i - 1] != str2[j - 1]) ? 1 : 0)});
    }
  }

  return dp[str1.size()][str2.size()];
}

int main()
{
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
