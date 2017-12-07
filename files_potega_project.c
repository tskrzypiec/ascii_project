//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//    // zrozumiec strukture pliku --> liczby sa oddzielone od siebie spacja
//    // napisac handle do pobrania zawartosci pliku --> pobierzemy liczby do tablicy intow
//    // napisac funkcje ktora bedzie interowala po tablicy i podniesie do potegi jej elementy
//    // napisac handle ktory wypisze zawartosc tablicy do nowego pliku
//    // eot
//
//    FILE *wskaznik;
//    char kontent[150]; //przechowujemy tu ten text
//    wskaznik = fopen("/home/user/Clion_repository/files_potega_project/liczby.txt","r"); // "r" jak read plik jest w folderze z projektem
//
//    if (wskaznik != NULL) {
//        while (!feof(wskaznik)) // f end of file
//        {
//            kontent[0] = 0; //zeruje bufor zeby mi ostatnia linijka nie wypadala 2 razy
//            fgets(kontent, 150, wskaznik);
//
//            printf("%s", kontent);
//
//        }
//
//        for(int i=0;i<10; i++ )
//        {
//           printf("%c", kontent[i]);
//        }
//
//
//
//        fclose(wskaznik); //zamykamy pli
//
//
//        char tekst[] = "Hej witaj!";
//        wskaznik = fopen("ZapisanyPlik.txt", "w"); // "w" jak write
//
//        fprintf(wskaznik, "%s", tekst); // zapisz nasz łańcuch w pliku
//
//        fclose(wskaznik); // zamknij plik
//    }
//
//        return 0;
//    }
//
///*int main()
//{
//    int i= 0;
//    int nr[32];
//
//    FILE *plik= fopen("/home/user/Clion_repository/files_potega_project/liczby.txt", "r");    // otworzenie pliku do odczytu
//    if(!plik)
//    {
//        puts("Brak pliku numery.txt");
//        return EXIT_FAILURE;
//    }
//    while (true)
//    {
//        fscanf(plik, "%d\n", &nr[i]);
//        if(feof(plik) != 0)
//            break;
//        printf("%d %d\n", i+1, nr[i]);
//        ++i;
//    }
//    fclose(plik);
//    return 0;
//}
//*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h> // For exit() function
#include <memory.h>

#define FILEPATH "/home/user/Clion_repository/files_potega_project/liczby.txt"
#define MAX 6

int main() {
    char ch;
    FILE *fp;
    int num[MAX];

    fp = fopen(FILEPATH, "r"); // read mode

    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    printf("The contents of file are :\n");
    int i = 0;
    int j = 0;
    char buff[5];
    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == ',')
        {
            buff[i] = 0;
            //num[j++] = *buff - 48; // todo polacz elementy tablicy buff, oejmij 48, a nastepnie wrzuc to tablicy  num
            num[j] = atoi(buff);
           // num[j++] = atoi(buff); //- 48; // todo polacz elementy tablicy buff, oejmij 48, a nastepnie wrzuc to tablicy  num
            printf("num=.....\n");
            printf("%d\n", num[j]);
        //printf("%d\n", num[0]);
            i = 0;
            num[j++];

            continue;
        }
        else
        {
            buff[i++] = ch;
        }
        printf("%c\n", ch);
    }

    // read num arr
    for(int i=0; i < 5; ++i)
    {
        printf("%d: %d\n", i, num[i]);
    }

    fclose(fp);
    return 0;
}