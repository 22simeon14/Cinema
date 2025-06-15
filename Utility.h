#pragma once

struct Date {
	int day;
	int month;
	int year;

	
};

struct Hour {
	int hour;
	int minutes;

	int to_mins() const{
		return minutes + hour * 60;
	}

};

enum class Theme {
	Nature,
	History,
	HistoricalFigure
};


inline bool do_hours_intersect(const Hour& start1, const Hour& end1, const Hour& start2, const Hour& end2) {
	int s1 = start1.to_mins();
	int e1 = end1.to_mins();
	int s2 = start2.to_mins();
	int e2 = end2.to_mins();

	return s1 < e2 && s2 < e1;
}

inline bool are_dates_equal(const Date& date1, const Date& date2)  {
	return date1.day == date2.day && date1.month == date2.month && date1.year == date2.year;
}