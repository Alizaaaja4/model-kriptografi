#include <stdio.h>
#include <string.h>

void caesarCipher(char text[], int shift) {
    int i;
    char ch;
    
    for(i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        
        // Periksa apakah huruf adalah huruf kecil
        if(ch >= 'a' && ch <= 'z') {
            ch = ch + shift;
            
            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            
            text[i] = ch;
        }
        // Periksa apakah huruf adalah huruf besar
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + shift;
            
            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            
            text[i] = ch;
        }
    }
}

int main() {
    char text[100];
    int shift;
    
    printf("Masukkan pesan: ");
    gets(text);
    printf("Masukkan pergeseran: ");
    scanf("%d", &shift);
    
    caesarCipher(text, shift);
    printf("Teks terenkripsi: %s\n", text);
    
    return 0;
}
