#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

// Encrypts a message using a Caesar cipher
string encrypt(string uncrypted_input, int n_letters)
{
    string result = uncrypted_input; // Copy the input message
    n_letters = n_letters % 26; // Normalize the shifting number
    for (char &c : result) // Go through each character in the message
    {
        if (isalpha(c)) // Check if the character is a letter
        {
            char base = islower(c) ? 'a' : 'A'; // Determine if the letter is lowercase or uppercase
            c = (c - base + n_letters) % 26 + base; // Shift the letter by n_letters positions
        }
    }
    return result; // Return the encrypted message
}

// Decrypts a message encrypted with a Caesar cipher
string decrypt(string encrypted_input, int n_letters)
{
    string result = encrypted_input; // Copy the encrypted message
    n_letters = n_letters % 26; // Normalize the shifting number
    for (char &c : result) // Go through each character in the message
    {
        if (isalpha(c)) // Check if the character is a letter
        {
            char base = islower(c) ? 'a' : 'A'; // Determine if the letter is lowercase or uppercase
            c = (c - base - n_letters + 26) % 26 + base; // Shift the letter back by n_letters positions
        }
    }
    return result; // Return the decrypted message
}

int main() {
    string user_message; // Stores the message input by the user
    string processed_message; // Stores the result after encryption or decryption
    string useroption; // Stores the user's choice (encrypt, decrypt, quit)
    int n_letters; // Stores the number of positions to shift

    bool running = true; // Keeps the program running until the user chooses to quit
    while (running) { // Loop to keep asking the user for input
        cout << "Enter an option (encrypt, decrypt, quit): ";
        getline(cin, useroption); // Get the user's choice

        if (useroption == "encrypt" || useroption == "decrypt") { // Check if the choice is valid
            cout << "Enter a shifting number (non-negative): ";
            cin >> n_letters; // Get the number of positions to shift

            // Make sure the shift number is non-negative
            while (n_letters < 0) {
                cout << "Invalid shifting number. Please enter a non-negative number: ";
                cin >> n_letters; // Ask the user to enter a valid number
            }
            cin.ignore(); // Remove any extra newline characters from the input buffer

            if (useroption == "encrypt") { // If the user wants to encrypt
                cout << "Please, enter a message: ";
                getline(cin, user_message); // Get the message to encrypt

                processed_message = encrypt(user_message, n_letters); // Encrypt the message
                cout << "Here is the encrypted message: " << processed_message << endl; // Show the encrypted message
            }
            else if (useroption == "decrypt") { // If the user wants to decrypt
                cout << "Please, enter an encrypted message: ";
                getline(cin, user_message); // Get the message to decrypt

                processed_message = decrypt(user_message, n_letters); // Decrypt the message
                cout << "Here is the decrypted message: " << processed_message << endl; // Show the decrypted message
            }
        }
        else if (useroption == "quit") { // If the user wants to quit
            running = false; // Stop the loop
        }
        else { // If the user entered an invalid option
            cout << "Please type one of these options:" << endl;
            cout << "option 1: encrypt" << endl; // List available options
            cout << "option 2: decrypt" << endl;
            cout << "option 3: quit" << endl;
        }
    }

    return 0; // End the program
}
