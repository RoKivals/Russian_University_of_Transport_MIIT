#include "Array.h"
#include "Windows.h"
#include "Money.h"
#include "BitString.h"

using namespace std;

void menu() {
  int choice;
  std::cout << "Если хотите сложить числа, используя класс Array, нажмите 1.\n";
  std::cout << "Если хотите сложить числа денежного формата, нажмите 2.\n";
  std::cout << "Если хотите сложить сложить битовые строки, нажмите 3.\n";
  std::cin >> choice;
  try {
	if (choice == 1) {
	  auto *ar1 = new unsigned char[max_size]{0};
	  ar1 = (unsigned char *) "2231280";
	  auto *ar2 = new unsigned char[max_size]{0};
	  ar2 = (unsigned char *) "911234";
	  std::cout << "Сумма двух массивов:\n";
	  Array arr1(ar1, 7), arr2(ar2, 6), ar_res;
	  ar_res = arr1 + arr2;
	  std::cout << " ";
	  for (int i = 0; i < arr1.get_size(); i++) {
		std::cout << arr1[i];
	  }
	  std::cout << endl << "+\n ";
	  for (int i = 0; i < arr2.get_size(); i++) {
		std::cout << arr2[i];
	  }
	  std::cout << endl << " ";
	  for (int i = 1; i < max_size; i++) {
		std::cout << "-";
	  }
	  std::cout << endl << " ";

	  for (int i = 0; i < ar_res.get_size(); i++) {
		cout << ar_res[i];
	  }
	  cout << endl;
	} else if (choice == 2) {
	  auto *ar1 = new unsigned char[max_size]{0};
	  ar1 = (unsigned char *) "123400";
	  auto *ar2 = new unsigned char[max_size]{0};
	  ar2 = (unsigned char *) "245600";
	  cout << "Сумма двух денежных сумм:\n\n";
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
		if (i == mon1.get_size() - 3) cout << " ";
	  }
	  cout << endl << " ";
	  for (int i = 1; i < max_size; i++) {
		cout << "-";
	  }
	  cout << endl << " ";
	  for (int i = 0; i < mon_res.get_size(); i++) {
		cout << mon_res[i];
		if (i == mon1.get_size() - 3) cout << " ";
	  }
	  cout << endl;
	} else if (choice == 3) {
	  auto *ar1 = new unsigned char[max_size]{0};
	  ar1 = (unsigned char *) "1010101";
	  auto *ar2 = new unsigned char[max_size]{0};
	  ar2 = (unsigned char *) "1000100";
	  cout << "Сумма двух битовых строк:\n\n";
	  BitString bs1(ar1, 7), bs2(ar2, 7), bs3;
	  cout << " ";
	  for (int i = 0; i < bs1.get_size(); i++) {
		cout << ar1[i];
	  }
	  cout << endl << "+\n ";
	  for (int i = 0; i < bs2.get_size(); i++) {
		cout << ar2[i];
	  }
	  cout << endl << " ";
	  for (int i = 1; i < max_size; i++) {
		cout << "-";
	  }
	  cout << endl << " ";
	  bs3 = bs1 + bs2;
	  for (int i = 0; i < bs3.get_size(); i++) {
		cout << bs3[i];
	  }
	  cout << endl;
	} else {
	  throw string("Ошибка! Повторите ввод!");
	}
  }
  catch (string &m) {
	cout << m << endl << endl;
	menu();
  }
  catch (logic_error& le) {
	cout << le.what() << endl;
  }
}

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  menu();
}
