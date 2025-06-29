//
//  encrypt.cpp
//  Encrypt_Decrypt
//
//  Created by Канапия Базарбаев on 03.12.2024.
//

#include <iostream>
#include <fstream>
#include "encrypt.h"

using namespace std;

Encrypt :: Encrypt(string e) : en(e) {};

string Encrypt :: getEn() {
    return en;
}

string Encrypt :: caesarEncrypt(const string& text, int shift, const char alphabet[], int alphabetSize) {
    string result;
    
    for(char c : text) {
        int index = -1;
        
        for(int i = 0; i < alphabetSize; i++) {
            if(alphabet[i] == toupper(c) ) {
                index = i;
                break;
            }
        }
            
        if(index != -1) {
            int newIndex = (index + shift) % alphabetSize;
            result += alphabet[newIndex];
        } else {
            result += c;
        }
    }
    
    return result;
}

void Encrypt :: writeToFile(const string& filename, const string& content) {
    ofstream outFile(filename, ios::out);
    if (!outFile.is_open()) {
        cerr << "Error: Could not open file " << filename << " for writing!" << endl;
        return;
    }
    
    outFile << content;
    outFile.close();
    cout << "Data successfully written to " << filename << endl;
}
