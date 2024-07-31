#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "crypto.h"

int stringlen(const unsigned char* text) {
    int i=0;
    while (text[i]!='\0') {
        i++;
    }
    return i;
}

char* reverse(const char* text) {
    int lenght = strlen(text);
    char* result = malloc(lenght * sizeof(char));
    for(int i=0; i<strlen(text); i++) {
        *(result+i)=*(text+lenght-1-i);
    }
    return result;
}


char* vigenere_encrypt(const char* key, const char* text) {
    int text_int=0, j=0, key_int=0;
    int lenght = strlen(text);
    char* result = malloc(lenght * sizeof(char));
    for(int i=0; i<strlen(text); i++) {
        text_int=(int)text[i];
        if(text_int>96 && text_int < 123) {
            text_int=text_int-32;
        }
        if (text_int < 65 || text_int > 90) {
            *(result+i)=(char)text_int;
            continue;
        }
        key_int=(int)key[j];
        if(key_int > 96 && key_int < 123) {
            key_int=key_int-32;
        }
        j++;
        if(j==strlen(key)) {
            j=0;
        }
        text_int=text_int+key_int-65;
        if (text_int > 90) {
            text_int -= 26;
        }
        if(text[i]==' ') {
            text_int=32;
        }
        *(result+i)=(char)text_int;
    }
    return result;
}
 
 
char* vigenere_decrypt(const char* key, const char* text) {
    int text_int=0, j=0, key_int=0;
    int lenght = strlen(text);
    char* result = malloc(lenght * sizeof(char));
    for(int i=0; i<strlen(text); i++) {
        text_int=(int)text[i];
        if (text_int < 65 || text_int > 90) {
            *(result+i)=(char)text_int;
            continue;
        }
        key_int=(int)key[j];
        if(key_int>96 && key_int < 123) {
            key_int=key_int-32;
        }
        j++;
        if(j==strlen(key)) {
            j=0;
        }
        text_int=text_int-key_int+65;
        if(text[i]==' ') {
            text_int=32;
        }
        if (text_int < 65) {
            text_int += 26;
        }
        *(result+i)=(char)text_int;
    }
    return result;
}

unsigned char* bit_encrypt(const char* text) {
    int lenght = strlen(text);
    unsigned char* result = malloc(lenght * sizeof(char));
    int bit_values[8] = {128, 64, 32, 16, 8, 4, 2 ,1};
    int bits[8];
    for (int j=0; j<strlen(text); j++) {
        int a=0;
        int symbol = (int)text[j];
        for(int i=0; i<8; i++) {
            bits[i]=0;
            if(bit_values[i]<=symbol) {
                bits[i]=1;
                symbol-=bit_values[i];
            }
        }
        for(int i=0; i<3; i+=2) {
            bits[i]+=bits[i+1];
            bits[i+1]=bits[i]-bits[i+1];
            bits[i]=bits[i]-bits[i+1];
        }
        for(int i=0; i<4; i++) {
            if(bits[i]==bits[i+4]) {
                bits[i+4]=0;
            } else {
                bits[i+4]=1;
            }
        }
        for(int i=0; i<8; i++) {
            if(bits[i]==1) {
                a+=bit_values[i];
            }
        }
        *(result+j)=(char)a;
    }
    return result;
}

char* bit_decrypt(const unsigned char* text) {
    int lenght = stringlen(text);
    char* result = malloc(lenght * sizeof(char));
    int bit_values[8] = {128, 64, 32, 16, 8, 4, 2 ,1};
    int bits[8];
   
    for (int j=0; j<stringlen(text); j++) {
        int a=0;
        int symbol = (int)text[j];
        for(int i=0; i<8; i++) {
            bits[i]=0;
            if(bit_values[i]<=symbol) {
                bits[i]=1;
                symbol-=bit_values[i];
            }
        }
        for(int i=0; i<4; i++) {
            if(bits[i]==bits[i+4]) {
                bits[i+4]=0;
            } else {
                bits[i+4]=1;
            }
        }
        for(int i=0; i<3; i+=2) {
            bits[i]+=bits[i+1];
            bits[i+1]=bits[i]-bits[i+1];
            bits[i]=bits[i]-bits[i+1];
        }
        for(int i=0; i<8; i++) {
            if(bits[i]==1) {
                a+=bit_values[i];
            }
        }
        *(result+j)=(unsigned char)a;
        
    }
    return result;
}