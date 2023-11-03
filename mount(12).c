#include <stdio.h>
#include <string.h>
#include <ctype.h>


void hillCipherEncrypt(char *plainText, char *keyMatrix) {
    int i, j, k, len = strlen(plainText);
    int key[2][2], plain[2], cipher[2];

    
    for (i = 0, k = 0; i < 2; i++) {
        for (j = 0; j < 2; j++, k++) {
            key[i][j] = keyMatrix[k] - 'A';
        }
    }

    
    for (i = 0; i < len; i += 2) {
        
        plain[0] = plainText[i] - 'A';
        plain[1] = plainText[i + 1] - 'A';

        
        cipher[0] = key[0][0] * plain[0] + key[0][1] * plain[1];
        cipher[1] = key[1][0] * plain[0] + key[1][1] * plain[1];

        
        cipher[0] %= 26;
        cipher[1] %= 26;

        
        printf("%c%c", cipher[0] + 'A', cipher[1] + 'A');
    }
}

int main() {
    char plainText[100], keyMatrix[5];

    
    printf("Enter plaintext (uppercase alphabets only): ");
    scanf("%s", plainText);
    printf("Enter 2x2 key matrix (uppercase alphabets only): ");
    scanf("%s", keyMatrix);

    
    if (strlen(plainText) % 2 != 0 || strlen(keyMatrix) != 4) {
        printf("Plaintext and key matrix lengths must be even and 4 characters, respectively.\n");
        return 1;
    }

    
    for (int i = 0; i < strlen(plainText); i++) {
        if (!isupper(plainText[i])) {
            printf("Invalid characters in plaintext. Use uppercase alphabets only.\n");
            return 1;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (!isupper(keyMatrix[i])) {
            printf("Invalid characters in the key matrix. Use uppercase alphabets only.\n");
            return 1;
        }
    }

    
    printf("Ciphertext: ");
    hillCipherEncrypt(plainText, keyMatrix);

    printf("\n");

    return 0;
}
