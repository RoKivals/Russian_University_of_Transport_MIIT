#include "BitString.h"

// Конструктор без параметров будет создавать массив с размером 0 и
// выделенной памятью для максимального кол-ва элементов.
BitString::BitString() {
  size_ = 0;
  arr_ = new unsigned char[max_size];
  std::fill(arr_, arr_ + max_size, '0');
}

// Реализуем конструктор BitString от двух параметров (массива данных и размера)
BitString::BitString(const unsigned char *arr, unsigned int size) {
  // Если массив данных создан, а размер подходит по условиям, то изменяем размер объекта
  // и передаём в него все элементы из массива
  if (size >= 0 && size < max_size && arr != nullptr) {
	size_ = size;
	arr_ = new unsigned char[size_];
	for (unsigned int x = 0; x < size_; x++) {
	  this->arr_[x] = arr[x];
	}
  } // Если одно из условий не выполнено, устанавливаем размер, равный 0 и выделяем память для внутреннего массива
  else {
	size_ = 0;
	arr_ = new unsigned char[size_];
  }
}

// Поскольку, в отличие от класса Money, в классе BitString у нас нет необходимости смещать один из массивов
// (нет разрядности чисел, что играло роль в денежном эквиваленте + невозможно переполнения байта в значении суммы.
// Сложение битовых строк будем производить по методу побитового логического ИЛИ.
BitString &BitString::operator+(BitString &right) {
  // Итоговый размер массива
  int itog_size = std::max(size_, right.size_);
  // Объявляем промежуточный массив для хранения сумм
  auto *res = new unsigned char[std::max(this->size_, right.size_)];
  // Заполняем массив нулями
  std::fill(res, res + itog_size, '0');

  if (right.size_ > this->size_) {
	for (int x = itog_size - 1; x >= this->size_; x--) {
	  res[x] = right.arr_[x];
	}
  } else {
	for (int x = itog_size - 1; x >= right.size_; x--) {
	  res[x] = this->arr_[x];
	}
  }
  for (int x = 0; x < std::min(this->size_, right.size_); x++) {
	if (arr_[x] + right.arr_[x] - '0' == '2') {
	  res[x] = '1';
	} else
	  res[x] = (arr_[x] + right.arr_[x]) - '0';
  }
  auto *bs = new BitString(res, itog_size);
  return *bs;
}

