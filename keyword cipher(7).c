#include<stdio.h>
char monocipher_encr(char);
char alpha[27][3] = { { 'a', 'C' }, { 'b', 'I' }, { 'c', 'P' }, { 'd', 'H' }, {
        'e', 'E' }, { 'f', 'R' }, { 'g', 'A' }, { 'h', 'B' }, { 'i', 'D' }, {
        'j', 'F' }, { 'k', 'G' }, { 'l', 'J' }, { 'm', 'K' }, { 'n', 'L' }, {
        'o', 'M' }, { 'p', 'N' }, { 'q', 'O' }, { 'r', 'Q' }, { 's', 'S' }, {
        't', 'T' }, { 'u', 'U' }, { 'v', 'V' }, { 'w', 'W' }, { 'x', 'X' }, {
        'y', 'Y' }, { 'z', 'Z' } };
char str[20];
int main() {
    char str[20], str2[20];
    int i;
    printf("\n Enter String..");
    gets(str);
    for (i = 0; str[i]; i++) {
        str2[i] = monocipher_encr(str[i]);
   }
    str2[i] = '\0';
    printf("\n Before Decryption..%s", str);
    printf("\n After Decryption..%s\n", str2);
}
char monocipher_encr(char a) {
    int i;
    for (i = 0; i < 27; i++) {
        if (a == alpha[i][0])
            break;
    }
    return alpha[i][1];
}
