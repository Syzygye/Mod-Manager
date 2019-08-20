void renamex(char titles[17][17], int k){
  #include "rename.h"
  //Print submenu.
  printf("\x1b[4;40HAdd x\n");
  printf("\x1b[5;40HAdd y\n");
  printf("\x1b[6;40HAdd a\n");
  printf("\x1b[7;40HAdd b\n");
  printf("\x1b[8;40HAdd z\n");
  printf("\x1b[9;40HClear\n");
  m=4;
  x=1;
  ejecutar=false;
    do{
      hidScanInput(); //Input of keys.
      u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
      if (kDown & KEY_A){ejecutar=true;}
      if (kDown & KEY_DUP && (x>1)){--x;}
      if (kDown & KEY_DDOWN && (x<6)){++x;}
      if (kDown & KEY_DUP && (m>4)){printf("\x1b[%i;39H ",m--);}
      if (kDown & KEY_DDOWN && (m<9)){printf("\x1b[%i;39H ",m++);}
      if (kDown & KEY_LSTICK_UP && (x>1)){--x;}
      if (kDown & KEY_LSTICK_DOWN && (x<6)){++x;}
      if (kDown & KEY_LSTICK_UP && (m>4)){printf("\x1b[%i;39H ",m--);}
      if (kDown & KEY_LSTICK_DOWN && (m<9)){printf("\x1b[%i;39H ",m++);}

      switch (x){
        case 1:printf("\x1b[4;39H+\n"); break;
        case 2:printf("\x1b[5;39H+\n"); break;
        case 3:printf("\x1b[6;39H+\n"); break;
        case 4:printf("\x1b[7;39H+\n"); break;
        case 5:printf("\x1b[8;39H+\n"); break;
        case 6:printf("\x1b[9;39H+\n"); break;
      }
      }while(ejecutar==false);

      switch (x){
        case 1:{        // Add "x" at the end of the name.
          char dire[14]="/sxos/titles/";
          char newname[30];
          char oldname[30];
          //Fill "oldname" with "dire" and with the name of the folder.
          for(i=0;i<13;i++)oldname[i]=dire[i];
          for(i=13;i<30;i++){
            oldname[i]=titles[k][y];
            ++y;
          }
          y=0;
          //Fill "newname" with "dire" and with the name of the folder.
          for(i=0;i<13;i++)newname[i]=dire[i];
            for(i=13;i<29;i++){
              newname[i]=titles[k][y];
              ++y;
            }
          newname[29]='x'; //Add "x" in the character 35.
          rename(oldname, newname); //Just rename.
          printf("\x1b[30;38HDone!\n");

//debug info, not necessary.
        /*  int b;
          for (int b = 0; b <50; b++) {
            printf("\x1b[30;38HDebug, no funciona y no se por que :)");
            printf("\x1b[31;38HOLDNAME-%s\n",oldname);
            printf("\x1b[32;38HNEWNAME-%s\n",newname);
            printf("\x1b[33;38HTITLES-%s\n",titles[1]);
            printf("\x1b[35;38HK-%i\n",k);
          } */


        break;}
        case 2:{
          char dire[14]="/sxos/titles/";
          char newname[30];
          char oldname[30];
          for(i=0;i<13;i++)oldname[i]=dire[i];
          for(i=13;i<30;i++){
            oldname[i]=titles[k][y];
            ++y;
          }
          y=0;
          for(i=0;i<13;i++)newname[i]=dire[i];
          for(i=13;i<29;i++){
            newname[i]=titles[k][y];
            ++y;
          }
          newname[29]='y';
          rename(oldname, newname);
          printf("\x1b[30;38HDone!\n");
        break;}
        case 3:{
          char dire[14]="/sxos/titles/";
          char newname[30];
          char oldname[30];
          for(i=0;i<13;i++)oldname[i]=dire[i];
          for(i=13;i<30;i++){
            oldname[i]=titles[k][y];
            ++y;
          }
          y=0;
          for(i=0;i<13;i++)newname[i]=dire[i];
          for(i=13;i<29;i++){
            newname[i]=titles[k][y];
            ++y;
          }
          newname[29]='a';
          rename(oldname, newname);
          printf("\x1b[30;38HDone!\n");

        break;}
        case 4:{
          char dire[14]="/sxos/titles/";
          char newname[30];
          char oldname[30];
          for(i=0;i<13;i++)oldname[i]=dire[i];
          for(i=13;i<30;i++){
            oldname[i]=titles[k][y];
            ++y;
          }
          y=0;
          for(i=0;i<13;i++)newname[i]=dire[i];
          for(i=13;i<29;i++){
            newname[i]=titles[k][y];
            ++y;
          }
          newname[29]='b';
          rename(oldname, newname);
          printf("\x1b[30;38HDone!\n");

        break;}
        case 5:{
          char dire[14]="/sxos/titles/";
          char newname[30];
          char oldname[30];
          for(i=0;i<13;i++)oldname[i]=dire[i];
          for(i=13;i<30;i++){
            oldname[i]=titles[k][y];
            ++y;
          }
          y=0;
          for(i=0;i<13;i++)newname[i]=dire[i];
          for(i=13;i<29;i++){
            newname[i]=titles[k][y];
            ++y;
          }
          newname[29]='z';
          rename(oldname, newname);
          printf("\x1b[30;38HDone!\n");

        break;}
        case 6:{
          char dire[14]="/sxos/titles/";
          char newname[30];
          char oldname[30];
          for(i=0;i<13;i++)oldname[i]=dire[i];
          for(i=13;i<30;i++){
            oldname[i]=titles[k][y];
            ++y;
          }
          y=0;
          for(i=0;i<13;i++)newname[i]=dire[i];
          for(i=13;i<29;i++){
            newname[i]=titles[k][y];
            ++y;
          }
          newname[29]='\0';
          rename(oldname, newname);
          printf("\x1b[30;38HDone!\n");

        break;}
      }
}
