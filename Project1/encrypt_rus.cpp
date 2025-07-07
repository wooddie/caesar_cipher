#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <cwctype>
#include "encrypt_rus.h"

using namespace std;

Encrypt_rus::Encrypt_rus(string e) : en_rus(e) {}

string Encrypt_rus::getEn() const {
	return en_rus;
}

std::wstring Encrypt_rus::caesarEncrypt(const std::wstring& text, int shift, const wchar_t alphabet[], size_t alphabetSize) {
	std::wstring result;
	for (wchar_t c : text) {
		int index = -1;
		for (size_t i = 0; i < alphabetSize; i++) {
			if (alphabet[i] == std::towupper(c)) {
				index = i;
				break;
			}
		}
		if (index != -1) {
			int newIndex = (index + shift) % alphabetSize;
			result += alphabet[newIndex];
		} else {
			result += c;
		}
	}
	return result;
}

void Encrypt_rus::writeToFile(const std::wstring& filename, const std::wstring& content) {
	std::wofstream outFile(filename);
	outFile.imbue(std::locale(""));
	if (!outFile.is_open()) {
		wcerr << L"Ошибка: не удалось открыть файл для записи: " << filename << endl;
		return;
	}
	outFile << content;
	outFile.close();
	wcout << L"Данные успешно записаны в " << filename << endl;
}