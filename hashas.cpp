#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

string paverstihex(string& s, bool upper_case)
{ 		
		
		for (int i = 0; i < 256; i++) {
			s.append(pridedas);
		}
	
		for (int i = 0; i < s.length(); ++i) {
			bitset<64> bs4(s[i]);
		}
		static const char hex_skaiciai[] = "0123456789ABCDEF";

		std::string output;
		output.reserve(s.length() * 2);
		for (unsigned char c : s)
		{
			output.push_back(hex_skaiciai[c >> 4]);
			output.push_back(hex_skaiciai[c & 15]);
		}
		if (output.length() > 256) {
			while (output.length() != 256) {
				output.pop_back();
			}
		}
		return output;
  
}
int main() {
	string myString = "Hello world";
	string hex = paverstihex(myString,true);
	cout << hex;

}
