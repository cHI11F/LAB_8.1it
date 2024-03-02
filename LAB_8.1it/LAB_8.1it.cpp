#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
using namespace std;

int Count(const char* str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '=')
            count++;
    }
    return count;
}

char* Change(const char* str)
{
    size_t len = strlen(str);
    char* tmp = new char[len * 2 + 1];
    char* t = tmp;
    for (size_t i = 0; i < len; i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '=') {
            *t++ = '*';
            *t++ = '*';
        }
        else {
            *t++ = str[i];
        }
    }
    *t = '\0';
    return tmp;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str) << " groups of '+ - ='" << endl;
    char* dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    delete[] dest;
    return 0;
}
