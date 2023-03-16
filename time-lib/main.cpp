#include <iostream>
#include "time.h"
using namespace std;

int main()
{
	std::setlocale(LC_ALL, "ru");

	string init_time, time_str;

	while (true) {
		cout << "Введите время в формате «ЧАС:МИН»" << endl;
		cin >> init_time;
		CODE_RESULT result = GetTimePlus5MinStr(init_time, time_str);
		if (result == INVALID_FORMAT) cout << "INVALID FORMAT" << endl;
		else cout << init_time + " + 5 мин = " << time_str << endl;

		char exit;
		cout << "Хотите продолжить? (y/n)" << endl;
		cin >> exit;
		if (exit == 'n') break;
	}
	return 0;
}