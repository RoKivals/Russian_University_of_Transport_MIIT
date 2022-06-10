#include "Functions.h"
#include <string>

using namespace std;

int main()
{ SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  Time Time1(3, 15);
  try
  {
	std::cout << TimeToSeconds(Time1) << std::endl;
  }
  catch (int)
  {
	std::cout << "������ ������� ������!" << std::endl;
  }

  try
  {
	std::cout << TimeToSeconds2(Time1) << std::endl;
  }
  catch (int m)
  {
	std::cout << "������ ������� ������! ��� ������ " << m << std::endl;
  }

  try
  {
	std::cout << TimeToSeconds3(Time1) << std::endl;
  }
  catch (std::invalid_argument e)
  {
	std::cout << "������ ����: " << e.what() << std::endl;
  }

  try
  {
	std::cout << TimeToSeconds4(Time1) << std::endl;
  }
  catch (MyEmptyException)
  {
	std::cout << "������ ������� ������! ���������� ���� ������ �����" << std::endl;
  }

  try
  {
	std::cout << TimeToSeconds5(Time1) << std::endl;
  }
  catch (MyTimeException e)
  {
	std::cout << "��������� ������: " << e.message << std::endl;
  }

  try
  {
	std::cout << TimeToSeconds6(Time1) << std::endl;
  }
  catch (MyTimeSonException e)
  {
	std::cout << "������ ������� ������! ���������� ���� ��������������� ������: " << e.what() << std::endl;
  }
}

