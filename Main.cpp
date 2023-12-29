// Made BY Abdul Ahad Ali Khan, Muhammad Awais Ashraf, Ahmed Abubakar Riaz From GIKI 
// All encrypted text and decrypted text will be saved and overwrite in files.
// Password asked in between is "name"

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int encryption(const string &text);
void decryption(int key);

int main()
{
    cout << "            <<<<<<<----------------------------------------------------------------------- >>>>>>" << endl;
    cout << "                                   WELCOME TO ENCRYPTION / DECRYPTION " << endl;
    cout << "            <<<<<<< ---------------------------------------------------------------------- >>>>>>" << endl;

    srand(time(0));

    string textToEncrypt;
    string textfromUser;

    cout << "Enter the text to encrypt: ";
    getline(cin, textToEncrypt);

    // Encryption
    int encryptionKey = encryption(textToEncrypt);

    cout << "Encryption Key: " << encryptionKey << endl;

    decryption(encryptionKey);

    ifstream inputFiles("encrypted_text.txt");
    if (!inputFiles)
    {
        cerr << "Error opening the input file." << endl;
        return 1;
    }

    ofstream outputFile("decrypted_text2.txt");
    if (!outputFile)
    {
        cerr << "Error opening the output file." << endl;
        inputFiles.close();
        return 1;
    }
    cout << "Do you want all possible decryptions press (y/n)" << endl;
    char input;
    cin >> input;
    cin.ignore();

    if (input == 'y')
    {
        string line;
        getline(inputFiles, line);

        for (int i = 1; i <= 26; i++)
        {
            for (int j = 0; j < line.size(); j++)
            {
                char ch = line[j];

                if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                {
                    char base = (ch >= 'a' && ch <= 'z') ? 'a' : 'A';
                    char decryptedChar = (ch - base - i + 26) % 26 + base;
                    outputFile << decryptedChar;
                }
                else
                {
                    outputFile << ch;
                }
            }
            outputFile << '\n'
                       << endl;
        }
        cout << "Possible Decryptions Done" << endl;
    }
    else if (input == 'n')
    {
        cout << "Possible Decryptions Not created" << endl;
    }

    inputFiles.close();
    outputFile.close();

    cout << "Do you want to use premium encryptor (press 0): ";
    int numb;
    cin >> numb;
    cin.ignore();

    if (numb == 0)
    {
        string pass[1] = {"name"};
        cout << "Enter Password to continue" << endl;
        string inppass;
        getline(cin, inppass);
        if (inppass == pass[0])
        {
            string textToEncrypt;

            cout << "Enter the text to encrypt: ";
            getline(cin, textToEncrypt);

            int key[3];
            for (int i = 0; i < 3; i++)
            {
                int a = rand() % 26+1;
                key[i] = a;
            }

            ofstream outputFile("encrypted_text.txt");
            if (!outputFile)
            {
                cout << "Error opening the output file." << endl;
                return 1; // Indicate an error
            }

            for (int i = 0; i < textToEncrypt.size(); ++i)
            {
                char ch = textToEncrypt[i];

                if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                {
                    char base = (ch >= 'a' && ch <= 'z') ? 'a' : 'A';
                    char encryptedChar = (ch - base + key[i % 3]) % 26 + base;
                    outputFile << encryptedChar;
                }
                else
                {
                    outputFile << ch;
                }
            }

            outputFile.close();

            cout << "Keys: ";
            for (int i = 0; i < 3; i++)
            {
                cout << key[i] << " ";
            }
            cout << endl;

            ifstream inputFile("encrypted_text.txt");
            if (!inputFile)
            {
                cerr << "Error opening the input file." << endl;
                return 1; // Indicate an error
            }

            ofstream decryptedOutputFile("decrypted_text.txt");
            if (!decryptedOutputFile)
            {
                cerr << "Error opening the output file." << endl;
                inputFile.close();
                return 1; // Indicate an error
            }

            string textToDecrypt;
            getline(inputFile, textToDecrypt);

            for (int i = 0; i < textToDecrypt.size(); ++i)
            {
                char ch = textToDecrypt[i];

                if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                {
                    char base = (ch >= 'a' && ch <= 'z') ? 'a' : 'A'; // ternary 
                    char decryptedChar = (ch - base - key[i % 3] + 26) % 26 + base;
                    decryptedOutputFile << decryptedChar;
                }
                else
                {
                    decryptedOutputFile << ch;
                }
            }

            inputFile.close();
            decryptedOutputFile.close();

            
        }
        else
        {
            cout << "Incorrect Password. Exiting..." << endl;
        }
    }
    else
    {
        cout << "Thank you for using Encryption and Decryption." << endl;
    }

    cout << "            <<<<<<<----------------------------------------------------------------------- >>>>>>" << endl;
    cout << "                                              THANK YOU " << endl;
    cout << "            <<<<<<< ---------------------------------------------------------------------- >>>>>>" << endl;

    return 0;
}

int encryption(const string &text)
{
    int key = rand() % 26 + 1;

    ofstream outputFile("encrypted_text.txt");
    if (!outputFile)
    {
        cout << "Error opening the output file." << endl;
        return -1;
    }

    for (int i = 0; i < text.size(); ++i)
    {
        char ch = text[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            char base = (ch >= 'a' && ch <= 'z') ? 'a' : 'A';  // ternary operator
            char encryptedChar = (ch - base + key+26) % 26 + base; 
            outputFile << encryptedChar;
        }
        else
        {
            outputFile << ch;
        }
    }

    outputFile.close();

    return key;
}

void decryption(int key)
{
    ifstream inputFile("encrypted_text.txt");
    if (!inputFile)
    {
        cerr << "Error opening the input file." << endl;
        return;
    }

    ofstream outputFile("decrypted_text.txt");
    if (!outputFile)
    {
        cerr << "Error opening the output file." << endl;
        inputFile.close();
        return;
    }

    char ch;
    while (inputFile.get(ch))
    {
        if ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z'))
        {
            char base = (ch >= 'a' and ch <= 'z') ? 'a' : 'A';
            char decryptedChar = (ch - base - key + 26) % 26 + base;
            outputFile << decryptedChar;
        }
        else
        {
            outputFile << ch;
        }
    }

    inputFile.close();
    outputFile.close();
}
