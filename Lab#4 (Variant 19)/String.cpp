#include "String.h"

/*Данный класс String принимает максимум 255 байта, из которых один (первый) - кол-во элементов.
 * Переопределим индексацию данного класса в связи с тем, что индексное обращение к 0-му элементу не имеет никакого смысла по сути своей.
 * Первый байт будем задавать числом int, которое будет в случае необходимости преобразовываться в char (в массиве) и обратно в int,
 * если нам нужно будет узнать кол-во элементов в строке.*/

String::String() {
  size_ = 0;
  arr_ = new unsigned char[max_size]{0};
}

String::String(const unsigned char *arr, unsigned int size) {
  arr_ = new unsigned char[max_size]{0};
  if (arr == nullptr || size + 1 > max_size || size < 0) {
    size_ = 0;
  } else {
    size_ = size + 1;
    for (unsigned int x = 1; x < size; x++) {
      this->arr_[x] = arr[x - 1];
    }
    this->arr_[0] = char(size);
  }
}

// Поскольку, в отличие от класса Money, в классе String у нас нет необходимости смещать один из массивов
// (нет разрядности чисел, что играло роль в денежном эквиваленте + невозможно переполнения байта в значении суммы).
// Также, класс String - класс строки, следовательно, нелогично будет применять к данному классу метод
// арифметического сложения. Будем идти слева направо и просто считать сумму чаров по модулю от всех
// человекочитаемых знаков ASCII.
String &String::operator+(String &right) {
  auto *res = new unsigned char[std::max(this->size_, right.size_)]{0};
  int itog_size = std::max(this->size_, right.size_);
  // Если один из массивов больше, просто перенесём хвост путём присваивания
  if (right.size_ > size_) {
    for (int x = itog_size - 1; x >= size_; x--) {
      res[x] = right.arr_[x];
    }
    for (int x = 1; x < itog_size; x++) {
      if (arr_[x] + right.arr_[x] >= 126) {
        res[x] = 31 + (arr_[x] + right.arr_[x]) % (127 - 31 + 1);
      } else
        res[x] = (arr_[x] + right.arr_[x]);
    }
  } else if (size_ > right.size_) {
    for (int x = itog_size - 1; x >= right.size_; x--) {
      res[x] = right.arr_[x];
    }
    for (int x = 1; x < right.size_; x++) {
      if (arr_[x] + right.arr_[x] >= 126) {
        res[x] = 31 + (arr_[x] + right.arr_[x]) % (127 - 31 + 1);
      } else
        res[x] = (arr_[x] + right.arr_[x]);
    }
  } else {
    for (int x = 1; x < itog_size; x++) {
      if (arr_[x] + right.arr_[x] >= 126) {
        res[x] = 31 + (arr_[x] + right.arr_[x]) % (127 - 31 + 1);
      } else
        res[x] = (arr_[x] + right.arr_[x]);
    }
  }
  auto *bs = new String(res, itog_size);
  return *bs;
}

unsigned char &String::operator[](int index) {
  if (index >= 0 && index < size_) {
    return arr_[index + 1];
  } else {
    std::cout << "ERROR!";
  }
}

unsigned int String::get_size() {
  return int(arr_[0]);
}



