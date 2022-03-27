#ifndef CPP_BRAIN_FUCK_STATE_H_
#define CPP_BRAIN_FUCK_STATE_H_

#include "types.h"
#include <stack>


struct State {
  std::stack<size_t> loop_;
  Operator operator_;
  void Do(int * ptr, int * input_ptr, byte * machine_, char * input_);

private:
  void Inc(int * ptr, int * input_ptr, byte * machine_);
  void Dec(int * ptr, int * input_ptr, byte * machine_);
  void IncPtr(int * ptr, int * input_ptr);
  void DecPtr(int * ptr, int * input_ptr);
  void PutChar(int * ptr, int * input_ptr, byte * machine_);
  void GetChar(int * ptr, int * input_ptr, byte * machine_);
  void LoopBegin(int * ptr, int * input_ptr, byte * machine_, char * input);
  void LoopEnd(int * ptr, int * input_ptr, byte * machine_, char * input);
};

#endif