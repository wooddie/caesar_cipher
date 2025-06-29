//
//  decrypt.cpp
//  Encrypt_Decrypt
//
//  Created by Канапия Базарбаев on 03.12.2024.
//

#include <iostream>
#include <fstream>
#include "decrypt.h"

using namespace std;

Decrypt :: Decrypt(string d) : de(d) {};

string Decrypt :: getDe() {
    return de;
}

string Decrypt :: caesarDecrypt(const std::string &encryptText, int key, const char alphabet[], int alphabetSize) {
    string result;
    
    for(char c : encryptText) {
        int index = -1;
        
        for(int i = 0; i < alphabetSize; i++) {
            if(alphabet[i] == toupper(c)) {
                index = i;
                break;
            }
        }
        
        if(index != -1) {
            int newIndex = (index - key + alphabetSize) % alphabetSize;
            result += alphabet[newIndex];
        } else {
            result += tolower(c);
        }
    }
    
    return result;
}

string Decrypt :: readFromFile(const string& filename) {
    ifstream inFile(filename, ios::in);
    if (!inFile.is_open()) {
        cerr << "Error: Could not open file " << filename << " for reading!" << endl;
        return "";
    }
    
    string content;
    getline(inFile, content, '\0');
    inFile.close();
    return content;
}
