#include <stdio.h>
#include <string.h>
void decryptRailFence(char *cipherText, int numRows) {
    int len = strlen(cipherText);
    char decryptedText[len];
    for (int i = 0; i < len; i++) {
        decryptedText[i] = ' ';
    }
    int index = 0;
    for (int i = 0; i < numRows; i++) {
        int j = i;
        while (j < len) {
            decryptedText[j] = cipherText[index++];
            j += 2 * (numRows - 1);
            if (i > 0 && i < numRows - 1 && j - 2 * i < len) {
                decryptedText[j - 2 * i] = cipherText[index++];
            }
        }
    }
    printf("Decrypted Text: %s\n", decryptedText);
}
int main() {
    char cipherText[100];
    int numRows;
    printf("Enter the ciphertext: ");
    fgets(cipherText, sizeof(cipherText), stdin);
    cipherText[strcspn(cipherText, "\n")] = '\0'; 
    printf("Enter the number of rows: ");
    scanf("%d", &numRows);
    decryptRailFence(cipherText, numRows);
    return 0;
}
