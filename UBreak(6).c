#include <stdio.h>
#include <string.h>
void polyalphabeticCipher(char plaintext[], char key[]) {
    int i, j;
    int plaintextLength = strlen(plaintext);
    int keyLength = strlen(key);
for (i = 0; i < plaintextLength; i++) {
 char currentChar = plaintext[i];
        char keyChar = key[i % keyLength];
        char encryptedChar = 'A' + (currentChar - 'A' + keyChar - 'A') % 26;
        printf("%c", encryptedChar);
    }
    printf("\n");
}
int main() {
    char plaintext[100];
    char key[100];

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    printf("Enter the key: ");
    scanf("%s", key);
 printf("Encrypted Text: ");
    polyalphabeticCipher(plaintext, key);
return 0;
}
