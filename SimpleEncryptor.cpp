#include "SimpleEncryptor.h"
#include "MyRNG.h"
#include <fstream>
#include <iostream>

/*
* A simple encryption program that uses a custom pseudorandom number generator to encrypt and decrypt messages.
*
* By Brendan Ross
* 2026-2-16
*/

std::string SimpleEncryptor::encryptMessage(const std::string& message) {
    std::string encryptedMessage = "";
    MyRNG rng;
    std::ofstream outFile("key.txt");

    for (char c : message) {
        int randomValue = rng.myRandom() % 256;
        encryptedMessage += static_cast<char>(static_cast<unsigned char>(((int)c + randomValue) % 256));
        outFile << randomValue << std::endl;
    }

    outFile.close();
    return encryptedMessage;
}

std::string SimpleEncryptor::decryptMessage(const std::string& messageToDecrypt, const std::string& keyFilename) {
    std::string decryptedMessage = "";
    std::ifstream file(keyFilename);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return "";
    }

    int index = 0;
    std::string line;
    while (std::getline(file, line)) {
        int keyInt = std::stoi(line);
        int charToDecrypt = (int)messageToDecrypt[index];
        decryptedMessage += static_cast<char>(static_cast<unsigned char>((charToDecrypt + 256 - (keyInt % 256)) % 256));
        index++;
    }

    file.close();
    return decryptedMessage;
}