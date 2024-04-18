#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int maxCommonCompressedLength(vector<int> &A, vector<int> &B) {
  vector<int> common_array;
  int i = 0, j = 0;
  while (i < A.size() && j < B.size()) {
    if (A[i] == B[j]) {
      common_array.push_back(A[i]);
      ++i;
      ++j;
    } else if (A[i] < B[j]) {
      A[i + 1] += A[i];
      ++i;
    } else {
      B[j + 1] += B[j];
      ++j;
    }
  }

  if (i < A.size() || j < B.size()) {
    return -1;
  }
  return common_array.size();
}

int main(int argc, char *argv[]) {
  ifstream inFile("compresie.in");
  ofstream outFile("compresie.out");
  int n, m;
  inFile >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    inFile >> A[i];
  }
  inFile >> m;
  vector<int> B(m);
  for (int i = 0; i < m; ++i) {
    inFile >> B[i];
  }

  outFile << maxCommonCompressedLength(A, B) << endl;

  inFile.close();
  outFile.close();

  return 0;
}
