#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*int main()
{
    // zrozumiec strukture pliku --> liczby sa oddzielone od siebie spacja
//    // napisac handle do pobrania zawartosci pliku --> pobierzemy liczby do tablicy intow
//    // napisac funkcje ktora bedzie interowala po tablicy i podniesie do potegi jej elementy
//    // napisac handle ktory wypisze zawartosc tablicy do nowego pliku
//    // eot
//
   FILE *wskaznik;
    char kontent[150]; //przechowujemy tu ten text
    int koniec;
   wskaznik = fopen("/home/user/Clion_repository/files_potega_project/liczby.txt","r"); // "r" jak read plik jest w folderze z projektem
//
    if (wskaznik != NULL) {
        while (!feof(wskaznik)) // f end of file
       {
           kontent[0] = 0; //zeruje bufor zeby mi ostatnia linijka nie wypadala 2 razy
            fgets(kontent, 150, wskaznik);

           koniec= atoi(kontent);

           printf("wartość i = %d", koniec);

            printf("kontent %s", kontent);

        }
//
      // for(int i=0;i<10; i++ )
      // {
      //     printf("heja %c", kontent[i]);
      //  }
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
        fclose(wskaznik); // zamknij plik
    }
//
        return 0;
    }
//
//*int main()
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
   // int num=0;

    fp = fopen(FILEPATH, "r"); // read mode

    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    printf("The contents of file are :\n");
    int i = 0;
    int j = 0;
    char buff[500];
    char potegi[100];

    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == ',')
        {
            buff[i] = 0;
           // num[j++] = *buff - 48; // todo polacz elementy tablicy buff, oejmij 48, a nastepnie wrzuc to tablicy  num

            num[j] = atoi(buff);
            printf("num=.....\n");
            printf("%d\n", num[j]);
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

    printf("The wyniki of chary are :\n");

    int n = 0;

    for (int i = 0; i < 5; i++) {
        n += sprintf (&potegi[n], "%d\n", num[i]);
    }

    printf("The wyniki of guuuuu are :\n");

    int k=0;
    for(int k=0; k < 5; ++k)
    {

        printf("%c: %c\n", k, potegi[k]);

    }











    //strcpy(potegi, num);
    //printf("%s\n", potegi);

    printf("The wyniki of fiuty are :\n");
    for(int k=0; k < 5; ++k)
    {
        printf("%c: %c\n", k, potegi[k]);
       // potegi[i]= num[i];
    }
       // itoa(i,potegi,100);

    //printf("wynik dodawania %d", num[0] + 2);
    fclose(fp);


        //char int[] ;
        fp = fopen("/home/user/Clion_repository/files_potega_project/liczby.txt", "a"); // "w" jak write

        fprintf (fp, "%s", potegi); // zapisz nasz łańcuch w pliku

        fclose (fp); // zamknij plik







    return 0;
}

/*void rozbijNaCzesci(int suma)

{

    setki=(suma/100)*100;

    dziesiatki=((suma%100)/10)*10;

    jednostki=suma%10;



    return;

}
 */