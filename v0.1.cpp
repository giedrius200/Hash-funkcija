#include <iostream>
#include <string>
#include <vector>

#include <bitset>

using namespace std;

#include <type_traits>

#include <sstream>

// SFINAE for safety. Sue me for putting it in a macro for brevity on the function
#define IS_INTEGRAL(T) typename std::enable_if< std::is_integral<T>::value >::type* = 0

template<class T>
std::string integral_to_binary_string(T byte, IS_INTEGRAL(T))
{
    std::bitset<sizeof(T)* CHAR_BIT> bs(byte);
    return bs.to_string();
}

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}

int main() {
    string myString = "Hello World";
    string binary="";

    unsigned long int mybit_int = 0;
    unsigned long int bitai = 0;

    int pakeistas;

    string binarypakeistas;

    //std::stringstream sstream(binarypakeistas);
    std::string output;

    for (std::size_t i = 0; i < myString.size(); ++i)
    {
        //cout << bitset<8>(myString.c_str()[i]);
        bitset<8>b(myString[i]);
        cout << hex << b.to_ulong();
        //cout << mybit_int;

    }
    cout <<endl<< "------------------------------------" << endl;
    for (std::size_t i = 0; i < myString.size(); ++i)
    {
        //cout << bitset<8>(myString.c_str()[i]);
        bitset<30>b(myString[i]);
        for (size_t i = 1; i < b.size(); i += 10) {
            b.set(i);
        }

        //cout << binarypakeistas;
        cout << hex << b.to_ulong();
        //cout << mybit_int;

    }
    //bitai = binaryToDecimal(mybit_int);
    //cout << mybit_int;
    //cout << bitai;
    //cout << binaryToDecimal(num) << endl;

}