#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include <vector>
#include <bitset>

#include <fstream>

#include <chrono>

using namespace std;

template<size_t N>
std::string bitset_to_string(std::bitset<N> bits) {
	static_assert(N % CHAR_BIT == 0, L"");
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

bool is_emptyy(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

string paverstihex(string& s, bool upper_case /* = true */)
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
			if (s.length() > 64) {
				break;
			}
			s.append(pridedas);
			stringas.append(pridedass);

		}

		while (s.length() > stringas.length()) {

			stringas.append(pridedass+s);

		}

		for (int i = 0; i < s.length(); ++i) {
			bitset<8> bs4(s[i]);
			bitset<8> bar(stringas[i]);
			bitset<8> bs3(bs4 <<= 2);
			bitset<8> rez(bs3 ^= bar);

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
		auto start = std::chrono::high_resolution_clock::now();
		hex = paverstihex(myString, true);
		auto diff = std::chrono::high_resolution_clock::now() - start;
		auto t1 = std::chrono::duration_cast<std::chrono::microseconds>(diff);
		std::cout << "Uztruko:  " << t1.count() << std::endl;
		cout << hex << endl;
		string pasirink = "";

		int skaiciuok = 0;

		cout << endl;
		while (pasirink != "n")
		{

			cout << "Ar dar viena zodi? Jei taip veskite, jei ne parasykite n" << endl;
			cin >> pasirink;

			if (pasirink == "n") { break; }
			auto start = std::chrono::high_resolution_clock::now();
			hex = paverstihex(pasirink, true);
			auto diff = std::chrono::high_resolution_clock::now() - start;
			auto t1 = std::chrono::duration_cast<std::chrono::microseconds>(diff);
			skaiciuok++;
			std::cout << "Uztruko:  " << t1.count() << std::endl;
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

		char eilute;

		bool tuscias;

		int kiek = 0;

		string sutapo;

		int bendra = 0;

		if (file.is_open())
		{

			if (is_emptyy(file)) {
				auto startv = std::chrono::high_resolution_clock::now();
				string yra;
				yra.append("Tuscias");
				auto start = std::chrono::high_resolution_clock::now();
				hexas = paverstihex(yra, true);
				auto diff = std::chrono::high_resolution_clock::now() - start;
				auto t1 = std::chrono::duration_cast<std::chrono::microseconds>(diff);
				hexai << "Uztruko:  " << t1.count() <<" ms"<< std::endl;

				hexai << hexas << endl;

				auto laikas= t1.count();
			    bendra = bendra + laikas;

				auto diffv = std::chrono::high_resolution_clock::now() - startv;
				auto tv = std::chrono::duration_cast<std::chrono::microseconds>(diffv);
				hexai << "----------------------------------------------" << endl;
				hexai << "Is viso uztruko:  " << bendra << " ms" << std::endl;
				
			}

			if (is_emptyy(file) == false) {

				cout << "Ar skaiyti kas eilute? (t, n) " << endl;

				cin >> eilute;

				if (eilute == 't') {
					auto startv = std::chrono::high_resolution_clock::now();
					for (std::string line; getline(file, line); )
					{
						while (line.length() == 0)
							getline(cin, line);
						auto start = std::chrono::high_resolution_clock::now();
						hexas = paverstihex(line, true);
						auto diff = std::chrono::high_resolution_clock::now() - start;
						auto t1 = std::chrono::duration_cast<std::chrono::microseconds>(diff);
						hexai << hexas << endl;
						if (hexas == sutapo) {
							kiek++;
						}
						sutapo = hexas;
						hexai << "Uztruko:  " << t1.count() << " ms" << std::endl;
						auto laikas = t1.count();
						bendra = bendra + laikas;


					}
					auto diffv = std::chrono::high_resolution_clock::now() - startv;
					auto tv = std::chrono::duration_cast<std::chrono::microseconds>(diffv);
					hexai << "----------------------------------------------" << endl;
					hexai << "Is viso uztruko:  " << bendra << " microseconds" << std::endl;
					hexai << "----------------------------------------------" << endl;
					hexai << "Sutapimu:  " << kiek << std::endl;
				}
				if (eilute == 'n') {
					auto startv = std::chrono::high_resolution_clock::now();
					while (!file.eof())
					{

						file >> stringas;
						auto start = std::chrono::high_resolution_clock::now();
						hexas = paverstihex(stringas, true);
						auto diff = std::chrono::high_resolution_clock::now() - start;
						auto t1 = std::chrono::duration_cast<std::chrono::microseconds>(diff);
						hexai << "Uztruko:  " << t1.count() << " ms" << std::endl;
						auto laikas= t1.count();
						bendra = bendra + laikas;
						if (hexas == sutapo) {
							kiek++;
						}
						sutapo = hexas;
						hexai << hexas << endl;

					}
					auto diffv = std::chrono::high_resolution_clock::now() - startv;
					auto tv = std::chrono::duration_cast<std::chrono::microseconds>(diffv);
					hexai << "----------------------------------------------" << endl;
					hexai << "Is viso uztruko:  " << bendra << " microseconds" << std::endl;
					hexai << "----------------------------------------------" << endl;
					hexai << "Sutapimu:  " << kiek << std::endl;
				}
			}
		}
	}



}
