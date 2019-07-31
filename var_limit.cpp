#include<iostream>
#include<string>
#include<limits>
using namespace std;

int main() {
    cout << "[type] \t\t"       << "[所占字节数]\t[最大值]\t\t[最小值]" << endl;
    cout << "bool: \t\t"        <<  sizeof(bool)            << "\t\t" << (numeric_limits<bool>::max)()        << "\t\t\t" << (numeric_limits<bool>::min)()          << endl;
    cout << "char: \t\t"        <<  sizeof(char)            << "\t\t" << CHAR_MAX                             << "\t\t\t" << CHAR_MIN                               << endl;
    cout << "signed char: \t"   <<  sizeof(signed char)     << "\t\t" << SCHAR_MAX                            << "\t\t\t" << SCHAR_MIN                              << endl;
    cout << "unsigned char: \t" <<  sizeof(unsigned char)   << "\t\t" << UCHAR_MAX                            << "\t\t\t" << (numeric_limits<unsigned char>::min)() << endl;
    cout << "wchar_t: \t"       <<  sizeof(wchar_t)         << "\t\t" << (numeric_limits<wchar_t>::max)()     << "\t\t\t" << (numeric_limits<wchar_t>::min)()       << endl;
    cout << "short: \t\t"       <<  sizeof(short)           << "\t\t" << SHRT_MAX                             << "\t\t\t" << SHRT_MIN                               << endl;
    cout << "int: \t\t"         <<  sizeof(int)             << "\t\t" << INT_MAX                              << "\t\t"   << INT_MIN                                << endl;
    cout << "unsigned: \t"      <<  sizeof(unsigned)        << "\t\t" << UINT_MAX                             << "\t\t"   << (numeric_limits<unsigned>::min)()      << endl;
    cout << "long: \t\t"        <<  sizeof(long)            << "\t\t" << LONG_MAX                             << "\t\t"   << LONG_MIN                               << endl;
    cout << "unsigned long: \t" <<  sizeof(unsigned long)   << "\t\t" << ULONG_MAX                            << "\t\t"   << (numeric_limits<unsigned long>::min)() << endl;
    cout << "long long: \t"     <<  sizeof(long long)       << "\t\t" << LLONG_MAX                            << "\t"     << LLONG_MIN                              << endl;
    cout << "double: \t"        <<  sizeof(double)          << "\t\t" << (numeric_limits<double>::max)()      << "\t\t"   << (numeric_limits<double>::min)()        << endl;
    cout << "long double: \t"   <<  sizeof(long double)     << "\t\t" << (numeric_limits<long double>::max)() << "\t\t"   << (numeric_limits<long double>::min)()   << endl;
    cout << "float: \t\t"       <<  sizeof(float)           << "\t\t" << (numeric_limits<float>::max)()       << "\t\t"   << (numeric_limits<float>::min)()         << endl;
    cout << "size_t: \t"        <<  sizeof(size_t)          << "\t\t" << (numeric_limits<size_t>::max)()      << "\t\t"   << (numeric_limits<size_t>::min)()        << endl;
    cout << "string: \t"        <<  sizeof(string)          << endl;
    cout << "[type] \t\t"       <<  "[所占字节数]\t[最大值]\t\t[最小值]" << endl;
    return 0;
}
