#ifndef CPP_BRAIN_FUCK_TYPES_H_
#define CPP_BRAIN_FUCK_TYPES_H_

#include <cstdint>
#include <unordered_map>

const int MACHINE_LEGTH = 3000000;
const int BUF_LENGTH = 1024;

using byte = int8_t;

enum class Operator {
  USELESS,
  INC,
  DEC,
  INC_PTR,
  DEC_PTR,
  PUTCHAR,
  GETCHAR,
  LOOP_BEGIN,
  LOOP_END,
};

static std::unordered_map<char, Operator> OpMp {
  {'>', Operator::INC_PTR},
  {'<', Operator::DEC_PTR},
  {'+', Operator::INC},
  {'-', Operator::DEC},
  {'.', Operator::PUTCHAR},
  {',', Operator::GETCHAR},
  {'[', Operator::LOOP_BEGIN},
  {']', Operator::LOOP_END},
};

static Operator GetOp(char c) {
  if (OpMp.find(c) != OpMp.end()) {
    return OpMp[c];
  } else {
    return Operator::USELESS; 
  }
}

#endif