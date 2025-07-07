//
//  main.cpp
//  Encrypt_Decrypt
//
//  Created by Канапия Базарбаев on 03.12.2024.
//

#include <iostream>
#include <fstream>
#include <limits>
#include "encrypt.h"
#include "decrypt.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    string text;
    int key;
    int choice;
    
    const char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int alphabetSize = sizeof(alphabet) / sizeof(alphabet[0]);

    const std::wstring alphabet_rus = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    size_t alphabetSize_rus = alphabet_rus.size();

    cout << "Available options: (1) encrypt | (2) decrypt" << endl;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (cin.fail() || (choice != 1 && choice != 2)) {
        cerr << "Invalid choice! Please enter 1 for encrypt or 2 for decrypt!" << endl;
        return 1;
    }

    switch (choice) {
    case 1: {
        cout << "Enter text: ";
        getline(cin, text);
        cout << "Enter key: ";
        cin >> key;

        if (cin.fail() || (key < 0)) {
            cerr << "Invalid key! Please enter a positive integer!" << endl;
            return 1;
        }

        Encrypt encryptObj;
        string result = encryptObj.caesarEncrypt(text, key, alphabet, alphabetSize);

        cout << "Result: " << result << endl;
        encryptObj.writeToFile("encrypted.txt", result);

        break;
    }
    case 2: {
        Decrypt decryptObj;
        string encryptedText = decryptObj.readFromFile("encrypted.txt");
        if (encryptedText.empty()) {
            cerr << "Error! Could not read from file or file is empty!" << endl;
            return 1;
        }

        cout << "Enter key: ";
        cin >> key;

        if (cin.fail() || (key < 0)) {
            cerr << "Invalid key! Please enter a positive integer!" << endl;
            return 1;
        }

        string result = decryptObj.caesarDecrypt(encryptedText, key, alphabet, alphabetSize);
        cout << "Result: " << result << endl;

        break;
    }
    default:
        cerr << "error" << endl;
        break;
    }

	system("pause");
    
    return 0;
}
