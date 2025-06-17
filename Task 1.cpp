#include <iostream>
#include <string>
using namespace std;

// Function to encrypt the text
string encrypt(string text, int shift) {
    string result = "";

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += char((c - base + shift) % 26 + base);
        } else {
            result += c; // Leave non-letter characters as they are
        }
    }

    return result;
}

// Function to decrypt the text
string decrypt(string text, int shift) {
    return encrypt(text, -shift); // Reverse the shift for decryption
}

int main() {
    string message, choice;
    int shift;

    cout << "🔐 Caesar Cipher in C++ 🔐" << endl;
    cout << "Enter your message: ";
    getline(cin, message);

    cout << "Enter shift value: ";
    cin >> shift;
    cin.ignore(); // Clear input buffer

    cout << "Type 'e' to Encrypt or 'd' to Decrypt: ";
    getline(cin, choice);

    if (choice == "e" || choice == "E") {
        string encrypted = encrypt(message, shift);
        cout << "\n🔒 Encrypted Message: " << encrypted << endl;
    } else if (choice == "d" || choice == "D") {
        string decrypted = decrypt(message, shift);
        cout << "\n🔓 Decrypted Message: " << decrypted << endl;
    } else {
        cout << "❌ Invalid option!" << endl;
    }

    return 0;
}