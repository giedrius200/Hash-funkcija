# Blockchain

**Pridedas bitset**
```
for (int i = 0; i < s.length(); ++i) {
			bitset<8> bs4(s[i]);
			bitset<8> bar(stringas[i]);
			bitset<8> bs3(bs4 <<= 2);
			bitset<8> rez(bs3 ^= bar);
		}
```
