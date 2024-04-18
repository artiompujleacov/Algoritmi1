#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cripteaza(vector<string> words, int N) {
  int max_length = 0;

  for (char dominant_letter = 'a'; dominant_letter <= 'z'; ++dominant_letter) {
    sort(words.begin(), words.end(),
         [dominant_letter](const string &a, const string &b) {
           double ratio_a =
               count(a.begin(), a.end(), dominant_letter) / (double)a.size();
           double ratio_b =
               count(b.begin(), b.end(), dominant_letter) / (double)b.size();
           return ratio_a > ratio_b;
         });

    vector<int> dp(N + 1, 0);
    vector<int> dom_count(N + 1, 0);
    vector<int> non_dom_count(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
      int current_dom =
          count(words[i - 1].begin(), words[i - 1].end(), dominant_letter);
      int current_non_dom = words[i - 1].size() - current_dom;

      for (int j = 0; j < i; ++j) {
        int total_dom = dom_count[j] + current_dom;
        int total_non_dom = non_dom_count[j] + current_non_dom;

        if (total_dom - total_non_dom - 1 >= 0) {
          if (dp[j] + (int)words[i - 1].size() > dp[i]) {
            dp[i] = dp[j] + words[i - 1].size();
            dom_count[i] = total_dom;
            non_dom_count[i] = total_non_dom;
          }
        }
      }
    }

    max_length = max(max_length, *max_element(dp.begin(), dp.end()));
  }
  return max_length;
}

int main(int argc, char *argv[]) {
  int N;
  ifstream inFile("criptat.in");
  ofstream outFile("criptat.out");
  inFile >> N;

  vector<string> words(N);
  for (int i = 0; i < N; ++i) {
    inFile >> words[i];
  }

  int max_length = cripteaza(words, N);
  outFile << max_length << endl;
  inFile.close();
  return 0;
}
