#ifndef DECRYPT_RUS_H
#define DECRYPT_RUS_H

#include <string>

class Decrypt_rus {
private:
	std::string de_rus;

public:
	Decrypt_rus() : de_rus("") {}
	Decrypt_rus(std::string d);

	std::string getDe() const;

	std::wstring caesarDecrypt(const std::wstring& encryptText, int key, const wchar_t alphabet[], size_t alphabetSize);

	std::wstring readFromFile(const std::wstring& filename);
};

#endif