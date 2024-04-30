#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int stringlen(const unsigned char* result);

void reverse(const char* text, char* result);

void vigenere_encrypt(const char* key, const char* text, char* result);

void vigenere_decrypt(const char* key, const char* text, char* result);

void encode_char(const char character, bool bits[8]);

char decode_char(const bool bits[8]);

void encode_string(const char string[], bool bytes[][8]);

void decode_string(const int rows, bool bytes[][8], char string[]);

void bit_encrypt(const char* text, unsigned char* result);

void bit_decrypt(const unsigned char* text, unsigned char* result);