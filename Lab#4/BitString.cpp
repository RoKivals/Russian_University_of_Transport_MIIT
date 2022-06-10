#include "BitString.h"

// max_size, который может принять array - 13. 100 бит = 12.5 байт,
// поэтому мы берём на 1 байт больше для максимума.

BitString::BitString() {
  size_ = 0;
  arr_ = new unsigned char[max_size]{0};
}

BitString::BitString(const unsigned char *arr, unsigned int size) {
  arr_ = new unsigned char[max_size]{0};
  if (arr == nullptr || size > max_size || size < 0) {
	size_ = 0;
  } else {
	size_ = size;
	for (unsigned int x = 0; x < size_; x++) {
	  this->arr_[x] = arr[x];
	}
  }
}

// Поскольку, в отличие от класса Money, в классе BitString у нас нет необходимости смещать один из массивов
// (нет разрядности чисел, что играло роль в денежном эквиваленте + невозможно переполнения байта в значении суммы.
// Сложение битовых строк будем производить по методу побитового логического ИЛИ.
BitString &BitString::operator+(BitString &right) {
  auto *res = new unsigned char[std::max(this->size_, right.size_)]{0};
  int itog_size = std::max(this->size_, right.size_);
  if (right.size_ > size_) {
	for (int x = itog_size - 1; x >= size_; x--) {
	  res[x] = right.arr_[x];
	}
	for (int x = 0; x < size_; x++) {
	  if (arr_[x] + right.arr_[x] - '0' == '2') {
		res[x] = '1';
	  } else
		res[x] = (arr_[x] + right.arr_[x]) - '0';
	}
  } else if (size_ > right.size_) {
	for (int x = itog_size - 1; x >= right.size_; x--) {
	  res[x] = right.arr_[x];
	}
	for (int x = 0; x < right.size_; x++) {
	  if (arr_[x] + right.arr_[x] - '0' == '2') {
		res[x] = '1';
	  } else
		res[x] = (arr_[x] + right.arr_[x]) - '0';
	}
  } else {
	for (int x = 0; x < itog_size; x++) {
	  if (arr_[x] + right.arr_[x] - '0' == '2') {
		res[x] = '1';
	  } else
		res[x] = (arr_[x] + right.arr_[x]) - '0';
	}
  }
  auto *bs = new BitString(res, itog_size);
  return *bs;
}

