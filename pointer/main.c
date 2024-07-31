#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "crypto.h"

int main(){
    char* reversed = reverse("Hello world!");
    printf("Reverse: %s\n", reversed);



    char* vigener = vigenere_encrypt("Key", "Hello world");
    printf("Vigenere_encrypt: %s\n", vigener);

    char* otvet = vigenere_decrypt("Key", vigener);
    printf("Vigenere_decrypt: %s\n", otvet);



    unsigned char* bits = bit_encrypt("Hello world!");
    // printf("Bit_encrypt: %s", bits);
    printf("Bit_encrypt: ");
    for(int i=0; i<stringlen(bits);i++){
        printf("%02x ", bits[i]);
    }
    printf("\n");

    char* decrypt = bit_decrypt(bits);
    printf("Bit_decrypt: %s\n", decrypt);

    

    return 0;
}