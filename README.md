# Blockchain
**Pridėta bitset to string funkcija, patobulintas bitset**
```
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
for (int i = 0; i < s.length(); ++i) {
			bitset<8> bs4(s[i]);
			bitset<8> bar(stringas[i]);
			bitset<8> bs3(bs4 <<= 2);
			bitset<8> rez(bs3 ^= bar);

			simbolis = bitset_to_string(rez);
			tuscia.append(simbolis);
		}
```
