#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int i, int j, vector<int>& P, vector<int>& W) {
  if(!i || !j)
    return 0;

  // edge case I missed. If weight would surpass max, don't check it.
  if(W[i-1] > j)
    return knapsack(i-1, j, P, W);
  return max(knapsack(i-1, j, P, W),
             knapsack(i-1, j - W[i-1], P, W) + P[i-1]);
}

int main() {
  vector<int> P = {1,2,5,6};
  vector<int> W = {2,3,4,5};
  int nMax = P.size();
  int wMax = 8; // maxVal = 8
  //vector<int> P = {60,100,120};
  //vector<int> W = {10,20,30};
  //int nMax = P.size();
  //int wMax = 50; // maxVal = 220
  
  int maxVal = knapsack(nMax, wMax, P, W);
  cout << "maxVal = " << maxVal << endl;
}
