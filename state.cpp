#include "state.h"
#include <iostream>
#include <cstdio>

void State::Do(int * ptr, int * input_ptr, byte * machine_, char * input_) {
  operator_ = GetOp(input_[*input_ptr]);
  if (operator_ != Operator::USELESS) {
    // printf("%d, %d, (%c)\n", *ptr, *input_ptr, input_[*input_ptr]);
  }
  switch (operator_)
  {
  case Operator::INC:
    Inc(ptr, input_ptr, machine_);
    break;
  case Operator::DEC:
    Dec(ptr, input_ptr, machine_);
    break;
  case Operator::INC_PTR:
    IncPtr(ptr, input_ptr);
    break;
  case Operator::DEC_PTR:
    DecPtr(ptr, input_ptr);
    break;
  case Operator::GETCHAR:
    GetChar(ptr, input_ptr, machine_);
    break;
  case Operator::PUTCHAR:
    PutChar(ptr, input_ptr, machine_);
    break;
  case Operator::LOOP_BEGIN:
    LoopBegin(ptr, input_ptr, machine_, input_);
    break;
  case Operator::LOOP_END:
    LoopEnd(ptr, input_ptr, machine_, input_);
    break;
  default:
    ++(*input_ptr);
    break;
  }
}

void State::Inc(int * ptr, int * input_ptr, byte * machine_) {
  machine_[*ptr]++;
  (*input_ptr)++;
}

void State::Dec(int * ptr, int * input_ptr, byte * machine_) {
  machine_[*ptr]--;
  (*input_ptr)++;
}

void State::IncPtr(int * ptr, int * input_ptr) {
  (*ptr)++;
  (*input_ptr)++;
}

void State::DecPtr(int * ptr, int * input_ptr) {
  (*ptr)--;
  (*input_ptr)++;
}

void State::GetChar(int * ptr, int * input_ptr, byte * machine_) {
  machine_[*ptr] = getchar();
  (*input_ptr)++;
}

void State::PutChar(int * ptr, int * input_ptr, byte * machine_) {
  putchar(machine_[*ptr]);
  (*input_ptr)++;
}

void State::LoopBegin(int * ptr, int * input_ptr, byte * machine_, char * input) {
  loop_.push(*input_ptr);
  (*input_ptr)++;
  if (!machine_[*ptr]) {
    int cnt_begin = 1;
    while (cnt_begin > 0) {
      if (GetOp(input[*input_ptr]) == Operator::LOOP_BEGIN) {
        cnt_begin++;
      } else if (GetOp(input[*input_ptr]) == Operator::LOOP_END) {
        cnt_begin--;
      }
      (*input_ptr)++;
    }
    loop_.pop();
  }
}

void State::LoopEnd(int * ptr, int * input_ptr, byte * machine_, char * input) {
  (*input_ptr) = loop_.top();
  loop_.pop();
}