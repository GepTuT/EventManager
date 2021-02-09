#pragma once
#include <iostream>
#include <string>

class Event {


public:
	Event() = default;

	Event(const Event& other) {
		*this = other;
	}

	bool operator== (const Event& other) const {
		return (m_Description == other.m_Description)
			&& (m_Place == other.m_Place) && (m_Important == other.m_Important);
	}

	Event& operator= (const Event& other) {
		m_Place = other.m_Place;
		m_Description = other.m_Description;
		m_Day = other.m_Day;
		m_Hour = other.m_Hour;
		m_Min = other.m_Min;
		m_Month = other.m_Month;
		m_Year = other.m_Year;
		m_Important = other.m_Important;
	
		return	*this;
	}

	int GetImportant() {
		return m_Important;
	}
	int GetMin() {
		return m_Min;
	}
	int GetHour  (){
		return m_Hour;
	}
	int GetDay	 (){
		return m_Day;
	}
	int GetMonth (){
		return m_Month;
	}
	int GetYear	 (){
		return m_Year;
	}
	int GetSort  (){
		return m_sort;
	}
	std::string  GetDescription() {
		return m_Description;
	}
	std::string  GetPlace() {
		return m_Place;
	}

	std::string GetMonth_Char(int month) {
		return month_char(month);
	}

	std::string GetWeek_Day(int day, int month, int year) {
		return week_day(day, month, year);
	}

	void SetImportant(int set) {
		m_Important = set;
	}
	void SetMin(int set) {
		m_Min = set;
	}
	void SetHour(int set) {
		m_Hour = set;
	}
	void SetDay(int set) {
		m_Day = set;
	}
	void SetMonth(int set) {
		m_Month = set;
	}
	void SetYear(int set) {
		m_Year = set;
	}
	void SetSort(int set) {
		m_sort = set;
	}
	void  SetDescription(std::string set) {
		 m_Description=set;
	}
	void  SetPlace(std::string set) {
		m_Place = set;
	}




private:
	int m_Important=0;
	int m_Min	= 0;
	int m_Hour = 0;
	int m_Day	= 0;
	int m_Month = 0;
	int m_Year = 0;
	int m_sort = 1;
	std::string  m_Description;
	std::string  m_Place;

	std::string month_char(int month)
	{
		std::string mc;
		switch (month) {
		case 1:  mc = "JAN"; break;
		case 2:  mc = "FEB"; break;
		case 3:  mc = "MAR"; break;
		case 4:  mc = "APR"; break;
		case 5:  mc = "MAY"; break;
		case 6:  mc = "JUN"; break;
		case 7:  mc = "JUL"; break;
		case 8:  mc = "AUG"; break;
		case 9:  mc = "SEP"; break;
		case 10: mc = "OKT"; break;
		case 11: mc = "NOV"; break;
		case 12: mc = "DEC"; break;
		}
		return mc;
	}

	std::string week_day(int day, int month, int year)
	{
		std::string dnc;
		int a = (14 - month) / 12;
		int y = year - a;
		int m = month + 12 * a - 2;
		int dn = (7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;
		switch (dn) {
		case 0: dnc = "SUN"; break;
		case 1: dnc = "MON"; break;
		case 2: dnc = "TUE"; break;
		case 3: dnc = "WED"; break;
		case 4: dnc = "THU"; break;
		case 5: dnc = "FRI"; break;
		case 6: dnc = "SAT"; break;
		}
		return dnc;
	}







};