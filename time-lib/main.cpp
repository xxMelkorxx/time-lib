#include <iostream>
#include "time.h"
using namespace std;

int main()
{
	std::setlocale(LC_ALL, "ru");

	string init_time, time_str;

	CODE_RESULT result1 = GetTimePlus5MinStr("\t2:22\t", time_str);
	cout << result1 << " " << time_str << endl;

	/*CODE_RESULT result2 = GetTimePlus5MinStr("1 3:33", time_str);
	cout << result2 << " " << time_str << endl;*/

	while (true) {
		cout << "Введите время в формате «ЧАС:МИН»" << endl;
		cin >> init_time;

		CODE_RESULT result = GetTimePlus5MinStr(init_time, time_str);
		if (result != OK)
			cout << "INVALID_ARGUMENT" << endl;
		else
			cout << init_time + " + 5 мин = " << time_str << endl;

		char exit;
		cout << "Хотите продолжить? (y/n)" << endl;
		cin >> exit;
		if (exit == 'n') break;
	}
	return 0;
}