#ifndef ENCRYPT_RUS_H
#define ENCRYPT_RUS_H

#include <string>

class Encrypt_rus {
private:
	std::string en_rus;
public:
	Encrypt_rus() : en_rus("") {}
	Encrypt_rus(std::string);

	std::string getEn() const;

	std::wstring caesarEncrypt(const std::wstring& text, int shift, const wchar_t alphabet[], size_t alphabetSize);

	void writeToFile(const std::wstring& filename, const std::wstring& content);
};

#endif