//
//  decrypt.h
//  Encrypt_Decrypt
//
//  Created by Канапия Базарбаев on 03.12.2024.
//

#ifndef DECRYPT_H
#define DECRYPT_H

#include <string>

class Decrypt {
    private:
        std::string de;
    public:
        Decrypt() : de("") {};
        Decrypt(std::string);

        std::string getDe();

        std::string caesarDecrypt(const std::string& encryptText, int key, const char alphabet[], int alphabetSize);
    
        std::string readFromFile(const std::string& filename);
};

#endif
