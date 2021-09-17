# Blockchain


Prideta
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
for (int i = 0; i < s.length(); ++i) {
			bitset<64> bs4(s[i]);
			bs4.flip();
			simbolis = bitset_to_string(bs4);
			tuscia.append(simbolis);
		}
