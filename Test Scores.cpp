#include <iostream>
#include <cmath>

using namespace std;

void program_title() {
  cout << "Paycheck Calculator\n\n";
}

double calculator (double hours, double pay_rate, double total_gross_pay) {
  if (hours <= 0.0) {
    throw invalid_argument ("Error! hours must be > 0."); // error statement for invalid number of hours.
  }
  if (pay_rate <= 0.0) {
    throw invalid_argument ("Error! rate must be > 0."); // error statement for invalid pay rate.
  }
  if (hours > 40.0) { // this if statement tests if the user entrrs more than 40 hours  and then calculates the total gross pay with overtime pay properly added at the value of 1.5 times normal pay.
  double  overtime_hours,
          overtime_gross_pay,
          overtime = 1.5;
    overtime_hours = hours - 40;
    overtime_gross_pay = (overtime * pay_rate) * overtime_hours;
    hours = 40;
    total_gross_pay = overtime_gross_pay + (hours * pay_rate);
  }
  else { 
    total_gross_pay = hours * pay_rate; // this calculates the total gross pay if the user enters 40 or less hours. 
  }
  return total_gross_pay;
}

int main() {
  double  hours,
          pay_rate,
          overtime,
          total_gross_pay; // variables
          
  program_title();
  
  cout << "Hours worked: ";
  cin >> hours;
  cout << endl;
  cout << "Hourly rate of pay: ";
  cin >> pay_rate;
  cout << endl;
  try {                               // if the user enters valid data in the program this will run line 47-48 and display it to the user.
   total_gross_pay = calculator(hours, pay_rate, total_gross_pay);
   cout << "Calculated gross pay: " << total_gross_pay << "\n\n";
  }
  catch (const invalid_argument& e) { // if the user enters incorrct data for pay_rate or hours line 51 is posted to the user explaining
    cout << e.what() <<"\n";          // if they inputted wrong hours first or wrong rate of pay.
  }
  cout << "Bye!";
  return 0;
}