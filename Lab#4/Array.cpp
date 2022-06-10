#include "Array.h"

Array::Array() {
  size_ = 0;
  arr_ = new unsigned char[max_size]{0};
}

// ��������� ����������� Array
Array::Array(const unsigned char *arr, unsigned int size) {
  arr_ = new unsigned char[max_size]{0}; // ��������� ������ �� ��������� ������
  // ���� ������ �� ������ ��� ������, ����������� ������� ����� 0, ��� ������ ���������,
  // �� ������ ������� ����� 0.
  if (arr == nullptr || size == 0 || size > max_size) {
	size_ = 0;
  } else {
	size_ = size;
	for (unsigned int x = 0; x < size_; x++) {
	  this->arr_[x] = arr[x];
	}
  }
}

// ���, ��� array - ������ ������ ������, �� �� ����� �����������, ��, �� ����������� � ���� ������� �����,
// � ��� �� ����� ������� � ���� ����� ������ ������� => ��� �������� �����, ���� �� ������� ������ 9,
// �� �� ������ �������� ������ ����� � ���� ������. �������, ����� ������������ �������� ����� �������� � �������.
// � ����������� ���������� ������� �� 1. ����� ����, ��� ��� �� ����� ����������� �� ������������� ���-�� ���������,
// �� ���� � ��� ����� ������������ � 0 �������, �� ��� ������� ����������� ����� ���� �������� => ��� �������
// ����� ��������� �� ��������, ������ ������� ��� ������� ������ ������������� �� 1

Array &Array::operator+(Array &right) {
  auto *res = new unsigned char[std::max(this->size_, right.size_)]{0};
  int itog_size = std::max(size_, right.size_);
  int start_sum = std::min(size_, right.size_);
  if (right.size_ > size_) {
	for (int x = itog_size - 1; x >= size_; x--) {
	  res[x] = right.arr_[x];
	}
  }
  if (right.size_ < size_) {
	for (int x = itog_size - 1; x >= right.size_; x--) {
	  res[x] = arr_[x];
	}
  }
  for (int x = start_sum - 1; x >= 0; x--) {
	// ���� � ��� ��� ������������ � 0 ��������, �� ��������� ������� � �������� ���� ������ ������.
	if ((x == 0 && (this->arr_[x] - '0') + (right.arr_[x] - '0') >= 10)) {
	  itog_size++;
	  res[x] = this->arr_[x] + right.arr_[x] - 58;
	  for (int i = itog_size - 1; i > 0; i--) {
		res[i] = res[i - 1];
	  }
	  res[0] = 1;
	}
	  // ���� ��� ������������ � �������, ������������� ������� � ���� ������� ������� (��� ������ ������)
	  // � ����� � ������� �������� ��������� ������� �� ������� �� 10 (���� ������ ��������� ����� � ASCII)
	else if ((this->arr_[x] - '0') + (right.arr_[x] - '0') >= 10) {
	  res[x - 1] = 1;
	  res[x] = this->arr_[x] + right.arr_[x] - 58;
	} else {
	  res[x] = this->arr_[x] + right.arr_[x] - '0';
	}
  }
  auto ar = new Array(res, itog_size);
  return *ar;
}

unsigned char &Array::operator[](int index) {
  if (index >= 0 && index < this->size_) {
	return arr_[index];
  } else {
	std::cout << "You are out of the array";
  }
}

unsigned int Array::get_size() {
  return size_;
}


