#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double borrow_money = 0 , percent = 0 , pay_debt = 0 ;
	cout << "Enter initial loan: ";
	cin>>borrow_money;
	cout << "Enter interest rate per year (%): " ;
	cin>>percent;
	cout << "Enter amount you can pay per year: " ;
	cin>>pay_debt;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	int i = 0;
	do {
		
		double interest = (percent/100)*borrow_money;
		double total = borrow_money+interest;
		if (total >= pay_debt){
			double newbalance = total - pay_debt;
			cout << fixed << setprecision(2); 
			cout << setw(13) << left << i+1; 
			cout << setw(13) << left << borrow_money;
			cout << setw(13) << left << interest;
			cout << setw(13) << left << total;
			cout << setw(13) << left << pay_debt;
			cout << setw(13) << left << newbalance;
			cout << "\n";
			borrow_money = newbalance;
		}else if(total <= pay_debt){
			pay_debt = total;
			double newbalance = total - pay_debt ;
			cout << fixed << setprecision(2); 
			cout << setw(13) << left << i+1; 
			cout << setw(13) << left << borrow_money;
			cout << setw(13) << left << interest;
			cout << setw(13) << left << total;
			cout << setw(13) << left << pay_debt ;
			cout << setw(13) << left << newbalance;
			cout << "\n";
			borrow_money = newbalance;
		}

		i++;	
	}
	while (borrow_money != 0);
	
	return 0;
}