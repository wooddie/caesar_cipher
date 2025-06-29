//
//  encrypt.h
//  Encrypt_Decrypt
//
//  Created by Канапия Базарбаев on 03.12.2024.
//

#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <string>

class Encrypt {
    private:
        std::string en;
    public:
        Encrypt() : en("") {};
        Encrypt(std::string);
    
        std::string getEn();
    
        std::string caesarEncrypt(const std::string& text, int shift, const char alphabet[], int alphabetSize);
    
        void writeToFile(const std::string& filename, const std::string& content);
};

#endif
