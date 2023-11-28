#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>
void calculateMD5(char *input, unsigned char *output) {
    MD5_CTX context;
    MD5_Init(&context);
    MD5_Update(&context, input, strlen(input));
    MD5_Final(output, &context);
}
int main() {
    char input[100];
    unsigned char output[MD5_DIGEST_LENGTH];
    printf("Enter the data to hash: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 
    calculateMD5(input, output);
    printf("MD5 Hash: ");
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");
    return 0;
}
