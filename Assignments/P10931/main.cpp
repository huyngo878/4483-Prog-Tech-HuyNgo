// P10931
// 4883
// Ngo
// August 30, 2023

#include <bitset>
#include <iostream>
#include <algorithm>

#define endl '\n'
using namespace std;

int main() {

  int n;
  std::string::difference_type i;

  std::size_t found;
  while (cin >> n) {
    if(!n) break;
    std::string binary = std::bitset<128>(n).to_string(); // to binary
    binary = binary.erase(0, binary.find_first_not_of('0'));
    cout<<"The parity of ";
    cout<<binary<<" is ";
    cout<< std::count(binary.begin(), binary.end(), '1')<<" (mod 2)."<<endl;
  }
  return 0;
}