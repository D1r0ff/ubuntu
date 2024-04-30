#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int stringlen(const unsigned char* text) {
    int i=0;
    while (text[i]!='\0') {
        i++;
    }
    return i;
}

void reverse(const char* text, char* result) {
    for(int i=0; i<strlen(text); i++) {
        result[i]=text[strlen(text)-1-i];
    }
}

void vigenere_encrypt(const char* key,const char* text, char* result) {
    int text_int=0, j=0, key_int=0;
    for(int i=0; i<strlen(text); i++) {
        text_int=(int)text[i];
        if(text_int>96 && text_int < 123) {
            text_int=text_int-32;
        }
        if (text_int < 65 || text_int > 90) {
            result[i]=(char)text_int;
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
        result[i]=(char)text_int;
    }
}
 
 
void vigenere_decrypt(const char* key, const char* text, char* result) {
    int text_int=0, j=0, key_int=0;
    for(int i=0; i<strlen(text); i++) {
        text_int=(int)text[i];
        if (text_int < 65 || text_int > 90) {
            result[i]=(char)text_int;
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
        result[i]=(char)text_int;
    }
}

// void encode_char(const char character, bool bits[8]) {
//     int bit_values[8] = {128, 64, 32, 16, 8, 4, 2 ,1};
//     int charValue = (int)character;
//     for(int i=0; i<8; i++) {
//         bits[i]=0;
//         if(bit_values[i]<=charValue) {
//             bits[i]=1;
//             charValue-=bit_values[i];
//         }
//     }
// }

// char decode_char(const bool bits[8]) {
//     int a=0;
//     int bit_values[8] = {128, 64, 32, 16, 8, 4, 2 ,1};
//     for(int i=0; i<8; i++) {
//         if(bits[i]==1) {
//             a+=bit_values[i];
//         }
//     }
//     return (char)a;
// }

void encode_string(const char string[], bool bytes[][8]) {
    int bit_values[8] = {128, 64, 32, 16, 8, 4, 2 ,1};
    for (int j=0; j<strlen(string); j++) {
        int charValue = (int)string[j];
        for(int i=0; i<8; i++) {
            bytes[j][i]=0;
            if(bit_values[i]<=charValue) {
                bytes[j][i]=1;
                charValue-=bit_values[i];
            }
        }
    }
}

// void decode_string(const int rows, bool bytes[][8], char string[]) {
//     int bit_values[8] = {128, 64, 32, 16, 8, 4, 2 ,1};
//     for(int j=0; j<rows-1;j++) {
//         int a=0;
//         for(int i=0; i<8; i++) {
//             if(bytes[j][i]==1) {
//                 a+=bit_values[i];
//             }
//         }
//         string[j]=(char)a;
//     }
// }

void bit_encrypt(const char* text, unsigned char* result) {
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
        result[j]=(char)a;
    }
}

void bit_decrypt(const unsigned char* text, unsigned char* result) {
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
        result[j]=(unsigned char)a;
        
    }

}
