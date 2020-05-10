#ifndef DATESTRUCT_H
#define DATESTRUCT_H

#include <time.h>   //Working with time
#include <MyHeaders/TypeStrmanip.h>

typedef unsigned int uint;


namespace mcl
{
  namespace cDate
  {
    //These are the number of seconds in each time unit
    const unsigned int MinuteLen = 60;
    const unsigned int HourLen   = 60 * MinuteLen;
    const unsigned int DayLen    = 24 * HourLen;
    /* While the number of days in a year is not constant
     * (some having 365 days, and leap years having 366 days),
     * the number of days in any consecutive 400 years is.
     */
    const unsigned int QCYearLen = 146097 * DayLen;


    const std::string MonthsABRV[12] = {
      "Jan",
      "Feb",
      "Mar",
      "Apr",
      "May",
      "Jun",
      "Jul",
      "Aug",
      "Sep",
      "Oct",
      "Nov",
      "Dec"
    };

    const std::string MonthsNAME[12] = {
      "January",
      "February",
      "March",
      "April",
      "May",
      "June",
      "July",
      "August",
      "September",
      "October",
      "November",
      "December"
    };

    const std::string WkDaysABRV[7] = {
      "Mon",
      "Tue",
      "Wed",
      "Thu",
      "Fri",
      "Sat",
      "Sun"
    };

    const std::string WkDaysNAME[7] = {
      "Monday",
      "Tuesday",
      "Wednesday",
      "Thursday",
      "Friday",
      "Saturday",
      "Sunday"
    };
  };


  struct Date   //This will store a date, and be able to convert between a Unix timestamp and human-readable date
  {
  private:
    //This will store the number of leap seconds, which will be found in a seperate file
    unsigned int LeapSeconds;

    //These are the actual date variables that will hold the year, month, etc.
    unsigned int Year, Month, Day, Hour, Minute, Second;
    unsigned int DaysSince1970, HoursSince1970, MinutesSince1970;

    //This will hold the number of seconds from 01-Jan-1970 00:00:00 to the date in the Date structure
    time_t UnixTimestamp;
    time_t tzUnixTimestamp;

    //At initialization of the struct, it will work Feb out
    uint DaysInMonths[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31 }; //The last element represents January. It's there so we don't go out of range of the set.

    int TimeZoneOffset = 0;
    bool TZSet = 0;


    bool InitWithDate;

  public:
    inline static int DefaultTZO = 0;
    //Consider adding multiple formats

    Date();
    Date(time_t);
    Date(std::string);
    Date(uint year, uint month = 1, uint day = 1, uint hour = 0, uint minute = 0, uint second = 0);

    void SetTime(time_t);
    void ResetTime();

    int Get_intYear() const;   std::string Get_strYear() const;
    int Get_intMonth() const;  std::string Get_strMonth() const;   std::string Get_abrvMonth() const;  std::string Get_nameMonth() const;
    int Get_intDay() const;    std::string Get_strDay() const;     std::string Get_abrvDay() const;    std::string Get_nameDay() const;
    int Get_intHour() const;   std::string Get_strHour() const;
    int Get_intMinute() const; std::string Get_strMinute() const;
    int Get_intSecond() const; std::string Get_strSecond() const;
    time_t Get_UnixTime() const;

    std::string Get_FullDate() const;
    std::string Get_HHMM() const;
    std::string Get_HHMMSS() const;
    std::string Get_DDMMMYear() const;

    static bool IsLeapYear(uint);
    bool IsLeapYear() const;

    Date& operator=(const Date&);

    void Set_TimeZone(int);
  };


  Date::Date()
  {
    this->SetTime(time(NULL));
  }
  Date::Date(time_t Time)
  {
    this->SetTime(Time);
  }
  Date::Date(std::string str)
  {
    //Later
  }
  Date::Date(uint year, uint month, uint day, uint hour, uint minute, uint second)
  {
    if (IsLeapYear(year))
      DaysInMonths[1] = 29;
    uint difyear = year - 1970;
    UnixTimestamp = (difyear * 365
                   + difyear / 4 + ((difyear % 4) && ((1 >= 4 - (difyear%4))))
                   - (difyear / 100 + ((difyear % 100) && ((69 >= 100 - (difyear%100)))))
                   + difyear / 400 + ((difyear % 400) && ((369 >= 400 - (difyear%400))))) * cDate::DayLen;
    for (uint i = 0; i < month; i++)
      UnixTimestamp += DaysInMonths[i] * cDate::DayLen;
    UnixTimestamp += day * cDate::DayLen
                   + hour * cDate::HourLen
                   + minute * cDate::MinuteLen
                   + second;
    this->SetTime(UnixTimestamp);
  }

  void Date::ResetTime()
  {
    this->SetTime(UnixTimestamp);
  }

  void Date::SetTime(time_t Time)
  {
    if (!TZSet)
      TimeZoneOffset = DefaultTZO;
    UnixTimestamp = Time;
    if (TimeZoneOffset < 0)
      Time -= (-TimeZoneOffset) * cDate::HourLen;
    else
      Time += TimeZoneOffset * cDate::HourLen;
    DaysSince1970 = Time / cDate::DayLen;
    HoursSince1970 = Time / cDate::HourLen;
    MinutesSince1970 = Time / cDate::MinuteLen;
    tzUnixTimestamp = Time;
    Year = 1970 + Time / (365 * cDate::DayLen);
    Time %= 365 * cDate::DayLen;
    while ((CountRecur(4, 1970, Year - 1970) - CountRecur(100, 1970, Year - 1970) + CountRecur(400, 1970, Year - 1970)) * cDate::DayLen > Time)
    {
      --Year;
      Time += 365 * cDate::DayLen;
    }
    Time -= (CountRecur(4, 1970, Year - 1970) - CountRecur(100, 1970, Year - 1970) + CountRecur(400, 1970, Year - 1970)) * cDate::DayLen;

    if (IsLeapYear(Year))
      DaysInMonths[1] = 29;
    Month = 0;
    while (DaysInMonths[Month] * cDate::DayLen < Time)
      Time %= DaysInMonths[Month++] * cDate::DayLen;
    Day = Time / cDate::DayLen;
    Time %= cDate::DayLen;
    Hour = Time / cDate::HourLen;
    Time %= cDate::HourLen;
    Minute = Time / cDate::MinuteLen;
    Time %= cDate::MinuteLen;
    Second = Time;
  }


  std::string Date::Get_FullDate() const
  {
    const char* NumSuffix = "th\0st\0nd\0rd";

    return cDate::WkDaysNAME[(DaysSince1970 + 3) % 7] +
          " the " + NtoS(Day+1) + ((Day+1) / 10 != 1 && (Day+1) % 10 < 4 ? NumSuffix + (3 * ((Day+1)%10)) : "th") +
          " of " + cDate::MonthsNAME[Month] +
          ", " + NtoS(Year) +
          ", " + NtoS(Hour, 10, 2) + ":" + NtoS(Minute, 10, 2) + ":" + NtoS(Second, 10, 2);
  }
  std::string Date::Get_HHMM() const
  {
    return NtoS(Hour, 10, 2) + ":" + NtoS(Minute, 10, 2);
  }
  std::string Date::Get_HHMMSS() const
  {
    return NtoS(Hour, 10, 2) + ":" + NtoS(Minute, 10, 2) + ":" + NtoS(Second, 10, 2);
  }
  std::string Date::Get_DDMMMYear() const
  {
    return NtoS(Day+1, 10, 2) + "-" + cDate::MonthsABRV[Month] + "-" + NtoS(Year);
  }

  bool Date::IsLeapYear(uint y)
  {
    if (y % 4)//Not a multiple of 4.
      return 0;
    if (y % 100)
      return y % 400 == 0;
    return 1;
  }


  Date& Date::operator=(const Date& rhs)
  {
    this->Year = rhs.Year;
    this->Month = rhs.Month;
    this->Day = rhs.Day;
    this->Hour = rhs.Hour;
    this->Minute = rhs.Minute;
    this->Second = rhs.Second;
    this->DaysSince1970 = rhs.DaysSince1970;
    this->HoursSince1970 = rhs.HoursSince1970;
    this->MinutesSince1970 = rhs.MinutesSince1970;
    this->UnixTimestamp = rhs.UnixTimestamp;
    this->tzUnixTimestamp = rhs.tzUnixTimestamp;
    this->TimeZoneOffset = rhs.TimeZoneOffset;

    return *this;
  }

  void Date::Set_TimeZone(int z)
  {
    TimeZoneOffset = z;
    TZSet = 1;
  }
}


#endif
