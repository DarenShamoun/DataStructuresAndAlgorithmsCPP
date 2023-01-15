#include <iostream>
#include <string>
#include "lab5.h"

void mesa::set(time_t& time,
	int hours, int minutes, int seconds, char period)
{
	time = { hours, minutes, seconds, period, 0 };

	if (hours < 1 || hours > 12)
	{
		time.errors |= ERROR_HOUR;
	}

	if (minutes < 0 || minutes > 59)
	{
		time.errors |= ERROR_MINUTE;
	}
	
	if (seconds < 0 || seconds > 59)
	{
		time.errors |= ERROR_SECOND;
	}
	
	if (period != 'a' && period != 'p')
	{
		time.errors |= ERROR_PERIOD;
	}
}

void mesa::display(std::ostream& os, const time_t& time)
{
	os << time.hours << ':' << time.minutes << ':' << time.seconds << ' ';
	if (time.period == 'a')
	{
		os << "AM";
	}
	else if (time.period == 'p')
	{
		os << "PM";
	}
	else
	{
		os << time.period;
	}

	if (time.errors != 0)
	{
		os << '[' << int(time.errors) << ']';
	}
}

int64_t mesa::time_to_jiffies(const time_t& time)
{
	if (time.errors == 0)
	{
		auto hrs = time.hours;
		if (time.period == 'a' && time.hours == 12)
		{
			hrs = 0;
		}
		if (time.period == 'p' && time.hours < 12)
		{
			hrs += 12;
		}
		return (int64_t(HZ) * (int64_t(hrs) * 3600 + int64_t(time.minutes) * 60 + int64_t(time.seconds)));
	}
	return 0;
}

mesa::time_t mesa::jiffies_to_time(int64_t jiffies)
{
	struct mesa::time_t value = { 0,0,0,'a'};
	auto sec = (jiffies / mesa::HZ);
	value.hours = (int(sec) / 3600);
	sec = sec - static_cast<int64_t>(value.hours * 3600);

	if (value.hours % 24 >= 12)
	{
		value.period = 'p';
	}
	value.hours %= 12;
	if (value.hours == 0)
	{
		value.hours = 12;
	}

	value.minutes = (int(sec) / 60);
	value.seconds = int(sec) - static_cast<int>(value.minutes * 60);

	return value;
}

void mesa::advance(mesa::time_t& time, int hours, int minutes, int seconds)
{
	int64_t ticks = time_to_jiffies(time);
	ticks += static_cast<int64_t> (mesa::HZ * static_cast<long>(hours * 3600 + minutes * 60 + seconds));
	time = jiffies_to_time(ticks);
}

