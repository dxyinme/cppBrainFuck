#include "state.h"
#include "util.h"

#include <cstring>
#include <string>
#include <iostream>


byte machine_[MACHINE_LEGTH];
char input_[MACHINE_LEGTH];

int main(int argc, char ** argv) {
  if (argc < 2) {
    puts("usage \n ./CppBrainFuck `xxxx`.bf");
    return 0;
  }
  int len = ReadInput(argv[1], input_);
  std::cout << argv[1] << "," << len << std::endl;
  std::cout << input_ << std::endl;
  memset(machine_, 0, sizeof(machine_));
  int ptr = 0;
  int input_ptr = 0;
  State st;
  while (input_ptr < len) {
    st.Do(&ptr, &input_ptr, machine_, input_);
  }
  return 0;
}