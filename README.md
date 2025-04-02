# 🚀 Basic Blockchain Implementation in C++ 🚀

Welcome to our Basic Blockchain Implementation repository! This project is a simple implementation of a blockchain in C++. It includes functionalities such as adding and removing nodes, mining blocks, making transactions, and viewing the blockchain. 

## 📁 Repository Structure 📁

Here's a brief overview of the key files in this repository:

### 📄 RSA.cpp & RSA.h 📄

These files contain the implementation and declaration of the RSA encryption algorithm. The `go()` function in this class is used to encrypt a vector of integers using a given public key (e, n). 

```cpp
#include "RSA.h"
vector<int> message = {1, 2, 3, 4, 5};
int e = 3;
int n = 7;
RSA rsa;
vector<int> encryptedMessage = rsa.go(e, n, message);
```
In this example, the message {1, 2, 3, 4, 5} is encrypted using the public key (3, 7) using the RSA encryption algorithm.

### 📄 main.cpp 📄

This file serves as the entry point for the program. It initializes the Network and MainMenu objects and enters a loop where it continually prints the main menu and waits for user input.

### 📄 StringUtility.h 📄

This file defines a utility class, StringUtility, that provides several static methods for string manipulation and analysis. These methods include converting strings to numbers and vice versa, checking if all characters in a string are zeros or letters, converting a character to lowercase, and checking if a string is a substring of another string.

### 📄 sha256.cpp & sha256.h 📄

These files are used to implement the SHA-256 cryptographic hash function. It is used to convert input data into a unique hash value, which can be used for data integrity checks.

### 📄 Network.cpp & Network.h 📄

These files define the functionality of a network in a blockchain system. It manages nodes, transactions, and the mining process within the network.

### 📄 Chain.cpp & Chain.h 📄

These files are part of a blockchain implementation. They provide functionality for adding blocks to the chain, printing the details of a specific block, and printing the entire chain.

### 📄 Block.cpp & Block.h 📄

These files define the Block class for a blockchain implementation. It includes the constructor for creating a new block with a previous hash, index, difficulty level, and a vector of transactions.

### 📄 transaction.cpp & transaction.h 📄

These files define a Transaction class method, getString(), which is used to convert transaction details into a string format.

### 📄 random.cpp & random.h 📄

These files define a Random class that generates random numbers within a specified interval.

### 📄 Node.cpp & Node.h 📄

These files define the functionality of a Node in a blockchain network. It includes methods for copying a blockchain, adding transactions to a memory pool, mining a block, and verifying a block.

### 📄 somePublicPrivatekeys.txt 📄

This file stores a series of public and private keys. Each pair of keys is numbered for easy reference.

### 📄 BasicBlockchain.cbp 📄

This file is a Code::Blocks project file for a basic blockchain application. It contains the configuration and settings for building and running the project in the Code::Blocks IDE.

### 📄 MainMenu.cpp & MainMenu.h 📄

These files are responsible for handling the main menu of a blockchain-based network application. It provides options for adding and removing nodes, mining blocks, making transactions, and viewing the blockchain.
