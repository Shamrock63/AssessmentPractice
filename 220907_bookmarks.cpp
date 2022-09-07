#include <iostream>

using namespace std;

long seqsInBook(string book) {
  int bSize = book.size();
  int scan_010[] = {0,0,0};
  int scan_101[] = {0,0,0};
  
  for(int i = 0; i < bSize; i++) {
    //cout << "book[i]: " << book[i] << endl;
    if(book[i] == '0') {
      scan_010[0]++;
      if(scan_101[0]) {
        scan_101[1] += scan_101[0];
      }
      if(scan_010[1]) {
        scan_010[2] += scan_010[1];
      }
    } else {
      scan_101[0]++;
      if(scan_010[0]) {
        scan_010[1] += scan_010[0];
      }
      if(scan_101[1]) {
        scan_101[2] += scan_101[1];
      }
    }
    //cout << "scan_010[]: " << scan_010[0] << " " << scan_010[1] << " " << scan_010[2] << endl;
    //cout << "scan_101[]: " << scan_101[0] << " " << scan_101[1] << " " << scan_101[2] << endl;
  }
  
  long seqs = 0;
  seqs = scan_010[2] + scan_101[2];
  return seqs;
}

int main() {
  string b = "1011101";
  long sequences = seqsInBook(b);
  cout << "Book: " << b << "\nSequences: " << sequences << endl;
}
