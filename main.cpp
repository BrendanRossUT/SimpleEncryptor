#include "SimpleEncryptor.h"
#include <iostream>

/*
 * The main class for the EulerMethods class.
 *
 * By Brendan Ross
 * 2026-2-16
 */

int main()
{
    SimpleEncryptor encryptor;
    std::string message = "hello world";
    std::string encryptedMessage = encryptor.encryptMessage(message);
    std::cout << encryptedMessage << std::endl;
    
    std::string decryptedMessage = encryptor.decryptMessage(encryptedMessage, "key.txt");
    std::cout << decryptedMessage << std::endl;

    return 0;
}