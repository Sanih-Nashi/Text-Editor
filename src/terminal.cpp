#include "terminal.h"
#include "antiutils.h"

#include "sys/ioctl.h"
#include "unistd.h"

int Tl::GetTerminalSize(int* row, int* column){
  struct winsize window_size;

  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size) == -1 || window_size.ws_col == 0)
    return -1;
  else{
    *column = window_size.ws_col;
    *row = window_size.ws_row;
    return 0;
  }
}
void Tl::initTerminal() {
  if (GetTerminalSize(&ter.row, &ter.column) == -1) 
    utils::die("getWindowSize");
  ter.cx = 0;
  ter.cy = 0;
}
