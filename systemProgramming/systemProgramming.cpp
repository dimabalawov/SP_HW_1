#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <tchar.h>
#define _UNICODE
using namespace std;

_TCHAR spaceToTab(_TCHAR *str)
{
	cout << "Space to Tab FUNCTION: " << endl;
	for (size_t i = 0; str[i]!= L'\0'; i++)
	{
		if (str[i] == ' ')
		{
			str[i] = '\t';
		}
	}
	wcout << str << endl;
	return *str;
}

void countSymbols(_TCHAR* str)
{
	cout << endl << "Count digits, letters, symbols FUNCTION: " << endl;
	short digits = 0;
	short letters = 0;
	short symbols = 0;
	for (size_t i = 0; str[i] != L'\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			digits++;
		}
		else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			letters++;
		}
		else
			symbols++;
	}
	cout << "Digits: " << digits << endl;
	cout << "Letters: " << letters << endl;
	cout << "Other symbols: " << symbols << endl;
}
void countWords(_TCHAR* str)
{
	cout << endl << "Count words FUNCTION: " << endl;
	short words = 0;
	bool isWord=0;
	for (size_t i = 0; str[i] != L'\0'; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			isWord = 1;
		}
		if (isWord && str[i] == ' ')
		{
			words++;
			isWord = 0;
		}
		if (isWord && str[i+1] == 0)
			words++;
	}
	cout << "Amount of Words: " << words << endl;
}
bool isPalindrome(_TCHAR* str)
{
	cout << endl << "Is Palindrome FUNCTION: " << endl;
	int length = wcslen(str);
	for (size_t i = 0; i < length/2; i++)
	{
		if (str[i] != str[length - i-1])
			return 0;
	}
	return 1;
}
void eraseSymbol(_TCHAR*& str,short index)
{
	cout << endl << "Erase Symbol FUNCTION: " << endl;
	int length = wcslen(str);
	if (index >= length)
	{
		return;
	}
	_TCHAR* newstr = new _TCHAR[length];
	int j = 0;
	for (int i = 0; str[i] != L'\0'; i++)
	{
		if (i != index)
		{
			newstr[j++] = str[i];
		}
	}
	newstr[j] = '\0';
	delete[] str;
	str = newstr;
}
void eraseSymbolAll(_TCHAR*& str, _TCHAR symb)
{
	cout << endl << "Erase All Selected Symbol FUNCTION: " << endl;
	int j = 0;
	int newlength = wcslen(str) + 1;
	for (int i = 0; str[i] != L'\0'; i++)
	{
		if (str[i] == symb)
		{
			newlength--;
		}
	}
	_TCHAR* newstr = new _TCHAR[newlength];
	for (int i = 0; str[i] != L'\0'; i++)
	{
		if (str[i] != symb)
		{
			newstr[j++] = str[i];
		}
	}
	newstr[j] = L'\0';
	delete[] str;
	str = newstr;
}
void insertSymbol(_TCHAR*& str, short index, _TCHAR symb)
{
	cout << endl << "Insert Symbol FUNCTION: " << endl;
	int length = wcslen(str)+2;
	if (index >= length)
	{
		return;
	}
	_TCHAR* newstr = new _TCHAR[length];
	int j = 0;
	for (int i = 0; str[i] != L'\0'; i++)
	{
		if (i == index)
		{
			newstr[j++] = symb;
			newstr[j++] = str[i];
		}
		else
			newstr[j++] = str[i];
	}
	newstr[j] = '\0';
	delete[] str;
	str = newstr;
}

int main()
{
	setlocale(LC_ALL, " ");
	_TCHAR str[15] = _TEXT("H el l o123");
	spaceToTab(str);
	_TCHAR str2[15] = _TEXT("H el l o123");
	countSymbols(str2);
	countWords(str2);
	_TCHAR str3[15] = _TEXT("TENET");
	cout << isPalindrome(str3) << endl;
	_TCHAR* str4 = new _TCHAR[6];
	wcscpy(str4, L"Hello");
	eraseSymbol(str4, 1);
	wcout << str4 << endl;
	_TCHAR* str5 = new _TCHAR[6];
	wcscpy(str5, L"Hello");
	eraseSymbolAll(str5, L'l');
	wcout << str5 << endl;
	_TCHAR* str6 = new _TCHAR[6];
	wcscpy(str6, L"Hello");
	insertSymbol(str6,2, L'l');
	wcout << str6 << endl;
}

