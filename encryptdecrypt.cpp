#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<math.h>

// Function to find modular inverse of a under mod 26
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; // No modular inverse exists
}

// Function to check if two numbers are coprime
int isCoprime(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return (a == 1);
}

// Encryption function
void encryptMessage(char msg[], int a, int b, char encrypted[]) {
    printf("\n-----------------------------------------------\n");
    printf("TABLE: Encryption (E(x) = (a*x + b) mod 26)\n");
    printf("-----------------------------------------------\n");
    printf("Letter\tNumber(x)\tEncrypted(y)\tResult\n");
    printf("-----------------------------------------------\n");

    int i;
    for (i = 0; msg[i] != '\0'; i++) {
        char ch = toupper(msg[i]);
        if (ch >= 'A' && ch <= 'Z') {
            int x = ch - 'A';
            int enc = (a * x + b) % 26;
            encrypted[i] = enc + 'A';
            printf("%c\t\t%d\t\t%d\t\t%c\n", ch, x, enc, encrypted[i]);
        } else {
            encrypted[i] = ch;
        }
    }
    encrypted[i] = '\0';
    printf("-----------------------------------------------\n");
}

// Decryption function
void decryptMessage(char msg[], int a, int b, char decrypted[]) {
    int a_inv = modInverse(a, 26);
    if (a_inv == -1) {
        printf("\n? No modular inverse exists for 'a' = %d. Choose another value.\n", a);
        decrypted[0] = '\0';
        return;
    }

    printf("\n-----------------------------------------------\n");
    printf("TABLE: Decryption (D(y) = a?¹*(y - b) mod 26)\n");
    printf("-----------------------------------------------\n");
    printf("Letter\tNumber(y)\tDecrypted(x)\tResult\n");
    printf("-----------------------------------------------\n");

    int i;
    for (i = 0; msg[i] != '\0'; i++) {
        char ch = toupper(msg[i]);
        if (ch >= 'A' && ch <= 'Z') {
            int y = ch - 'A';
            int dec = (a_inv * (y - b + 26)) % 26;
            decrypted[i] = dec + 'A';
            printf("%c\t\t%d\t\t%d\t\t%c\n", ch, y, dec, decrypted[i]);
        } else {
            decrypted[i] = ch;
        }
    }
    decrypted[i] = '\0';
    printf("-----------------------------------------------\n");
}

int main() {
    char message[100], encrypted[100], decrypted[100];
    int a, b, choice;
    char cont;

    printf("=============================================================\n");
    printf(" ?? MESSAGE ENCRYPTION & DECRYPTION USING MODULAR ARITHMETIC\n");
    printf("=============================================================\n");

    do {
        printf("\nChoose an option:\n");
        printf("1. Encrypt Message\n");
        printf("2. Decrypt Message\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear input buffer

        if (choice == 1) {
            printf("\nEnter message (A-Z letters only): ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0'; // remove newline

            printf("Enter key 'a' (coprime with 26): ");
            scanf("%d", &a);
            printf("Enter key 'b': ");
            scanf("%d", &b);
            getchar();

            if (!isCoprime(a, 26)) {
                printf("\n? Invalid key! 'a' must be coprime with 26.\n");
                continue;
            }

            encryptMessage(message, a, b, encrypted);
            printf("\n?? Encrypted Message: %s\n", encrypted);
        } 
        else if (choice == 2) {
            printf("\nEnter encrypted message (A-Z letters only): ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';

            printf("Enter key 'a' (used during encryption): ");
            scanf("%d", &a);
            printf("Enter key 'b': ");
            scanf("%d", &b);
            getchar();

            if (!isCoprime(a, 26)) {
                printf("\n? Invalid key! 'a' must be coprime with 26.\n");
                continue;
            }

            decryptMessage(message, a, b, decrypted);
            if (strlen(decrypted) > 0)
                printf("\n?? Decrypted Message: %s\n", decrypted);
        } 
        else if (choice == 3) {
            printf("\n?? Exiting program. Goodbye!\n");
            break;
        } 
        else {
            printf("\n? Invalid choice! Please select 1, 2, or 3.\n");
        }

        printf("\n-------------------------------------------------------------\n");
        printf("FORMULAS USED:\n");
        printf("Encryption: E(x) = (a*x + b) mod 26\n");
        printf("Decryption: D(y) = a?¹*(y - b) mod 26\n");
        printf("-------------------------------------------------------------\n");
        printf("? NOTE: Choose 'a' coprime with 26 (1, 3, 5, 7, 11, 15, 17, 19, 21, 23, 25)\n");
        printf("=============================================================\n");

        printf("\nDo you want to perform another operation? (y/n): ");
        scanf(" %c", &cont);
        getchar(); // clear buffer

    } while (cont == 'y' || cont == 'Y');

    printf("\nProgram terminated successfully.\n");
    printf("=============================================================\n");
    
    return 0;
}
