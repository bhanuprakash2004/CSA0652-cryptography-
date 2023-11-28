#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void vigenereDecrypt(char *ciphertext, char *key) {
    int ciphertextLen = strlen(ciphertext);
    int keyLen = strlen(key);
    char decrypted[ciphertextLen + 1];

    for (int i = 0, j = 0; i < ciphertextLen; i++, j++) {
        // Wrap around the key if it's shorter than the ciphertext
        if (j == keyLen) {
            j = 0;
        }

        if (isalpha(ciphertext[i])) {
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            decrypted[i] = ((ciphertext[i] - key[j] + 26) % 26) + base;
        } else {
            // If the character is not a letter, keep it unchanged
            decrypted[i] = ciphertext[i];
            j--;
        }
    }

    decrypted[ciphertextLen] = '\0';
    printf("Decrypted text: %s\n", decrypted);
}

int main() {
    char ciphertext[] = "EnterYourCiphertextHere"; // Replace this with your ciphertext
    char key[] = "KEY"; // Replace this with the decryption key

    // Convert the key to uppercase
    for (int i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }

    vigenereDecrypt(ciphertext, key);

    return 0;
}

