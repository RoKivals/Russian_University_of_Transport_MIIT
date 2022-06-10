#include "Functions.h"

int64_t TimeToSeconds(Time &time) {

  int64_t result;
  if (time.hours_ < 0 || time.minutes_ < 0 || (typeid(time.hours_).name() != typeid(int).name() || typeid(time.minutes_).name() != typeid(int).name())) {
	result = -1;
  } else {
	result = time.hours_ * 3600 + time.minutes_ * 60;
  }
  return result;
}

int64_t TimeToSeconds2(Time &time) {
  int64_t result;
  if (time.hours_ < 0 || time.minutes_ < 0 || typeid(time.hours_).name() != typeid(int).name() || typeid(time.minutes_).name() != typeid(int).name()) {
	throw -1;
  } else {
	result = time.hours_ * 3600 + time.minutes_ * 60;
  }
  return result;
}

int64_t TimeToSeconds3(Time &time) {
  int64_t result;
  if (time.hours_ < 0 || time.minutes_ < 0 || typeid(time.hours_).name() != typeid(int).name() || typeid(time.minutes_).name() != typeid(int).name()) {
	throw std::logic_error{"”добнее всего перемножать числа"};
  } else {
	result = time.hours_ * 3600 + time.minutes_ * 60;
  }
  return result;
}

int64_t TimeToSeconds4(Time &time) {
  int64_t result;
  if (time.hours_ < 0 || time.minutes_ < 0 || typeid(time.hours_).name() != typeid(int).name() || typeid(time.minutes_).name() != typeid(int).name())
  { throw MyEmptyException(); }
  else {
	result = time.hours_ * 3600 + time.minutes_ * 60;
  }
  return result;
}

int64_t TimeToSeconds5(Time &time) {
  int64_t result;
  if (time.hours_ < 0 || time.minutes_ < 0 || typeid(time.hours_).name() != typeid(int).name() || typeid(time.minutes_).name() != typeid(int).name())
  { throw MyTimeException(time.hours_, time.minutes_, "√де-то напортачили с вводом."); }
  else {
	result = time.hours_ * 3600 + time.minutes_ * 60;
  }
  return result;
}

int64_t TimeToSeconds6(Time &time) {
  int64_t result;
  if (time.hours_ < 0 || time.minutes_ < 0 || typeid(time.hours_).name() != typeid(int).name() || typeid(time.minutes_).name() != typeid(int).name())
  { throw MyTimeSonException(time.hours_, time.minutes_, "¬ходные данные как-то не очень"); }
  else {
	result = time.hours_ * 3600 + time.minutes_ * 60;
  }
  return result;
}

