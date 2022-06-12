#ifndef RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_4_VARIANT_19_STRING_H_
#define RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_4_VARIANT_19_STRING_H_
#include "Array.h"
#include <iostream>

class String : public Array {
 public:
  String();
  explicit String(const unsigned char *, unsigned int = 0);
  String &operator+(String &);
  unsigned char &operator[](int) override;
  unsigned int get_size();
};

#endif //RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_4_VARIANT_19_STRING_H_
