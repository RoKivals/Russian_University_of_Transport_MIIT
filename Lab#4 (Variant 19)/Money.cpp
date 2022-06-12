#include "Money.h"

// Допустим, что мы работаем с массивом из класса array
// Рубли у нас представлены типом long (4 байта - 4 символа unsigned char)
// Копейки - два символа => будем работать с массивом чаров так,
// что первые 4 элемента - рубли, а следующие 2 - копейки.
// Также будем считать, что копейки обязательно есть в массиве (в виде 00, если они занулены)
// Это лишь моя интерпретация условия задачи.
// Поскольку, у неё нет чётких формулировок, ТЗ, или хотя бы Входных/Выходных данных, считаем это предположение истинным.
// Плюсом ко всему, в задании нас просят переопределить индексацию для всех наследуемых классов =>
// => просто создать поля long и char - не выполнить переопределение оператора индексации в этом классе.

Money &Money::operator+(Money &right) {
  int cent =
	  (this->arr_[size_ - 2] - '0') * 10 + (this->arr_[size_ - 1] - '0') + (right.arr_[right.size_ - 2] - '0') * 10
		  + (right.arr_[right.size_ - 1] - '0');
  auto *res = new unsigned char[size_]{0};
  unsigned int itog_size = size_;
  for (int x = right.size_ - 3; x >= 0; x--) {
	if ((x == 0 && (this->arr_[x] - '0') + (right.arr_[x] - '0') >= 10)) {
	  itog_size++;
	  res[x] = this->arr_[x] + right.arr_[x] - 58;
	  for (int i = itog_size - 1; i > 0; i--) {
		res[i] = res[i - 1];
	  }
	  res[0] = '1';
	} else if ((this->arr_[x] - '0') + (right.arr_[x] - '0') >= 10) {
	  res[x - 1] = 1;
	  res[x] += this->arr_[x] + right.arr_[x] - 58;
	} else {
	  res[x] += this->arr_[x] + right.arr_[x] - '0';
	}
  }
  res[itog_size - 3] += cent / 100;
  res[itog_size - 2] = cent % 100 / 10 + '0';
  res[itog_size - 1] = cent % 10 + '0';
  auto itog = new Money(res, itog_size);
  return *itog;
}

Money::Money() {
  size_ = 0;
  arr_ = new unsigned char[max_size]{0};
}

Money::Money(const unsigned char *arr, unsigned int size) {
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

