#ifndef RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_5_FUNCTIONS_H_
#define RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_5_FUNCTIONS_H_
#include <iostream>
#include <stdexcept>
#include "Windows.h"

// Структура, отвечающая за имя в виде кол-ва часов и минут.
template<class T>
struct Time {
 protected:
  T hours_;
  T minutes_;
 public:
  Time(T Hours, T Minutes) : hours_(Hours), minutes_(Minutes) {};
  T get_hours() { return hours_; }
  T get_min() { return minutes_; }
};

// Пустое исключение
class MyEmptyException {};

// Класс-исключение
class MyTimeException {
 private:
  int hours_;
  int minutes_;

 public:
  std::string message;

  MyTimeException(int Hours, int Minutes, const std::string &String) :
	  hours_(Hours), minutes_(Minutes), message(String) {};
};

// Класс-наследник-исключение
class MyTimeSonException : public std::invalid_argument {
 private:
  int hours_;
  int minutes_;

 public:
  MyTimeSonException(int Hours, int Minutes, const std::string &String) :
	  hours_(Hours), minutes_(Minutes), invalid_argument(String) {}
};

template<class T>
// функция без обработки исключений
int64_t TimeToSeconds(Time<T> &time) {
  int64_t result;
  if (time.get_hours() < 0 || time.get_min() < 0
	  || (typeid(time.get_hours()).name() != typeid(int).name()
		  || typeid(time.get_min()).name() != typeid(int).name())) {
	result = -1;
  } else {
	result = time.get_hours() * 3600 + time.get_min() * 60;
  }
  return result;
}

template<class T>
// функция с исключением типа int
int64_t TimeToSeconds2(Time<T> &time) {
  int64_t result;
  if (time.get_hours() < 0 || time.get_min() < 0 || typeid(time.get_hours()).name() != typeid(int).name()
	  || typeid(time.get_min()).name() != typeid(int).name()) {
	throw -1;
  } else {
	result = time.get_hours() * 3600 + time.get_min() * 60;
  }
  return result;
}

template<class T>
// Функция с исключением стандартного типа
int64_t TimeToSeconds3(Time<T> &time) {
  int64_t result;
  if (time.get_hours() < 0 || time.get_min() < 0 || typeid(time.get_hours()).name() != typeid(int).name()
	  || typeid(time.get_min()).name() != typeid(int).name()) {
	throw std::logic_error{"??????? ????? ??????????? ?????"};
  } else {
	result = time.get_hours() * 3600 + time.get_min() * 60;
  }
  return result;
}

template<class T>
// Функция с исключением типа пустого класса
int64_t TimeToSeconds4(Time<T> &time) {
  int64_t result;
  if (time.get_hours() < 0 || time.get_min() < 0 || typeid(time.get_hours()).name() != typeid(int).name()
	  || typeid(time.get_min()).name() != typeid(int).name()) { throw MyEmptyException(); }
  else {
	result = time.get_hours() * 3600 + time.get_min() * 60;
  }
  return result;
}

template<class T>
// Функция с исключением типа MyTimeException
int64_t TimeToSeconds5(Time<T> &time) {
  int64_t result;
  if (time.get_hours() < 0 || time.get_min() < 0 || typeid(time.get_hours()).name() != typeid(int).name()
	  || typeid(time.get_min()).name() != typeid(int).name()) {
	throw MyTimeException(time.get_hours(),
						  time.get_min(),
						  "Где-то напортачили с вводом.");
  }
  else {
	result = time.get_hours() * 3600 + time.get_min() * 60;
  }
  return result;
}

template<class T>
// Функция с исключением типа зависимого класса MyTimeException
int64_t TimeToSeconds6(Time<T> &time) {
  int64_t result;
  if (time.get_hours() < 0 || time.get_min() < 0 || typeid(time.get_hours()).name() != typeid(int).name()
	  || typeid(time.get_min()).name() != typeid(int).name()) {
	throw MyTimeSonException(time.get_hours(),
							 time.get_min(),
							 "Входные данные как-то не очень");
  }
  else {
	result = time.get_hours() * 3600 + time.get_min() * 60;
  }
  return result;
}

#endif //RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_5_FUNCTIONS_H_
