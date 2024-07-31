#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "crypto.h"

int main () {
	printf("Your text:\n");
	char text[1000];
	fgets(text, 1000, stdin);

	printf("What you want to do?\n1 - encrypt\n2 - decrypt\n");
	int b;
	scanf("%i", &b);


	if (b==1) {
		printf("How you want to encrypt?\n1 - reverse\n2 - vigener\n3 - bits\n4 - chaos\n");
		int a;
		scanf("%i", &a);

		if(a==1){
			char result[1000];
			reverse(text, result);
			printf("Result: %s\n", result);
		}
		if(a==2){
			printf("Your key:\n");
			char key[1000];
			int c=0;
			scanf("%i", &c);
			fgets(key, 1000, stdin);
			char result[1000];
			vigenere_encrypt(key, text, result);
			printf("Result: %s\n", result);
		}
		if(a==3){
			bool bytes[strlen(text)+1][8];
			encode_string(text, bytes);
			for(int j = 0; j < strlen(text)-1; j++){
				printf("%c: ", text[j]);
				for(int i = 0; i < 8; i++){
					printf("%d", bytes[j][i]);
				}
				printf("\n");
			}
		}
		if(a==4){
			unsigned char result[1000];
			bit_encrypt(text, result);
			for(int i=0; i < stringlen(result);i++) {
				printf("%02x ", result[i]);
			}
			printf("\n");
		}
	}

	if(b==2) {
		printf("What you want to decrypt?\n1 - reverse\n2 - vigener\n3 - chaos\n");
		int a;
		scanf("%i", &a);

		if(a==1){
			char result[1000];
			reverse(text, result);
			printf("Result: %s\n", result);
		}
		if(a==2){
			printf("Your key:\n");
			char key[1000];
			int c=0;
			scanf("%i", &c);
			fgets(key, 1000, stdin);
			char result[1000];
			vigenere_decrypt(key, text, result);
			printf("Result: %s\n", result);
		}
		if(a==3){
			unsigned char text1[1000];
			for(int i=0; i<strlen(text); i++) {
				text1[i]=text[i];
			}
			unsigned char result[1000];
			bit_decrypt(text1, result);
			printf("Result: %s\n", result);
		}
	}
    

	return 0;
}