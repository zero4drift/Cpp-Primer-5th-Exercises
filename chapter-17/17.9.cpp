#include <string>
#include <iostream>
#include <bitset>

using std::bitset;

int main()
{
  bitset<64> bitvec(32);
  std::cout << bitvec << std::endl;
  // 58*0...100000
  bitset<32> bv(1010101);
  std::cout << bv << std::endl;
  // 57*0...1010101
  // guess expression in textbook misses '0b';
  // but if textbook is right:
  // 12*0...11110110100110110101 
  std::string bstr;
  std::cin >> bstr;
  bitset<8> bv2(bstr);
  std::cout << bv2 << std::endl;
  // the result has 8 bits and content depends on input string;
}
