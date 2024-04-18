#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

double binary_search(vector<double> &praguri, vector<double> &puteri, int n) {
  double left = *min_element(praguri.begin(), praguri.end());
  double right = *max_element(praguri.begin(), praguri.end());
  double max_power = INT_MIN;
  double epsilon = 0.000001;

  while (right - left > epsilon) {
    double mid = (left + right) / 2;
    double current_power = INT_MAX;
    for (int i = 0; i < n; ++i) {
      current_power = min(current_power, puteri[i] - abs(mid - praguri[i]));
    }

    if (current_power > max_power) {
      max_power = current_power;
    }

    double power_left = INT_MAX, power_right = INT_MAX;
    for (int i = 0; i < n; ++i) {
      power_left =
          min(power_left, puteri[i] - abs((mid - epsilon) - praguri[i]));
      power_right =
          min(power_right, puteri[i] - abs((mid + epsilon) - praguri[i]));
    }

    if (power_right > current_power) {
      left = mid;
    } else {
      right = mid;
    }
  }

  return max_power;
}

int main(int argc, char *argv[]) {
  ifstream inFile("servere.in");
  ofstream outFile("servere.out");

  int n;
  inFile >> n;
  vector<double> praguri(n), puteri(n);
  for (int i = 0; i < n; ++i)
    inFile >> puteri[i];
  for (int i = 0; i < n; ++i)
    inFile >> praguri[i];

  double optimal_power = binary_search(praguri, puteri, n);
  outFile << fixed << setprecision(1) << optimal_power << endl;

  inFile.close();
  outFile.close();

  return 0;
}
