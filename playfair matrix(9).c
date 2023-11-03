#include <stdio.h>
#include <string.h>

// Define Playfair matrix
char playfairMatrix[5][5] = {
    {'M', 'F', 'H', 'I', 'J'},
    {'K', 'U', 'N', 'O', 'P'},
    {'Q', 'Z', 'V', 'W', 'X'},
    {'Y', 'E', 'L', 'A', 'R'},
    {'G', 'D', 'S', 'T', 'B'}
};

// Function to find the coordinates of a character in the Playfair matrix
void findPosition(char ch, int *row, int *col) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (playfairMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt a pair of characters
void encryptPair(char a, char b) {
    int row1, col1, row2, col2;
    findPosition(a, &row1, &col1);
    findPosition(b, &row2, &col2);

    if (row1 == row2) {
        printf("%c%c", playfairMatrix[row1][(col1 + 1) % 5], playfairMatrix[row2][(col2 + 1) % 5]);
    } else if (col1 == col2) {
        printf("%c%c", playfairMatrix[(row1 + 1) % 5][col1], playfairMatrix[(row2 + 1) % 5][col2]);
    } else {
        printf("%c%c", playfairMatrix[row1][col2], playfairMatrix[row2][col1]);
    }
}

int main() {
    char message[1000];
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // Preprocess the message
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] - 'a' + 'A';  // Convert to uppercase
        }
        if (message[i] >= 'A' && message[i] <= 'Z') {
            if (message[i] == 'J') {
                message[i] = 'I';  // Replace 'J' with 'I'
            }
        } else {
            continue;  // Skip non-alphabetic characters
        }
    }

    // Handle double letters
    for (int i = 0; i < len; i += 2) {
        if (message[i] == message[i + 1]) {
            memmove(&message[i + 1], &message[i + 2], len - i - 2);
            len--;
        }
    }

    // Encrypt the message in pairs
    for (int i = 0; i < len; i += 2) {
        encryptPair(message[i], message[i + 1]);
    }

    return 0;
}
