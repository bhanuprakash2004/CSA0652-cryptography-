#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char *text, const char *key) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    int i;
    for (i = 0; i < textLen; i++) {
        if (isalpha(text[i])) {
            char upperText = toupper(text[i]);
            char upperKey = toupper(key[i % keyLen]);
            text[i] = 'A' + ((upperText - 'A' + upperKey - 'A') % 26);
        }
    }
}
int main() {
    char plaintext[1000];
    char keyword[100];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter the keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    keyword[strcspn(keyword, "\n")] = '\0';
    vigenereEncrypt(plaintext, keyword);
    printf("Encrypted text: %s\n", plaintext);
    return 0;
}

