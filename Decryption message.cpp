#include <stdio.h>
#include <string.h>

int main() {
    // Declaring variables
    int i, key;
    char s[1000], c;

    // Taking ciphertext and key input
    printf("Enter encrypted text:\n");
    fgets(s, sizeof(s), stdin);
    printf("Enter key:\n");
    scanf("%d", &key);

    int n = strlen(s);

    // Decrypting each character according to the given key
    for (i = 0; i < n; i++) {
        c = s[i];
        if (c >= 'a' && c <= 'z') {
            c = c - key;
            if (c < 'a') {
                c = c + 'z' - 'a' + 1;
            }
            s[i] = c;
        } else if (c >= 'A' && c <= 'Z') {
            c = c - key;
            if (c < 'A') {
                c = c + 'Z' - 'A' + 1;
            }
            s[i] = c;
        }
    }

    // Output the original message
    printf("Decrypted message: %s\n", s);

    return 0;
}