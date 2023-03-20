#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include <map>
#include <vector>
#include "time.h"
using namespace std;

map<int, string> str_hours = {
	{0, "ноль"},
	{1, "один"},
	{2, "два"},
	{3, "три"},
	{4, "четыре"},
	{5, "пять"},
	{6, "шесть"},
	{7, "семь"},
	{8, "восемь"},
	{9, "девять"},
	{10, "десять"},
	{11, "одиннадцать"},
	{12, "двенадцать"},
	{13, "тринадцать"},
	{14, "четырнадцать"},
	{15, "пятнадцать"},
	{16, "шестнадцать"},
	{17, "семнадцать"},
	{18, "восемьнадцать"},
	{19, "девятнадцать"},
	{20, "двадцать"},
	{30, "тридцать"},
	{40, "сорок"},
	{50, "пятьдесят"},
};

map<int, string> str_minutes = {
	{0, "ноль"},
	{1, "одна"},
	{2, "две"},
	{3, "три"},
	{4, "четыре"},
	{5, "пять"},
	{6, "шесть"},
	{7, "семь"},
	{8, "восемь"},
	{9, "девять"},
	{10, "десять"},
	{11, "одиннадцать"},
	{12, "двенадцать"},
	{13, "тринадцать"},
	{14, "четырнадцать"},
	{15, "пятнадцать"},
	{16, "шестнадцать"},
	{17, "семнадцать"},
	{18, "восемьнадцать"},
	{19, "девятнадцать"},
	{20, "двадцать"},
	{30, "тридцать"},
	{40, "сорок"},
	{50, "пятьдесят"},
};

vector<string> split(string str_to_split, char delimeter)
{
	stringstream ss(str_to_split);
	string item;
	vector<string> splittedStrings;
	while (getline(ss, item, delimeter)) {
		splittedStrings.push_back(item);
	}
	return splittedStrings;
}

CODE_RESULT GetTimePlus5MinStr(string init_time, string& new_time_str)
{
	regex rgx1("^[2][0-3][:][0-5][0-9]$");
	regex rgx2("^[1][0-9][:][0-5][0-9]$");
	regex rgx3("^[0]{0,1}[0-9][:][0-5][0-9]$");
	if (!regex_match(init_time, rgx1) && !regex_match(init_time, rgx2) && !regex_match(init_time, rgx3))
		return INVALID_ARGUMENT;
	
	vector<string> split_time = split(init_time, ':');
	int h = stoi(split_time[0]);
	int m = stoi(split_time[1]);

	m += 5;
	if (m >= 60) {
		h++;
		if (h == 24) h = 0;
		m %= 60;
	}

	string str_h, str_m;
	if (h > 20) {
		int hh = h % 10;
		h -= hh;
		str_h = str_hours[h] + " " + str_hours[hh] + (hh == 1 ? " час" : " часа");
	}
	else str_h = str_hours[h] + ((h == 1) ? " час" : ((h >= 2 && h <= 4) ? " часа" : " часов"));

	if (m > 20) {
		int mm = m % 10;
		m -= mm;
		str_m = str_minutes[m] + " " + str_minutes[mm] + ((mm == 1) ? " минута" : ((mm >= 2 && mm <= 4) ? " минуты" : " минут"));
	}
	else str_m = str_minutes[m] + ((m == 1) ? " минута" : ((m >= 2 && m <= 4) ? " минуты" : " минут"));

	new_time_str = str_h + " " + str_m;

	return OK;
}