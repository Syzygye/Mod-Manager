#include <switch.h>
#include <stdio.h>
#include <dirent.h>
#include <vector>
#include <string>
int pos;
#define CONSOLE_UGLY   CONSOLE_ESC(46;1m)
void logo(){
    printf(CONSOLE_BLUE);
    printf("\x1b[20;28H +-+-+-+-+-+-+-+-+-+-+-+");
    printf("\x1b[21;28H |                     |");
    printf("\x1b[22;28H |      MOD MANAGER    |");
    printf("\x1b[23;28H |                     |");
    printf("\x1b[24;28H +-+-+-+-+-+-+-+-+-+-+-+");
    printf(CONSOLE_RESET);
}
void _clear() {
    consoleClear();
    printf(CONSOLE_UGLY "\x1b[1;0H                                                                                ");
    printf(CONSOLE_UGLY "\x1b[2;0H________________________________________________________________________________");
    printf(CONSOLE_UGLY "\x1b[45;0H                                                                                ");
    printf(CONSOLE_GREEN "\x1b[1;33H-[Mod Manager]-");
    printf(CONSOLE_UGLY "\x1b[44;0H                                                                                ");
    printf(CONSOLE_GREEN "\x1b[45;71H@soymanker");
    printf(CONSOLE_GREEN "\x1b[45;1HBeta v.0.3");
    printf(CONSOLE_RESET);
}
void listprint(int placement, const char *value, char *usecColor=CONSOLE_WHITE, char *secColor=CONSOLE_GREEN) {
    if(placement == pos) {
        printf("%s" "\x1b[%d;0H" " %s", secColor, placement, value);
        printf(CONSOLE_RESET);
    }
    else printf("%s" "\x1b[%d;0H%s ", usecColor, placement, value);
}
inline bool d_exists (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}
bool isCFWStuff(std::string d_name) {
    if ((d_name == "010000000000000D") ||
        (d_name == "0100000000000032") ||
        (d_name == "0100000000000034") ||
        (d_name == "0100000000000036") ||
        (d_name == "0100000000000037"))
        return true;
    return false;
}
bool isDisabled(std::string d_name) {
    if(d_name.back()=='x') return true;
    return false;
}

void do_stuff(char *cfw) {
    DIR *dir;
    dirent *ent;
    std::vector<std::string> titles;
    dir = opendir(("/" + std::string(cfw) + "/titles").c_str());
    if(!dir) {
        printf("Failed to open /%s/titles", cfw);
        return;
    }
    while(ent=readdir(dir)) {
        if(!isCFWStuff(ent->d_name)) titles.push_back(ent->d_name);
    }
    closedir(dir);
    _clear();
    pos = 5;
    while(appletMainLoop()) {
        for(int i=0; i<titles.size(); i++) {
            if(isDisabled(titles[i])) listprint(i+5, titles[i].substr(0, titles[i].size()-1).c_str(), CONSOLE_RED, CONSOLE_YELLOW);
            else listprint(i+5, titles[i].c_str());
        }
        consoleUpdate(NULL);
        hidScanInput();
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        if((kDown & KEY_B) || (kDown & KEY_PLUS)) break;
        if((kDown & KEY_DOWN) && (pos<(titles.size()+4))) pos++;
        if((kDown & KEY_UP) && (pos>5)) pos--;
        if(kDown & KEY_A) {
            std::string oldname = titles[pos-5], newname;
            if(isDisabled(oldname)) newname = oldname.substr(0, oldname.size()-1);
            else {
                newname = oldname + "x";
            }
            int result = rename(
                ("/" + std::string(cfw) + "/titles/" + oldname).c_str(),
                ("/" + std::string(cfw) + "/titles/" + newname).c_str()
            );
            if(result == 0) titles[pos-5] = newname;
        }
    }
    pos = 5;
}

int main(int argc, char **argv) {
    consoleInit(NULL);
    pos=5;
    while(appletMainLoop()) {
        _clear();
        logo();
        
        if(d_exists("/atmosphere")) listprint(5, "Atmosphere");
        else listprint(5, "Atmosphere", CONSOLE_RED, CONSOLE_YELLOW);
        if(d_exists("SX OS")) listprint(7, "SX OS");
        else listprint(7, "SX OS", CONSOLE_RED, CONSOLE_YELLOW);
        if(d_exists("atmosphere")) listprint(9, "ReiNX");
        else listprint(9, "ReiNX", CONSOLE_RED, CONSOLE_YELLOW);
        listprint(11, "Exit");
        consoleUpdate(NULL);

        hidScanInput();
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
        if(kDown & KEY_A) {
            if(pos == 11) break;
            switch (pos) {
                case 5: do_stuff("atmosphere"); break;
                case 7: do_stuff("sxos"); break;
                case 9: do_stuff("reinx"); break;
            }
        };
        if((kDown & KEY_DOWN) && (pos<11)) pos=pos+2;
        if((kDown & KEY_UP) && (pos>5)) pos=pos-2;
        if((kDown & KEY_B) || (kDown & KEY_PLUS)) break;
    }
    consoleExit(NULL);
}