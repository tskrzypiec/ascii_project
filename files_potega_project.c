
#include <stdio.h>
#include <stdlib.h>

#define FILEPATH "/home/user/Clion_repository/files_potega_project/liczby.txt"
#define MAX 100

int main() {
    char ch;
    FILE *fp;

    fp = fopen(FILEPATH, "r"); // read mode

    if (fp == NULL) {
        perror("Błąd odczytu...\n");
        exit(EXIT_FAILURE);
    }

    printf("Czytam liczby z pliku i nadpisuje ich potegi...\n");
    int i = 0;
    int j = 0;
    int num[MAX]; // umieszczam tu wyłuskaną ze stringa liczbę
    int squared[MAX]; // wynik potęgowania
    char buff[50];   // bufor na liczby
    char score[50]; // tablica w wynikami potęgowania
    int numbers = 0; // ilość pobranych liczb


    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ',') {
            buff[i] = 0;
            num[j] = atoi(buff); // zamieniam na liczbę funkcją atoi
            squared[j] = num[j] * num[j]; // potęguje
            i = 0;
            num[j++];
            numbers++;

            continue;
        } else {
            buff[i++] = ch;
        }

    }

    int n = 0;

    for (int i = 0; i < numbers; i++) {
        n += sprintf(&score[n], "%d\n", squared[i]); //zamieniam na string
    }

    fclose(fp);

    fp = fopen("/home/user/Clion_repository/files_potega_project/liczby.txt", "a"); // nadpisz w pliku

    fprintf(fp, "%s", score); // zapisz łańcuch w pliku

    fclose(fp);

    return 0;
}

