#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

vector<double> mergeVectors(vector<double> &v1, vector<double> &v2) {
  vector<double> merged;
  merged.reserve(v1.size() + v2.size());
  merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(merged));
  merged.erase(unique(merged.begin(), merged.end()), merged.end());
  return merged;
}

double oferta(int N, int M, vector<double> prices) {
  vector<vector<double>> dp(N + 1);
  dp[0].push_back(0);

  for (int i = 1; i <= N; ++i) {
    for (auto &x : dp[i - 1]) {
      dp[i].push_back(x + prices[i - 1]);
    }
    sort(dp[i].begin(), dp[i].end());
    dp[i].erase(unique(dp[i].begin(), dp[i].end()), dp[i].end());

    if (i >= 2) {
      vector<double> temp;
      for (auto &x : dp[i - 2]) {
        temp.push_back(x + max(prices[i - 1], prices[i - 2]) +
                       min(prices[i - 1], prices[i - 2]) / 2);
      }
      dp[i] = mergeVectors(dp[i], temp);
    }
    if (i >= 3) {
      vector<double> temp;
      for (auto &x : dp[i - 3]) {
        vector<double> three_prices = {prices[i - 1], prices[i - 2],
                                       prices[i - 3]};
        sort(three_prices.begin(), three_prices.end());
        temp.push_back(x + three_prices[2] + three_prices[1]);
      }
      dp[i] = mergeVectors(dp[i], temp);
    }
    while (dp[i].size() > M) {
      dp[i].pop_back();
    }
  }
  if (M > dp[N].size()) {
    return -1;
  } else {
    return dp[N][M - 1];
  }
}

int main(int argc, char *argv[]) {
  int N, M;
  ifstream inFile("oferta.in");
  ofstream outFile("oferta.out");
  inFile >> N;
  inFile >> M;

  vector<double> prices(N);
  for (int i = 0; i < N; ++i) {
    inFile >> prices[i];
  }

  outFile << fixed << setprecision(2) << oferta(N, M, prices) << endl;

  inFile.close();
  outFile.close();

  return 0;
}
