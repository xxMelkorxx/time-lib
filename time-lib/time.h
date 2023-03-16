#pragma once

/*��� ������
* INVALID_FORMAT - �������� ������
*/
enum CODE_RESULT
{
	INVALID_FORMAT,
	OK
};

/*
�������, ������������ 5 ����� � init_time.
* init_time � ������� "{hours}:{minutes}".
* new_time_str - �������� �������� - ���������� ����� � ��������� �������������.
������� ���������� ��� ������ - OK ��� INVALID_FORMAT.
*/
CODE_RESULT GetTimePlus5MinStr(std::string init_time, std::string& new_time_str);
