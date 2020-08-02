#include <bits/stdc++.h>
#include <climits>

// Loops from `begin` to `end` excluding `end`. Goes forward and backward both.
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
// Same as above. Only goes forward.
#define srep(i, begin, end) for (__typeof(end) i = begin; i != end; i++)
#define sll(x) LL x; cin >> x
#define pll(x) printf("%lld ", x)
#define nl printf("\n")

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef vector<LL> VLL;
typedef pair<LL, LL> PLL;

// Number of Sundays On First of the Month in years 1900-2288
LL SUNDAYS = 688;

// Number to add for a month to find the weekday on first
LL cumulative_days_of_month[] = {-1, 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
LL cumulative_days_of_month_leap_year[] = {-1, 0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};

bool isLeapYear(LL year) {
    if(year % 400 == 0) {
        return true;
    }
    if(year % 100 == 0) {
        return false;
    }
    if(year % 4 == 0) {
        return true;
    }
    return false;
}

map<LL,LL> year_cache;
// Returns weekday of 1st January of the year
LL getFirstDayOfYear(LL given_year) {
    // Every 400 years the cylce repeats.
    // So finding the nearest year to 1900 
    // which is away from the actual year by a multiple of 400
    LL equivalent_year = 1900 + (given_year - 1900) % 400;
    // Read from cache
    if(year_cache.find(equivalent_year) != year_cache.end()) {
        return year_cache[equivalent_year];
    }
    // 0 - Sunday, 1 - Monday ...
    LL day = 1;
    // Every year weekdays move forward by 1.
    // Except on leap years when they move forward by 2.
    rep(year, 1900, equivalent_year) {
        day++;
        if(isLeapYear(year)) {
            day++;
        }
        day %= 7;
    }
    // Store in cache
    year_cache[equivalent_year] = day;
    return day;
}

// If 1st of month in year is a Sunday
bool isFirstSunday(LL month, LL year) {
    // Get weekday on first day of the year
    LL day = getFirstDayOfYear(year);
    // 0 - Sunday
    // Leap Years have different number of days
    if(isLeapYear(year)) {
        return ((day + cumulative_days_of_month_leap_year[month]) % 7 == 0);
    } else {
        return ((day + cumulative_days_of_month[month]) % 7 == 0);
    }
}

map<LL, LL> sunday_cache;
// Count months of year where 1st is Sunday
LL countSundaysOnFirst(LL given_year) {
    // Every 400 years the cylce repeats.
    // So finding the nearest year to 1900 
    // which is away from the actual year by a multiple of 400
    LL equivalent_year = 1900 + (given_year - 1900) % 400;
    if(sunday_cache.find(equivalent_year) != sunday_cache.end()) {
        return sunday_cache[equivalent_year];
    }
    LL count = 0;
    rep(month, 1, 13) {
        if(isFirstSunday(month, equivalent_year)) {
            count++;
        }
    }
    sunday_cache[equivalent_year] = count;
    return count;
}

LL countSundaysOnFirstBetweenDates(LL d_1, LL m_1, LL y_1, LL d_2, LL m_2, LL y_2) {
    // Move to next month's first
    if(d_1 != 1) {
        d_1 = 1;
        if(m_1 != 12) {
            m_1++;
        }
        else {
            m_1 = 1; y_1++;
        }
    }
    LL count = 0;
    if(y_1 == y_2) {
        // Count Sundays on Firsts for every month including first and last month
        rep(m, m_1, m_2+1) {
            if(isFirstSunday(m, y_1)) {
                count++;
            }
        }
    }
    else if(y_2 - y_1 < 400) {
        // Count Sundays on First for every month after first in the first year
        rep(m, m_1, 13) {
            if(isFirstSunday(m, y_1)) {
                count++;
            }
        }
        // Count Sundays on First for every year betwwen first and last
        rep(y, y_1+1, y_2) {
            count += countSundaysOnFirst(y);
        }
        // Count Sundays on First on every month before last including the last month in the last year
        rep(m, 1, m_2+1) {
            if(isFirstSunday(m, y_2)) {
                count++;
            }
        }
    }
    else {
        // Move to next year 
        rep(m, m_1, 13) {
            if(isFirstSunday(m, y_1)) {
                count++;
            }
        }
        d_1 = 1; m_1 = 1; y_1++;

        // Move to previous year
        rep(m, 1, m_2+1) {
            if(isFirstSunday(m, y_2)) {
                count++;
            }
        }
        d_1 = 31; m_2 = 12; y_2--;

        while(y_1 <= y_2 && y_1 % 400 != 0) {
            count += countSundaysOnFirst(y_1);
            y_1++;
        }
        while(y_2 >= y_1 && (y_2 + 1) % 400 != 0) {
            count += countSundaysOnFirst(y_2);
            y_2--;
        }
        LL count_of_400s = (y_2/400) - (y_1/400) + 1;
        count += (count_of_400s * SUNDAYS);
    }

    return count;
}

int main() {
    sll(t);
    rep(_, 0, t) {
        sll(y_1); sll(m_1); sll(d_1);
        sll(y_2); sll(m_2); sll(d_2);
        LL answer = countSundaysOnFirstBetweenDates(d_1, m_1, y_1, d_2, m_2, y_2);
        pll(answer); nl;
    }
}
