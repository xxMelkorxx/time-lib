#pragma once

/*Код ошибки
* INVALID_FORMAT - неверный формат
*/
enum CODE_RESULT
{
	INVALID_FORMAT,
	OK
};

/*
Функция, прибавляющую 5 минут к init_time.
* init_time в формате "{hours}:{minutes}".
* new_time_str - выходной параметр - полученное время в строковом представлении.
Функция возвращает код ошибки - OK или INVALID_FORMAT.
*/
CODE_RESULT GetTimePlus5MinStr(std::string init_time, std::string& new_time_str);
