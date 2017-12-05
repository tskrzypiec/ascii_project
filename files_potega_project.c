#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *wskaznik;
    char kontent[150]; //przechowujemy tu ten text
    wskaznik = fopen("/home/user/Clion_repository/files_potega_project/liczby.txt","r"); // "r" jak read plik jest w folderze z projektem

    if (wskaznik != NULL) {
        while (!feof(wskaznik)) // f end of file
        {
            kontent[0] = 0; //zeruje bufor zeby mi ostatnia linijka nie wypadala 2 razy
            fgets(kontent, 150, wskaznik);

            printf("%s", kontent);

        }

        fclose(wskaznik); //zamykamy pli


        char tekst[] = "Hej witaj!";
        wskaznik = fopen("ZapisanyPlik.txt", "w"); // "w" jak write

        fprintf(wskaznik, "%s", tekst); // zapisz nasz łańcuch w pliku

        fclose(wskaznik); // zamknij plik
    }

        return 0;
    }