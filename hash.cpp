#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include <vector>
#include <bitset>

using namespace std;

int hashw(const string& s)
{
	int h = 0;
	for (int i = 0; i < s.length(); i++)
		h += s[i];
	return h;
}

template<size_t N>
std::string bitset_to_string(std::bitset<N> bits) {
	static_assert(N % CHAR_BIT == 0, L"bitset size must be multiple of char");
	std::string toReturn;
	for (size_t j = 0; j < N / CHAR_BIT; ++j)
	{
		char next = 0;
		for (size_t i = 0; i < CHAR_BIT; ++i)
		{
			size_t index = N - (CHAR_BIT * j) - i - 1;
			size_t pos = CHAR_BIT - i - 1;
			if (bits[index])
				next |= (1 << pos);
		}
		toReturn.push_back(next);
	}
	return toReturn;
}

string paverstihex(string& s, bool upper_case /* = true */)
{
	ostringstream ret;

	string pridedas = s;
	string simbolis = "";
	string tuscia = "";

		for (int i = 0; i < 256; i++) {
			s.append(pridedas);
		}
		for (int i = 0; i < s.length(); ++i) {
			bitset<64> bs4(s[i]);
			bs4.flip();
			simbolis = bitset_to_string(bs4);
			tuscia.append(simbolis);
		}
		pridedas.append(tuscia);
		s = pridedas;
		cout << s.length() << endl;
		if (s.length() > 256) {
			while (s.length() != 256) {
				s.pop_back();
			}
		}
		cout << s.length() << endl;
	/*for (string::size_type i = 0; i < s.length(); ++i)
		ret << std::hex << std::setfill('0') << std::setw(2) << (upper_case ? std::uppercase : std::nouppercase) << (int)s[i];*/
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
	//return ret.str();
}
int main() {
	string myString = "Hello world";
	string hex = paverstihex(myString,true);
	cout << hex;




}