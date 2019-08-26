void logo(){
  for (int x=0;x<1000; x++) {
    printf(CONSOLE_ESC(32;3m));
    printf("\x1b[20;28H +-+-+-+-+-+-+-+-+-+-+-+");
    printf("\x1b[21;28H |                     |");
    printf("\x1b[22;28H |      MOD MANAGER    |");
    printf("\x1b[23;28H |                     |");
    printf("\x1b[24;28H +-+-+-+-+-+-+-+-+-+-+-+");
    printf(CONSOLE_ESC(33;1m));
    printf("\x1b[20;28H +-+-+-+-+-+-+-+-+-+-+-+");
    printf("\x1b[21;28H |                     |");
    printf("\x1b[22;28H |      MOD MANAGER    |");
    printf("\x1b[23;28H |                     |");
    printf("\x1b[24;28H +-+-+-+-+-+-+-+-+-+-+-+");
    printf(CONSOLE_ESC(34;1m));
    printf("\x1b[20;28H +-+-+-+-+-+-+-+-+-+-+-+");
    printf("\x1b[21;28H |                     |");
    printf("\x1b[22;28H |      MOD MANAGER    |");
    printf("\x1b[23;28H |                     |");
    printf("\x1b[24;28H +-+-+-+-+-+-+-+-+-+-+-+");
    printf(CONSOLE_ESC(0m));
  }
}
