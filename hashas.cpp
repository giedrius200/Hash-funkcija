#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include <vector>
#include <bitset>

#include <fstream>

using namespace std;

template<size_t N>
std::string bitset_to_string(std::bitset<N> bits) {
	static_assert(N % CHAR_BIT == 0, L);
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

#include <type_traits>

#define IS_INTEGRAL(T) typename std::enable_if< std::is_integral<T>::value >::type* = 0

template<class T>
std::string integral_to_binary_string(T byte, IS_INTEGRAL(T))
{
	std::bitset<sizeof(T)* CHAR_BIT> bs(byte);
	return bs.to_string();
}

string paverstihex(string& s, bool upper_case)
{
	ostringstream ret;

	string pridedas = s;
	string simbolis = "";
	string tuscia = "";

	char simbolisc;

	string stringas = "kriptografija";

	string pridedass = stringas;

	int bitai;

		for (int i = 0; i < 64; i++) {
			s.append(pridedas);
			stringas.append(pridedass);
		}
		for (int i = 0; i < s.length(); ++i) {
			bitset<8> bs4(s[i]);
			bitset<8> bar(stringas[i]);
			bitset<8> rez(bs4 ^= bar);

			simbolis = bitset_to_string(rez);
			tuscia.append(simbolis);
		}
		pridedas.append(tuscia);
		s = pridedas;

		if (s.length() > 64) {
			while (s.length() != 64) {
				s.pop_back();
			}
		}
	
		static const char hex_skaiciai[] = "0123456789ABCDEF";

		std::string output;
		output.reserve(s.length() * 2);
		for (unsigned char c : s)
		{
			output.push_back(hex_skaiciai[c >> 4]);
			output.push_back(hex_skaiciai[c & 15]);
		}
		if (output.length() > 64) {
			while (output.length() != 64) {
				output.pop_back();
			}
		}
		return output;
	
}
int main() {
	string filename;

	char pasirinkimas;

	string hex;

	cout << "Ar norite skaityti zodzius is failo? (t, f)" << endl;
	cin >> pasirinkimas;
	if (pasirinkimas == 'f') {
		cout << "Iveskite zodi" << endl;
		string myString = "";
		cin >> myString;
		hex = paverstihex(myString, true);
		cout << hex << endl;
		string pasirink = "";

		int skaiciuok = 0;

		cout << endl;
		while (pasirink != "n")
		{

			cout << "Ar dar viena zodi? Jei taip veskite, jei ne parasykite n" << endl;
			cin >> pasirink;

			if (pasirink == "n") { break; }

			hex = paverstihex(pasirink, true);
			skaiciuok++;
			cout <<skaiciuok << ".      " << hex << endl;

			cout << endl;
			
		}

	}

	else if(pasirinkimas == 't'){
		cout << "Iveskite failo pavadinima " << endl;

		cin >> filename;

		filename = filename + ".txt";

		ifstream file;

		ofstream hexai;

		hexai.open("hexai.txt");

		file.open(filename);

		string stringas;

		string hexas;

		if (file.is_open())
		{
			
			while (!file.eof())
			{
				file >> stringas;

				hexas = paverstihex(stringas, true);
				hexai << hexas << endl;

			}
		}
	}



}
