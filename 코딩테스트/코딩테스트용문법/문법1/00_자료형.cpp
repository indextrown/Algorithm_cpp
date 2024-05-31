#include <iostream>
#include <limits> 
using namespace std;


int main()
{
    // 크기: 1byte  범위: -128 ~ 127    
    char A = 65;
    char a = 97;


    cout << "char\t\t" << " : " << sizeof(char) << " bytes, 범위: " << (int)numeric_limits<char>::min() << " ~ " << (int)numeric_limits<char>::max() << "\n";
    cout << "unsigned char\t" << " : " << sizeof(unsigned char) << " bytes, 범위: " << (unsigned int)numeric_limits<unsigned char>::min() << " ~ " << (unsigned int)numeric_limits<unsigned char>::max() << "\n";
    cout << "wchar_t\t\t" << " : " << sizeof(wchar_t) << " bytes, 범위: " << numeric_limits<wchar_t>::min() << " ~ " << numeric_limits<wchar_t>::max() << "\n";
    cout << "short\t\t" << " : " << sizeof(short) << " bytes, 범위: " << numeric_limits<short>::min() << " ~ " << numeric_limits<short>::max() << "\n";
    cout << "unsigned short\t" << " : " << sizeof(unsigned short) << " bytes, 범위: " << numeric_limits<unsigned short>::min() << " ~ " << numeric_limits<unsigned short>::max() << "\n";
    cout << "int\t\t" << " : " << sizeof(int) << " bytes, 범위: " << numeric_limits<int>::min() << " ~ " << numeric_limits<int>::max() << "\n";
    cout << "unsigned int\t" << " : " << sizeof(unsigned int) << " bytes, 범위: " << numeric_limits<unsigned int>::min() << " ~ " << numeric_limits<unsigned int>::max() << "\n";
    cout << "long\t\t" << " : " << sizeof(long) << " bytes, 범위: " << numeric_limits<long>::min() << " ~ " << numeric_limits<long>::max() << "\n";
    cout << "unsigned long\t" << " : " << sizeof(unsigned long) << " bytes, 범위: " << numeric_limits<unsigned long>::min() << " ~ " << numeric_limits<unsigned long>::max() << "\n";
    cout << "long long\t" << " : " << sizeof(long long) << " bytes, 범위: " << numeric_limits<long long>::min() << " ~ " << numeric_limits<long long>::max() << "\n";
    cout << "unsigned long long" << " : " << sizeof(unsigned long long) << " bytes, 범위: " << numeric_limits<unsigned long long>::min() << " ~ " << numeric_limits<unsigned long long>::max() << "\n";
    cout << "float\t\t" << " : " << sizeof(float) << " bytes, 범위: " << numeric_limits<float>::min() << " ~ " << numeric_limits<float>::max() << "\n";
    cout << "double\t\t" << " : " << sizeof(double) << " bytes, 범위: " << numeric_limits<double>::min() << " ~ " << numeric_limits<double>::max() << "\n";
    cout << "long double\t" << " : " << sizeof(long double) << " bytes, 범위: " << numeric_limits<long double>::min() << " ~ " << numeric_limits<long double>::max() << "\n";

    return 0;
}