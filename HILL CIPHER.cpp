#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 3
void getKeyMatrix(char key[MAX][MAX], int keySize) {
    printf("Enter the key matrix (%dx%d):\n", keySize, keySize);
    for (int i = 0; i < keySize; i++) {
        for (int j = 0; j < keySize; j++) {
            scanf("%d", &key[i][j]);
        }
    }
}
void encryptHillCipher(char *plaintext, char key[MAX][MAX], int keySize) {
    int len = strlen(plaintext);
    int input[MAX];
    int output[MAX];
    int padding = keySize - len % keySize;
    if (padding != keySize) {
        for (int i = 0; i < padding; i++) {
            plaintext[len + i] = 'X';
        }
        len += padding;
    }
    printf("Encrypted Text: ");
    for (int i = 0; i < len; i += keySize) {
        for (int j = 0; j < keySize; j++) {
            input[j] = plaintext[i + j] - 'A';
        }
        for (int j = 0; j < keySize; j++) {
            output[j] = 0;
            for (int k = 0; k < keySize; k++) {
                output[j] += key[j][k] * input[k];
            }
            output[j] %= 26;
            printf("%c", output[j] + 'A');
        }
    }
    printf("\n");
}
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}
void decryptHillCipher(char *ciphertext, char key[MAX][MAX], int keySize) {
    int len = strlen(ciphertext);
    int input[MAX];
    int output[MAX];

    int keyInverse[MAX][MAX];
    int det = 0;
    for (int i = 0; i < keySize; i++) {
        for (int j = 0; j < keySize; j++) {
            det += key[i][j] * key[(i + 1) % keySize][(j + 1) % keySize] * key[(i + 2) % keySize][(j + 2) % keySize];
        }
    }

    det = det % 26;
    for (int i = 0; i < keySize; i++) {
        for (int j = 0; j < keySize; j++) {
            keyInverse[i][j] = key[(j + 1) % keySize][(i + 1) % keySize] * key[(j + 2) % keySize][(i + 2) % keySize] -
                               key[(j + 2) % keySize][(i + 1) % keySize] * key[(j + 1) % keySize][(i + 2) % keySize];
            keyInverse[i][j] = keyInverse[i][j] % 26;
            if (keyInverse[i][j] < 0)
                keyInverse[i][j] += 26;
        }
    }
    int detInverse = modInverse(det, 26);
    for (int i = 0; i < keySize; i++) {
        for (int j = 0; j < keySize; j++) {
            keyInverse[i][j] = (keyInverse[i][j] * detInverse) % 26;
        }
    }
    printf("Decrypted Text: ");
    for (int i = 0; i < len; i += keySize) {
        for (int j = 0; j < keySize; j++) {
            input[j] = ciphertext[i + j] - 'A';
        }

        for (int j = 0; j < keySize; j++) {
            output[j] = 0;
            for (int k = 0; k < keySize; k++) {
                output[j] += keyInverse[j][k] * input[k];
            }
            output[j] %= 26;
            printf("%c", output[j] + 'A');
        }
    }
    printf("\n");
}
int main() {
    char plaintext[100], ciphertext[100];
    char key[MAX][MAX];
    int keySize;
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
    printf("Enter the key size (2 or 3): ");
    scanf("%d", &keySize);

    if (keySize < 2 || keySize > 3) {
        printf("Invalid key size. Exiting...\n");
        return 1;
    }
    getKeyMatrix(key, keySize);
    encryptHillCipher(plaintext, key, keySize);
    printf("\nEnter the ciphertext: ");
    scanf("%s", ciphertext);
    decryptHillCipher(ciphertext, key, keySize);
    return 0;
}
