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
    string text;
    int key;
    int choice;
    
    const char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int alphabetSize = sizeof(alphabet) / sizeof(alphabet[0]);

    const char alphabet_rus[] = {
    'А','Б','В','Г','Д','Е','Ж','З','И','Й','К','Л','М',
    'Н','О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Щ',
    'Ъ','Ы','Ь','Э','Ю','Я'
    };
	int alphabetSize_rus = sizeof(alphabet_rus) / sizeof(alphabet_rus[0]);

	cout << "choose language - Выберите язык: (1) English | (2) Русский" << endl;
	int lang_choice;
	cin >> lang_choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

	if (cin.fail() || (lang_choice != 1 && lang_choice != 2)) {
    cerr << "Invalid choice! Please enter 1 for English or 2 for Русский!" << endl;
        return 1;
	}

    switch (lang_choice) {
        case 1:
            cout << "You chose English." << endl;
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
            break;
        case 2:
            cout << "Вы выбрали Русский." << endl;
            cout << "Доступные варианты: (1) шифрование | (2) расшифровка" << endl;
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (cin.fail() || (choice != 1 && choice != 2)) {
				cerr << "Неверный выбор! Пожалуйста, введите 1 для шифрования или 2 для расшифровки!" << endl;
                return 1;
            }

            switch (choice) {
            case 1: {
				cout << "Введите текст: ";
                getline(cin, text);
				cout << "Введите ключ: ";
                cin >> key;

                if (cin.fail() || (key < 0)) {    
					cerr << "Неверный ключ! Пожалуйста, введите положительное целое число!" << endl;
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
					cerr << "Ошибка! Не удалось прочитать из файла или файл пуст!" << endl;
                    return 1;
                }

				cout << "Введите ключ: ";
                cin >> key;

                if (cin.fail() || (key < 0)) {
					cerr << "Неверный ключ! Пожалуйста, введите положительное целое число!" << endl;
                    return 1;
                }

                string result = decryptObj.caesarDecrypt(encryptedText, key, alphabet, alphabetSize);
                cout << "Результат: " << result << endl;

                break;
            }
            default:
				cerr << "Неверный выбор!" << endl;
                break;
            }
            break;
        default:
            cerr << "Invalid language choice! | Неверный выбор языка!" << endl;
            return 1;
	}

	system("pause");
    
    return 0;
}
