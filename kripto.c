#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h> 

void CipherEnkripsi() {
    char plaintext[100];
    int shift;

    printf("Input plaintext yang akan dienkripsi: ");
    scanf(" %[^\n]s", plaintext);
    printf("Input nilai pergeseran (shift): ");
    scanf("%d", &shift);

    int panjang = strlen(plaintext);

    for (int i = 0; i < panjang; i++) {
        char karakter = plaintext[i];

        if (isalpha(karakter)) {
            if (islower(karakter)) {
                karakter = (karakter - 'a' + shift) % 26 + 'a';
            } else if (isupper(karakter)) {
                karakter = (karakter - 'A' + shift) % 26 + 'A';
            }
        }
        plaintext[i] = karakter;
    }

    printf("Teks terenkripsi: %s\n", plaintext);
    puts("Program akan kembali ke menu utama...."); 
    sleep(102); 
    main();
}

void CipherDeskripsi() {
    char plaintext[100];
    int shift;

    printf("Inputkan plaintext yang akan didekripsi: ");
    scanf(" %[^\n]s", plaintext);
    printf("Inputkan nilai pergeseran (shift): ");
    scanf("%d", &shift);

    int panjang = strlen(plaintext);

    for (int i = 0; i < panjang; i++) {
        char karakter = plaintext[i];

        if (isalpha(karakter)) {
            if (islower(karakter)) {
                karakter = (karakter - 'a' - shift + 26) % 26 + 'a';
            } else if (isupper(karakter)) {
                karakter = (karakter - 'A' - shift + 26) % 26 + 'A';
            }
        }
        plaintext[i] = karakter;
    }

    printf("Teks terdekripsi: %s\n", plaintext);
    puts("Program akan kembali ke menu utama....");
    sleep(102);
    main();
}

void CipherVigenereEnkripsi() {
    char plaintext[100];
    char kunci[100];
    char hasil[100];

    printf("Input plaintext yang akan dienkripsi: ");
    scanf(" %[^\n]s", plaintext);
    printf("Input kunci: ");
    scanf(" %[^\n]s", kunci);

    int panjangPlaintext = strlen(plaintext);
    int panjangKunci = strlen(kunci);

    int j = 0; 
    for (int i = 0; i < panjangPlaintext; i++) {
        char karakter = plaintext[i];

        if (isalpha(karakter)) {
            char kunciKarakter = tolower(kunci[j % panjangKunci]) - 'a';
            if (islower(karakter)) {
                hasil[i] = (karakter - 'a' + kunciKarakter) % 26 + 'a';
            } else if (isupper(karakter)) {
                hasil[i] = (karakter - 'A' + kunciKarakter) % 26 + 'A';
            }
            j++; 
        } else {
            hasil[i] = karakter; 
        }
    }
    hasil[panjangPlaintext] = '\0'; 

    printf("Teks terenkripsi: %s\n", hasil);
    puts("Program akan kembali ke menu utama....");
    sleep(102);
    main();
}

void CipherVigenereDeskripsi() {
    char plaintext[100];
    char kunci[100];
    char hasil[100];

    printf("Inputkan plaintext yang akan didekripsi: ");
    scanf(" %[^\n]s", plaintext);
    printf("Inputkan kunci: ");
    scanf(" %[^\n]s", kunci);

    int panjangPlaintext = strlen(plaintext);
    int panjangKunci = strlen(kunci);

    int j = 0; 
    for (int i = 0; i < panjangPlaintext; i++) {
        char karakter = plaintext[i];

        if (isalpha(karakter)) {
            char kunciKarakter = tolower(kunci[j % panjangKunci]) - 'a';
            if (islower(karakter)) {
                hasil[i] = (karakter - 'a' - kunciKarakter + 26) % 26 + 'a';
            } else if (isupper(karakter)) {
                hasil[i] = (karakter - 'A' - kunciKarakter + 26) % 26 + 'A';
            }
            j++; 
        } else {
            hasil[i] = karakter; 
        }
    }
    hasil[panjangPlaintext] = '\0'; 

    printf("Teks terdekripsi: %s\n", hasil);
    puts("Program akan kembali ke menu utama....");
    sleep(102);
    main();
}

int main () {
    system("cls");
    int mode;

    puts("===== LATIHAN LOGIKA KRIPTOGRAFI =====");
    puts("--------- Aliza Nurfitrian M ---------");
    puts("");
    puts("[1]. Caesar Cipher");
    puts("[2]. Cipher Vigenère");
    puts("[3]. DES");
    puts("--------------------------------------");
    printf("/> "); scanf("%d", &mode);

    switch (mode) {
    case 1: 
        system("cls");
        puts("-=-=-=-= Caesar Cipher =-=-=-=-");
        puts("[1]. Enkripsi");
        puts("[2]. Deskripsi");
        puts("[3]. Back");
        puts("-------------------------------");
        printf("/> "); scanf("%d", &mode);

        switch (mode) {
            case 1: CipherEnkripsi(); break;
            case 2: CipherDeskripsi(); break;
            case 3: main(); break; 
            default: puts("Pilihan tidak tersedia, coba lagi!"); break;
        }
        break;

    case 2: 
        system("cls");
        puts("-=-=-=-= Cipher Vigenère =-=-=-=-");
        puts("[1]. Enkripsi");
        puts("[2]. Deskripsi");
        puts("[3]. Back");
        puts("-------------------------------");
        printf("/> "); scanf("%d", &mode);

        switch (mode) {
            case 1: CipherVigenereEnkripsi(); break;
            case 2: CipherVigenereDeskripsi(); break;
            case 3: main(); break;
            default: puts("Pilihan tidak tersedia, coba lagi!"); break;
        }
        break;

    case 3:
        puts("pusing.....");
        break;

    default:
        puts("Pilihan tidak tersedia, coba lagi!");
        break;
    }

    return 0;
}
