/**********************************
* ПИ-221                          *
* Иванов Тимофей                  *
* Календарь 2.0                   *
* https://onlinegdb.com/UMcNBOVK9 *
* 22.11.2022                      *
**********************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int shiftOne;
int shiftTwo;

void showMonths(string monthOne, string monthTwo, int daysOne, int daysTwo) {
  cout << "          " << monthOne << "                            " << monthTwo << "\n пн вт ср чт пт сб вс бк лп сф   пн вт ср чт пт сб вс бк лп сф\n";
  int weekDayOne = 1;
  int nowDayOne = 1;
  int weekDayTwo = 1;
  int nowDayTwo = 1;
  shiftTwo = (shiftOne + daysOne) % 10;
  int shiftTwoForFuture = shiftTwo;
  while ((nowDayOne <= daysOne) || (nowDayTwo <= daysTwo)) {
    while (shiftOne != 0) {
      cout << "   ";
      shiftOne -= 1;
      weekDayOne += 1;
    }
    while (((weekDayOne) <= 10) && (nowDayOne <= daysOne)) {
      cout << setw(3) << nowDayOne;
      nowDayOne += 1;
      weekDayOne += 1;
    }
    if (nowDayOne >= daysOne) {
      while (weekDayOne <= 10) {
        cout << "   ";
        weekDayOne += 1;
      }
    }
    weekDayOne = 1;
    cout << "  ";
    while (shiftTwo != 0) {
      cout << "   ";
      shiftTwo -= 1;
      weekDayTwo += 1;
    }
    while ((weekDayTwo <= 10) && (nowDayTwo <= daysTwo)) {
      cout << setw(3) << nowDayTwo;
      nowDayTwo += 1;
      weekDayTwo += 1;
    }
    weekDayTwo = 1;
    cout << "\n";
  }
    
  shiftOne = (daysTwo + shiftTwoForFuture) % 10;
  cout << "\n\n";
}

int main() {
  int year;
  cout << "введите год: ";
  cin >> year;
  shiftOne = (((year - 1) * 4 + ((year / 400) + (year / 4) - (year / 100))) % 10);

  showMonths("январь", "февраль", 31, 30);
  if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
    showMonths("март", "апрель", 31, 29);
  } else {
    showMonths("март", "апрель", 31, 28);
  }
  showMonths("май", "июнь", 31, 30);
  showMonths("июль", "август", 31, 31);
  showMonths("сентябрь", "октябрь", 30, 31);
  return 0;
}
