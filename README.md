# Blockchain
**Pridėdas chronos**
```
auto startv = std::chrono::high_resolution_clock::now();
auto start = std::chrono::high_resolution_clock::now();

hexas = paverstihex(yra, true);

auto diff = std::chrono::high_resolution_clock::now() - start;
auto t1 = std::chrono::duration_cast<std::chrono::microseconds>(diff);

hexai << "Uztruko:  " << t1.count() <<" ms"<< std::endl;

auto diffv = std::chrono::high_resolution_clock::now() - startv;
auto tv = std::chrono::duration_cast<std::chrono::microseconds>(diffv);
hexai << "----------------------------------------------" << endl;
hexai << "Is viso uztruko:  " << bendra << " ms" << std::endl;
```
