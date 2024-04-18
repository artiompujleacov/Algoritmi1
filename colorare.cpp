#include <fstream>
#include <iostream>

using namespace std;

const long long MOD = 1000000007;

int fast_pow(int base, int exponent, int mod) {
  int half = 0;
  if (exponent == 0) {
    return 1;
  }
  if (exponent % 2 == 0) {
    half = fast_pow(base, exponent / 2, mod);
    return ((long long)half * half) % mod;
  }
  return ((long long)base * fast_pow(base, exponent - 1, mod)) % mod;
}

long long coloreaza(int n, ifstream &inFile) {
  long long sum = 1;
  char type, last = 0;
  int m;

  for (long long i = 0; i < n; ++i) {
    inFile >> m >> type;
    for (int j = 0; j < m; j++) {
      if (j >= 1) {
        if (last == 'V') {
          switch (type) {
          case 'V':
            sum = (sum * fast_pow(2, m - 1, MOD)) % MOD;
            last = 'V';
            break;
          case 'H':
            sum = (sum * fast_pow(2, m - 1, MOD)) % MOD;
            last = 'H';
            break;
          }
        } else if (last == 'H') {
          switch (type) {
          case 'V':
            sum = (sum * 1) % MOD;
            last = 'V';
            break;
          case 'H':
            sum = (sum * fast_pow(3, m - 1, MOD)) % MOD;
            last = 'H';
            break;
          }
        }
        break;
      } else if (j == 0) {
        if (last == 0) {
          switch (type) {
          case 'V':
            sum = (sum * 3) % MOD;
            last = 'V';
            break;
          case 'H':
            sum = (sum * 6) % MOD;
            last = 'H';
            break;
          }
        } else if (last == 'V') {
          switch (type) {
          case 'V':
            sum = (sum * 2) % MOD;
            last = 'V';
            break;
          case 'H':
            sum = (sum * 2) % MOD;
            last = 'H';
            break;
          }
        } else if (last == 'H') {
          switch (type) {
          case 'V':
            sum = (sum * 1) % MOD;
            last = 'V';
            break;
          case 'H':
            sum = (sum * 3) % MOD;
            last = 'H';
            break;
          }
        }
      }
    }
  }
  return sum;
}

int main(int argc, char *argv[]) {
  ifstream inFile("colorare.in");
  ofstream outFile("colorare.out");

  long long n;
  inFile >> n;
  long long sum = 1;

  sum = coloreaza(n, inFile);
  outFile << sum << endl;

  inFile.close();
  outFile.close();
  return 0;
}
