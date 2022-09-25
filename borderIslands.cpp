#include <iostream>
#include <vector>

using namespace std;

void floodFill(int i, int j, int m, int n, vector<vector<int>>& input, int color, int colorOld) {
  // if out of range, already changed, or not the original val
  if(i<0||j<0||i>=m||j>=n || input[i][j]==color || input[i][j]!= colorOld)
    return;
  
  //vector<vector<int>> steps = {{-1,0},{1,0},{0,-1},{0,1}};
  //for(int x, int y : steps) {
  //  floodFill(i+x,j+y,m,n,input,color,colorOld);
  //}
  input[i][j] = 2;
  floodFill(i+1,j,m,n,input,color,colorOld);
  floodFill(i-1,j,m,n,input,color,colorOld);
  floodFill(i,j+1,m,n,input,color,colorOld);
  floodFill(i,j-1,m,n,input,color,colorOld);
}

void borderOnly(vector<vector<int>>& input) {
  int m = input.size();
  int n = input[0].size();

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      //if(input[i][j]) cout << "Filling [" << i << "][" << j << "]\n";
      if(input[i][j]) floodFill(i,j,m,n,input,2,1);
      // if not in top or bottom rows, only do the l/r sides
      if(i && i < m-1) j += n-2;
    }
  }

  //cout << "2 >> 1: " << (2 >> 1) << endl;
  //cout << "1 >> 1: " << (1 >> 1) << endl;
  //cout << "0 >> 1: " << (0 >> 1) << endl;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      input[i][j] = input[i][j] >> 1;
    }
  }
}

void printMap(vector<vector<int>>& input) {
  int m = input.size();
  int n = input[0].size();
  for(int i = 0; i < m; i++) {
    if(!i) cout << "{{";
    else cout << " {";
    for(int j = 0; j < n; j++) {
      if(j) cout << ",";
      cout << input[i][j];
    }
    if(i < m-1) cout << "},\n";
    else cout << "}}\n";
  }
}

int main() {
  vector<vector<int>> input = {{1,0,0,0,0,0},
                               {0,1,0,1,1,1},
                               {0,0,1,0,1,0},
                               {1,1,0,0,1,0},
                               {1,0,1,1,0,0},
                               {1,0,0,0,0,1}};
  cout << "Input:\n";
  printMap(input);
  borderOnly(input);
  cout << "\nOutput:\n";
  printMap(input);
}
