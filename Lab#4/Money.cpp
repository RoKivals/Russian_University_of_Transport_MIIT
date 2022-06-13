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
  // Итоговый размер массива
  int itog_size = std::max(this->size_, right.size_);
  // индекс, на котором один из двух массивов начинается, если они разные
  int fir_stop = right.size_ - this->size_;
  // Выделяем память для массива, хранящего суммы элементов
  auto *res = new unsigned char[itog_size];
  // Заполняем массив нулями
  std::fill(res, res + itog_size, '0');
  if (right.size_ >= this->size_) {
	// Если правое число больше левого
	for (int x = 0; x < fir_stop; x++) {
	  res[x] = right.arr_[x];
	}
	for (int x = itog_size - 1; x >= fir_stop; --x) {
	  if ((x == 0 && (this->arr_[x - fir_stop] - '0') + (right.arr_[x] - '0') >= 10)) {
		itog_size++;
		res[x] += this->arr_[x - fir_stop] + right.arr_[x] - 106;
		for (int i = itog_size - 1; i > 0; i--) {
		  res[i] = res[i - 1];
		}
		res[0] = '1';
	  } else if ((this->arr_[x - fir_stop] - '0') + (right.arr_[x] - '0') >= 10) {
		res[x - 1] = '1';
		res[x] += this->arr_[x - fir_stop] + right.arr_[x] - 106;
	  } else {
		res[x] += this->arr_[x - fir_stop] + right.arr_[x] - 96;
	  }
	}
  } else {
	// Если левое число больше правого
	for (int x = 0; x < fir_stop; x++) {
	  res[x] = this->arr_[x];
	}
	for (int x = itog_size - 1; x >= fir_stop; x--) {
	  if ((x == 0 && (this->arr_[x] - '0') + (right.arr_[x - fir_stop] - '0') >= 10)) {
		itog_size++;
		res[x] += this->arr_[x] + right.arr_[x - fir_stop] - 106;
		for (int i = itog_size - 1; i > 0; i--) {
		  res[i] = res[i - 1];
		}
		res[0] = '1';
	  } else if ((this->arr_[x] - '0') + (right.arr_[x - fir_stop] - '0') >= 10) {
		res[x - 1] = '1';
		res[x] += this->arr_[x] + right.arr_[x - fir_stop] - 106;
	  } else {
		res[x] += this->arr_[x] + right.arr_[x - fir_stop] - 96;
	  }
	}
  }
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



