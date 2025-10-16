Affine Cipher Encryption & Decryption ToolThis is a simple command-line tool written in C++ that implements the Affine cipher for encrypting and decrypting alphabetic messages. It serves as a practical demonstration of modular arithmetic in cryptography.The program provides an interactive interface where a user can input a message and a pair of integer keys (a and b) to perform encryption or decryption. It also includes detailed, step-by-step tables to illustrate how each character is transformed.✨ FeaturesInteractive CLI: A user-friendly menu to choose between encryption, decryption, or exiting the program.Affine Cipher Implementation: Encrypts and decrypts messages using the mathematical formulas of the Affine cipher.Key Validation: Automatically checks if the key a is coprime with 26, a necessary condition for the cipher to be decryptable.Detailed Process Visualization: For both encryption and decryption, the program generates a table showing the transformation for each character, from letter to number and back.Robust Input Handling: Ignores non-alphabetic characters and processes the message regardless of its initial case (by converting all letters to uppercase).⚙️ How It WorksThe Affine cipher is a type of monoalphabetic substitution cipher. Each letter in the alphabet is mapped to its numeric equivalent (A=0, B=1, ..., Z=25).EncryptionThe encryption function for a single letter x is:$$E(x) = (ax + b) \pmod{26}$$Where:x is the integer representation of the plaintext character.a and b are the secret keys.a must be coprime with 26 (i.e., $gcd(a, 26) = 1$).DecryptionThe decryption function for a single letter y is:$$D(y) = a^{-1}(y - b) \pmod{26}$$Where:y is the integer representation of the ciphertext character.$a^{-1}$ is the modular multiplicative inverse of a modulo 26. This inverse exists only if a is coprime with 26.🚀 How to UsePrerequisitesYou need a C++ compiler, such as g++, installed on your system.CompilationClone the repository or save the encryptdecrypt.cpp file to your local machine.Open your terminal or command prompt and navigate to the directory containing the file.Compile the code using the following command:Bashg++ encryptdecrypt.cpp -o affine_cipher
ExecutionRun the compiled program:Bash./affine_cipher
Follow the on-screen prompts to encrypt or decrypt your messages.Example Session=============================================================
 ?? MESSAGE ENCRYPTION & DECRYPTION USING MODULAR ARITHMETIC
=============================================================

Choose an option:
1. Encrypt Message
2. Decrypt Message
3. Exit
Enter choice: 1

Enter message (A-Z letters only): HELLO WORLD
Enter key 'a' (coprime with 26): 5
Enter key 'b': 8

-----------------------------------------------
TABLE: Encryption (E(x) = (a*x + b) mod 26)
-----------------------------------------------
Letter	Number(x)	Encrypted(y)	Result
-----------------------------------------------
H		7		17		R
E		4		2		C
L		11		11		L
L		11		11		L
O		14		20		U
W		22		10		K
O		14		20		U
R		17		15		P
L		11		11		L
D		3		23		X
-----------------------------------------------

?? Encrypted Message: RCLLU KUPLX

Do you want to perform another operation? (y/n): n

Program terminated successfully.
=============================================================
