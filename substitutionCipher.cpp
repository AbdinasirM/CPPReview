#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> // For std::shuffle and std::iota
#include <random>    // For std::default_random_engine

using namespace std;

// Function to generate a random cipher mapping for the given alphabet
vector<char> generateRandomCipher(vector<char> alphabet)
{
    vector<int> indices(26);                 // Create a vector of indices from 0 to 25
    iota(indices.begin(), indices.end(), 0); // Fill indices with 0, 1, 2, ..., 25

    random_device rd;                             // Obtain a random number from hardware
    default_random_engine rng(rd());              // Seed the random number generator
    shuffle(indices.begin(), indices.end(), rng); // Randomly shuffle indices

    map<char, char> cipherMap; // Map to hold the cipher characters

    vector<char> mycipher(26); // Vector to hold the generated cipher
    for (size_t i = 0; i < indices.size(); ++i)
    {
        mycipher[i] = alphabet[indices[i]]; // Create cipher by mapping each index to a character
    }

    return mycipher; // Return the generated cipher
}

// Function to encrypt a message using the provided cipher
void encryption(const vector<char> &cipher, string message, vector<char> alphabet)
{
    string encryptedMessage;      // To store the encrypted message
    string cipherKey;             // To store the cipher key
    map<char, char> alpha_cipher; // Map to convert original characters to ciphered characters

    cout << "original alphabet letter -> Ciphered alphabet letter" << endl;
    for (int i = 0; i < alphabet.size(); i++)
    {
        cout << alphabet[i] << "                 ->               " << cipher[i] << endl; // Print cipher mapping
        cipherKey += cipher[i];                                                           // Build the cipher key string
        alpha_cipher[alphabet[i]] = cipher[i];                                            // Create the map for character substitution
    }

    for (char &c : message) // Iterate through each character in the message
    {
        if (isalpha(c)) // Check if the character is alphabetic
        {
            char upper_c = toupper(c);                            // Convert character to uppercase
            if (alpha_cipher.find(upper_c) != alpha_cipher.end()) // Check if the character is in the cipher map
            {
                encryptedMessage += alpha_cipher[upper_c]; // Substitute character using the cipher map
            }
        }
        else
        {
            encryptedMessage += c; // Keep non-alphabetic characters unchanged
        }
    }
    cout << "Cipher Key: " << cipherKey << endl;               // Print the cipher key
    cout << "Encrypted message: " << encryptedMessage << endl; // Print the encrypted message
}

// Function to decrypt a message using the provided cipher key
void decryption(string encryptedMessage, string cipheredAlphabet, vector<char> alphabet)
{
    string decryptedMessage;      // To store the decrypted message
    map<char, char> alpha_cipher; // Map to convert ciphered characters back to original characters

    vector<char> convertedstringToVector(cipheredAlphabet.begin(), cipheredAlphabet.end()); // Convert cipher key string to vector

    // Build the decryption map
    for (int i = 0; i < convertedstringToVector.size(); i++)
    {
        alpha_cipher[convertedstringToVector[i]] = alphabet[i];                                            // Map each ciphered character to the original character
        cout << convertedstringToVector[i] << "                 ->               " << alphabet[i] << endl; // Print decryption mapping
    }

    for (char &c : encryptedMessage) // Iterate through each character in the encrypted message
    {
        if (isalpha(c)) // Check if the character is alphabetic
        {
            char upperC = toupper(c);                            // Convert character to uppercase
            if (alpha_cipher.find(upperC) != alpha_cipher.end()) // Check if the character is in the decryption map
            {
                decryptedMessage += alpha_cipher[upperC]; // Substitute character using the decryption map
            }
        }
        else
        {
            decryptedMessage += c; // Keep non-alphabetic characters unchanged
        }
    }
    cout << "Decrypted message: " << decryptedMessage << endl; // Print the decrypted message
}

int main()
{
    vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string user_message; // To store the user's message
    string user_option;  // To store the user's option (encrypt, decrypt, or quit)
    string cipherkey;    // To store the cipher key

    bool running = true; // Control variable for the main loop
    while (running)
    {
        cout << "Please enter an option: encrypt, decrypt, quit: ";
        getline(cin, user_option); // Get user option

        if (user_option == "encrypt")
        {
            vector<char> cipher = generateRandomCipher(alphabet); // Generate a random cipher
            cout << "Please enter a message: ";
            getline(cin, user_message);                 // Get the message to encrypt
            encryption(cipher, user_message, alphabet); // Encrypt the message
        }
        else if (user_option == "decrypt")
        {
            cout << "Please enter the encrypted message: ";
            getline(cin, user_message); // Get the encrypted message

            cout << "Please enter the cipher key: ";
            getline(cin, cipherkey); // Get the cipher key

            decryption(user_message, cipherkey, alphabet); // Decrypt the message
        }
        else if (user_option == "quit")
        {
            running = false; // Exit the loop
        }
        else
        {
            // Handle invalid options
            cout << "Please type one of these options:" << endl;
            cout << "option 1: encrypt" << endl; // List available options
            cout << "option 2: decrypt" << endl;
            cout << "option 3: quit" << endl;
        }
    }

    return 0; // End of the program
}
