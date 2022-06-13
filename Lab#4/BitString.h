#ifndef RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_6_BITSTRING_H_
#define RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_6_BITSTRING_H_
#include "Array.h"
#include <iostream>

class BitString : public Array {
 protected:
  static const int max_size = 13;
 public:
  BitString();
  explicit BitString(const unsigned char *, unsigned int = 0);
  BitString &operator+(BitString &);
};

#endif //RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_6_BITSTRING_H_
