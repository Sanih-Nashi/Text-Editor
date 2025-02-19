#include "antiutils.h"
#include "RawMode.h"
#include "KeyProcess.h"
#include "terminal.h"

#include <iostream>

const float version = 1.0;

int main() {
  RawMode::enableRawMode();
  initTerminal();
  
  utils::ClearScreen();
  std::cout <<"Welcome to anti version " << version <<"\n\n\r"<<std::flush;  
  while (true){
   KeyPress::ProcessKeyPress();
  }
}
