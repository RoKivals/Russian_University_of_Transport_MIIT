#include "Array.h"
#include "Windows.h"
#include "Money.h"
#include "String.h"

using namespace std;

void menu() {
  const int msize = 255;
  int choice;
  std::cout << "Если хотите сложить числа, используя класс Array, нажмите 1.\n";
  std::cout << "Если хотите сложить числа денежного формата, нажмите 2.\n";
  std::cout << "Если хотите сложить сложить битовые строки, нажмите 3.\n";
  std::cin >> choice;
  try {
	if (choice == 1) {
	  auto *ar1 = new unsigned char[msize]{0};
	  ar1 = (unsigned char *)"9231240";
	  auto *ar2 = new unsigned char[msize]{0};
	  ar2 = (unsigned char *)"211234";
	  std::cout << "Сумма двух массивов:\n";
	  Array arr1(ar1, 7), arr2(ar2, 6), arr_res;
	  arr_res = arr1 + arr2;
	  std::cout << " ";
	  for (int i = 0; i < arr1.get_size(); i++) {
		std::cout << arr1[i];
	  }
	  std::cout << endl << "+\n ";
	  for (int i = 0; i < arr2.get_size(); i++) {
		std::cout << arr2[i];
	  }
	  std::cout << endl << " ";
	  for (int i = 0; i < arr_res.get_size(); i++) {
		std::cout << "-";
	  }
	  std::cout << endl << " ";
	  for (int i = 0; i < arr_res.get_size(); i++) {
		cout << arr_res[i];
	  }
	  cout << endl;
	} else if (choice == 2) {
	  auto *ar1 = new unsigned char[msize]{0};
	  ar1 = (unsigned char *)"823400";
	  auto *ar2 = new unsigned char[msize]{0};
	  ar2 = (unsigned char *)"245600";
	  cout << "Денежная сумма:\n\n";
	  Money mon1(ar1, 6), mon2(ar2, 6), mon_res;
	  mon_res = mon1 + mon2;
	  cout << " ";
	  for (int i = 0; i < mon1.get_size(); i++) {
		cout << ar1[i];
		if (i == mon1.get_size() - 3) cout << " ";
	  }
	  cout << endl << "+\n ";
	  for (int i = 0; i < mon2.get_size(); i++) {
		cout << ar2[i];
		if (i == mon2.get_size() - 3) cout << " ";
	  }
	  cout << endl << " ";
	  for (int i = 0; i < mon_res.get_size() + 1; i++) {
		cout << "-";
	  }
	  cout << endl << " ";
	  for (int i = 0; i < mon_res.get_size(); i++) {
		cout << mon_res[i];
		if (i == mon_res.get_size() - 3) cout << " ";
	  }
	  cout << endl;
	} else if (choice == 3) {
	  auto *ar1 = new unsigned char[msize]{0};
	  ar1 = (unsigned char *)"n0b01o1";
	  auto *ar2 = new unsigned char[msize]{0};
	  ar2 = (unsigned char *)"100acl0";
	  cout << "Сумма двух строк:\n\n";
	  String str1(ar1, 7), str2(ar2, 7), str_res;
	  str_res = str1 + str2;
	  cout << " ";
	  for (int i = 0; i < str1.get_size(); i++) {
		cout << str1[i];
	  }
	  cout << endl << "+\n ";
	  for (int i = 0; i < str2.get_size(); i++) {
		cout << str2[i];
	  }
	  cout << endl << " ";
	  for (int i = 1; i < str_res.get_size(); i++) {
		cout << "-";
	  }
	  cout << endl << " ";
	  for (int i = 1; i < str_res.get_size(); i++) {
		cout << str_res[i];
	  }
	  cout << endl;
	} else {
	  throw string("Ошибка! Повторите ввод!");
	}
  }
  catch (const std::out_of_range &oor) {
	std::cout << oor.what() << std::endl;
	menu();
  }

  catch (const string &m) {
	cout << m << endl << endl;
	menu();
  }

}

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  menu();
}

