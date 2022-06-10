#ifndef RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_4_VARIANT_19_MONEY_H_
#define RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_4_VARIANT_19_MONEY_H_

#include "Array.h"
#include <algorithm>
#include <iostream>

class Money : public Array {
 protected:
  static const int max_size = 7;
 public:
  Money();
  explicit Money(const unsigned char *, unsigned int = 0);
  Money &operator+(Money &);
};

#endif //RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_4_VARIANT_19_MONEY_H_
