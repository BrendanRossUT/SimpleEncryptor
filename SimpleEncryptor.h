#ifndef SIMPLEENCRYPTOR_H
#define SIMPLEENCRYPTOR_H

#include <string>

/*
* A simple encryption program that uses a custom pseudorandom number generator to encrypt and decrypt messages.
*
* By Brendan Ross
* 2026-2-16
*/

class SimpleEncryptor
{
public:

    /**
    * Encrypts a message using the custom pseudorandom number generator. The encrypted message is written to a .txt file, titled "key.txt".
    * This file contains the key used to encrypt the message, which is necessary for decryption. 
    * 
    * WARNING: This file will be overwritten each time the encryptMessage function is called.
    * 
    * @param message The message to be encrypted.
    * @return The encrypted message as a string.
    */
    std::string encryptMessage(const std::string& message);

    /**
    * Decrypts a message with the provided .txt file. The decrypted message is returned as a string.
    * @param messageToDecrypt The message to be decrypted.
    * @param keyFilename The filename of the .txt file. Used as the key to decrypt the message.
    * @return The decrypted message as a string. Returns an empty string if the file cannot be opened.
    */
    std::string decryptMessage(const std::string& messageToDecrypt, const std::string& keyFilename);
};

#endif