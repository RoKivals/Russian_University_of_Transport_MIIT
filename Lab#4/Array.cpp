#include "Array.h"

// Конструктор без параметров будет создавать массив с размером 0 и
// выделенной памятью для максимального кол-ва элементов.
Array::Array() {
  size_ = 0;
  arr_ = new unsigned char[max_size];
  std::fill(arr_, arr_ + max_size, '0');
}

// Реализуем конструктор Array от двух параметров (массива данных и размера)
Array::Array(const unsigned char *arr, int size) {
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

/*
 * Поскольку это просто массив, который из себя не представляет строку или число,
 * будем складывать его элементы арифметическим путём справа налево. Арифметический способ подразумевает под собой
 * увеличение на единицу прошлого элемента, если мы получим число больше 10.
 * По сути, это просто школьный метод сложения столбиком. За тем лишь исключением,
 * что если один из массивов меньше другого, то будем считать, что тот массив который МЕНЬШЕ,
 * справа заполнен нулями (что при сложении даст нам просто число из БОЛЬШЕГО массива).
 * Также, в случае переполнения нулевого разряда предусмотрена возможность сдвига всего результата вправо
 * и записи единицы в нулевом индексе. А так как по условию задачи мы имеем ограничение
 * на максимальное кол-во элементов, то наверняка можно складывать только те массивы, размер которых на 1 меньше максимума.
 */

Array &Array::operator+(Array &right) {
  // Объявляем промежуточный массив для хранения сумм
  auto *res = new unsigned char[std::max(this->size_, right.size_)];
  // Итоговый размер массива
  int itog_size = std::max(size_, right.size_);
  std::fill(res, res + itog_size, '0');
  for (int x = itog_size - 1; x >= 0; x--) {
	// Если у нас идёт переполнение в 0 элементе, то добавляем элемент и сдвигаем весь массив вправо.
	if ((x == 0 && (this->arr_[x] - '0') + (right.arr_[x] - '0') >= 10)) {
	  itog_size++;
	  res[x] += this->arr_[x] + right.arr_[x] - 106;
	  for (int i = itog_size - 1; i > 0; i--) {
		res[i] = res[i - 1];
	  }
	  res[0] = '1';
	}
	  // Если идёт переполнение в разряде, устанавливаем единицу в след элемент массива (идём справа налево)
	  // А также в текущем элементы оставляем остаток от деления на 10 (путём вычета последней цифры в ASCII)
	else if ((this->arr_[x] - '0') + (right.arr_[x] - '0') >= 10) {
	  res[x - 1] = '1';
	  res[x] += this->arr_[x] + right.arr_[x] - 106;
	} else {
	  res[x] += ((this->arr_[x] + right.arr_[x]) - 96);
	}
  }
  auto ar = new Array(res, itog_size);
  return *ar;
}

// Если будет запрошен отрицательный индекс, будет выброшено исключение
unsigned char &Array::operator[](int index) {
  if (index >= 0 && index < this->size_) {
	return arr_[index];
  } else {
	throw std::logic_error("Это тебе не питон!");
  }
}

// Возвращает кол-во элементов в массиве (может не совпадать с кол-вом выделенной памяти
unsigned int Array::get_size() {
  return size_;
}


