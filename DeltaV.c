#include <stdio.h>
#include <stdlib.h>

#include <unistd.h> //for clear, move to utils

void sayhello();
void readascii();
void clearScreen(); //for clear, move to utils
void setColour(char key); //move to utils

int main()
{
    clearScreen();
    readascii();
    sayhello();

    return 0;
}

void sayhello()
{
    setColour('r');
    printf("\n\nDelta-V Calculator for Low Earth Orbit, Medium Earth Orbit and\n");
    printf("Geosynchronous Equatorial Orbit Sattelites (LEO, MEO, GEO)\n");
    setColour('0');
    printf("--------------------------------------------------------------\n");
}

void readascii()
{
    FILE *fptr;
    char filePath[] = "ascii/sattelite", contents;

    fptr = fopen(filePath, "r");
    if (fptr == NULL)
    {
        printf("Cannot find or open file \n");
        return;
    }

    contents = fgetc(fptr);
    while (contents != EOF)
    {
        printf("%c", contents);
        contents = fgetc(fptr);
    }

    fclose(fptr);
}

void clearScreen() //move to utils
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}



void setColour(char key) //null for reset, //move to utils
{
    switch (key)
    {
        case 'r': //red
            printf("\033[1;31m");
            break;
        case 'g': //green
            break;
            printf("\033[0;32m");
        case 'b': //blue
            break;
            printf("\033[0;34m");
        case 'y': //yellow
            printf("\033[1;33m");
            break;
        case 'c': //cyan
            printf("\033[0;36m");
            break;
        default: //reset
            printf("\033[0m");
            break;
    }
}