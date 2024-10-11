#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Fungsi untuk enkripsi menggunakan Caesar Cipher
void encrypt(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        // Enkripsi huruf kecil
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        // Enkripsi huruf besar
        else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        // Jika karakter bukan huruf, biarkan apa adanya
        text[i] = ch;
    }
}

// Fungsi untuk dekripsi menggunakan Caesar Cipher
void decrypt(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        // Dekripsi huruf kecil
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - shift + 26) % 26 + 'a';
        }
        // Dekripsi huruf besar
        else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        // Jika karakter bukan huruf, biarkan apa adanya
        text[i] = ch;
    }
}

// Fungsi utama untuk menentukan mode dan menerima input pengguna
int main() {
    char text[1000];
    int shift, mode;
    
    // Pilih mode: 1 untuk enkripsi, 2 untuk dekripsi
    printf("Pilih mode: \n1. Enkripsi\n2. Dekripsi\nPilihan Anda: ");
    scanf("%d", &mode);
    getchar(); // Membuang newline setelah input mode
    
    // Input pesan
    printf("Masukkan pesan: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Hapus newline dari input
    
    // Input pergeseran
    printf("Masukkan pergeseran: ");
    scanf("%d", &shift);
    
    // Menentukan apakah enkripsi atau dekripsi
    if (mode == 1) {
        encrypt(text, shift);
        printf("Teks terenkripsi: %s\n", text);
    } else if (mode == 2) {
        decrypt(text, shift);
        printf("Teks terdekripsi: %s\n", text);
    } else {
        printf("Mode yang Anda pilih tidak valid.\n");
    }

    return 0;
}
