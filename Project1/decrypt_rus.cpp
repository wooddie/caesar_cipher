#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <cwctype>
#include "decrypt_rus.h"

using namespace std;

Decrypt_rus::Decrypt_rus(string d) : de_rus(d) {}

string Decrypt_rus::getDe() const {
	return de_rus;
}

std::wstring Decrypt_rus::caesarDecrypt(const std::wstring& encryptText, int key, const wchar_t alphabet[], size_t alphabetSize) {
	std::wstring result;
	for (wchar_t c : encryptText) {
		int index = -1;
		for (size_t i = 0; i < alphabetSize; i++) {
			if (alphabet[i] == std::towupper(c)) {
				index = i;
				break;
			}
		}
		if (index != -1) {
			int newIndex = (index - key + alphabetSize) % alphabetSize;
			result += alphabet[newIndex];
		}
		else {
			result += std::towlower(c);
		}
	}
	return result;
}

std::wstring Decrypt_rus::readFromFile(const std::wstring& filename) {
	std::wifstream inFile(filename);
	inFile.imbue(std::locale(""));

	if (!inFile.is_open()) {
		std::wcerr << L"Ошибка: не удалось открыть файл для чтения: " << filename << std::endl;
		return L"";
	}

	std::wstring content;
	std::getline(inFile, content, L'\0');
	inFile.close();
	return content;
}