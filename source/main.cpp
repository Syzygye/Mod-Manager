#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <switch.h>
#include "tcross.cpp"
#include "logo.cpp"

int main(int argc, char **argv)
{
    gfxInitDefault();
    consoleInit(NULL);
#include "main.h"
logo();
//bucle
        do{
            consoleInit(NULL);
            #include "header.cpp"
            ejecutar1=false;
            k=1;
            m=3;
            printf("\x1b[5;0HFolders\n");
            printf("\x1b[7;0HDelete\n");
            printf("\x1b[9;0Hop3\n");
            printf("\x1b[11;0HExit\n");


            do{

              hidScanInput();
              u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
              if (kDown & KEY_A){ejecutar1=true;}
              if (kDown & KEY_DUP && (k>1)){--k;}
              if (kDown & KEY_DDOWN && (k<t)){++k;}
              if (kDown & KEY_DUP && (m>3)){printf("\x1b[%i;0H",m--);}
              if (kDown & KEY_DDOWN && (m<t+2)){printf("\x1b[%i;0H",m++);}
              if (kDown & KEY_LSTICK_UP && (k>1)){--k;}
              if (kDown & KEY_LSTICK_DOWN && (k<t)){++k;}
              if (kDown & KEY_LSTICK_UP && (m>3)){printf("\x1b[%i;0H",m--);}
              if (kDown & KEY_LSTICK_DOWN && (m<t+2)){printf("\x1b[%i;0H",m++);}

              switch (k){
                case 1:{
                  printf("\x1b[7;0HDelete\n");
                  printf("\x1b[9;0Hop3\n");
                  printf("\x1b[11;0HExit\n");
                  printf(CONSOLE_ESC(32;1m)"\x1b[5;0HFolders\n");
                  printf(CONSOLE_ESC(0m));
                  break;}
                case 2:{
                  printf("\x1b[5;0HFolders\n");
                  printf("\x1b[9;0Hop3\n");
                  printf("\x1b[11;0HExit\n");
                  printf(CONSOLE_ESC(32;1m)"\x1b[7;0HDelete\n");
                  printf(CONSOLE_ESC(0m));
                break;}
                case 3:{
                  printf("\x1b[5;0HFolders\n");
                  printf("\x1b[7;0HDelete\n");
                  printf("\x1b[11;0HExit\n");
                  printf(CONSOLE_ESC(32;1m)"\x1b[9;0Hop3\n");
                  printf(CONSOLE_ESC(0m));
                break;}
                case 4:{
                  printf("\x1b[5;0HFolders\n");
                  printf("\x1b[7;0HDelete\n");
                  printf("\x1b[9;0Hop3\n");
                  printf(CONSOLE_ESC(32;1m)"\x1b[11;0HExit\n");
                  printf(CONSOLE_ESC(0m));
                  break;}
                //case 5:printf("\x1b[7;0H+\n"); break;
                //case 6:printf("\x1b[8;0H+\n"); break;
                //case 7:printf("\x1b[9;0H+\n"); break;
                //case 8:printf("\x1b[10;0H+\n"); break;
              }

            }while(ejecutar1==false);

        switch (k) {

          case 1:{
            tcross();
          break;}
          case 2:{

          break;}
          case 3:{

          break;}
          case 4:{
            exit=true;
          break;}
        }

        gfxFlushBuffers();
        gfxSwapBuffers();
        gfxWaitForVsync();
    }while(exit!=true);
    gfxFlushBuffers();
    gfxSwapBuffers();
    gfxWaitForVsync();
    gfxExit();
}
