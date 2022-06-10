#ifndef RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_5_FUNCTIONS_H_
#define RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_5_FUNCTIONS_H_
#include <iostream>
#include <stdexcept>
#include "Windows.h"

// Структура, представляющая время
struct Time
{
 private:
  int hours_;
  int minutes_;
  // функция без обработки исключений
  friend int64_t TimeToSeconds(Time &);
  // функция с исключением типа int
  friend int64_t TimeToSeconds2(Time &);
  // Функция с исключением стандартного типа
  friend int64_t TimeToSeconds3(Time &);
  // Функция с исключением типа пустого класса
  friend int64_t TimeToSeconds4(Time &);
  // Функция с исключением типа MyTimeException
  friend int64_t TimeToSeconds5(Time &);
  // Функция с исключением типа зависимого класса MyTimeException
  friend int64_t TimeToSeconds6(Time &);
 public:
  Time(int Hours, int Minutes) : hours_(Hours), minutes_(Minutes){};
};

// Пустое исключение
class MyEmptyException {};

// Класс-исключение
class MyTimeException
{
 private:
  int hours_;
  int minutes_;

 public:
  std::string message;

  MyTimeException(int Hours, int Minutes, const std::string& String) :
	  hours_(Hours), minutes_(Minutes), message(String) {};
};

// Класс-наследник-исключение
class MyTimeSonException : public std::invalid_argument
{
 private:
  int hours_;
  int minutes_;

 public:
  MyTimeSonException(int Hours, int Minutes, const std::string& String) :
	  hours_(Hours), minutes_(Minutes), invalid_argument(String) {}
};

#endif //RUSSIAN_UNIVERSITY_OF_TRANSPORT__MIIT__LAB_5_FUNCTIONS_H_
