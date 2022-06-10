#ifndef RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_4_VARIANT_19_ARRAY_H_
#define RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_4_VARIANT_19_ARRAY_H_
#pragma once
#include <algorithm>
#include <iostream>
#include <stdexcept>


class Array {
 protected:
  static const int max_size = 255;
  unsigned int size_;
  unsigned char *arr_;
 public:
  Array();
  explicit Array(const unsigned char *, unsigned int = 0);
  virtual Array &operator+(Array &);
  virtual unsigned char &operator[](int);
  virtual unsigned int get_size();
};

#endif //RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_4_VARIANT_19_ARRAY_H_
