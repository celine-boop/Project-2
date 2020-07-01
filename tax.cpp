#include <iostream>
#include <string>
using namespace std;

int main()
{
	double tax; //set variable for tax

	cout << "Name: "; 
	string name;
	getline(cin, name);
	if (name == ""){ //if the string is emty
		cout << "You must enter a name" << endl;
		return 1;  //stops the function so that the next line does not pop out
	}
		
	cout << "Taxable income: ";
	double taxableincome;
	cin >> taxableincome;
	cin.ignore(10000, '\n'); //getline followed by cin int
	if (taxableincome < 0) {
		cout << "The taxable income must be nonnegative" << endl;
		return 1;
	}

	cout << "Occupation: ";
	string occ;
	getline(cin, occ);
	if (occ == "") {
		cout << "You must enter an occupation" << endl;
		return 1;
	}
		

	cout << "Number of children: ";
	int numchild;
	cin >> numchild;
	cin.ignore(10000, '\n'); //getline followed by cin int
	if (numchild < 0) {
		cout << "The number of children must be nonnegative" << endl;
		return 1;
	}
		

	cout << "---" << endl;
	cout.setf(ios::fixed); //set output to be in 2 decimal places
	cout.precision(2);

	if (taxableincome <= 50000) //first $50000
	{
		tax = (taxableincome * 0.04) - (numchild * 200);
		if (tax > 0) //make sure that tax is not below zero
		{
			cout << name << " would pay " << "$" << tax << endl;
		}
		else
		{
			return 1;
		}
	}
	else if (taxableincome > 50000 && taxableincome <= 120000 && occ != "engineer" || "scientist") //next $70000, and occupation is not engineer or scientist
	{
		tax = (50000 * 0.04) + ((taxableincome - 50000) * 0.06) - (numchild * 200);
		if (tax > 0)
		{
			cout << name << " would pay " << "$" << tax << endl;
		}
		else
		{
			return 1;
		}
	}
	else if (taxableincome > 50000 && taxableincome <= 120000 && occ == "engineer" || "scientist") //next $70000, and occupation is engineer or scientist
	{
		{
			tax = (50000 * 0.04) + ((taxableincome - 50000) * 0.05) - (numchild * 200);
			if (tax > 0)
			{
				cout << name << " would pay " << "$" << tax << endl;
			}
			else
			{
				return 1;
			}
		}
	}
	else //tax larger than $120000
	{
		tax = (50000 * 0.04) + (70000 * 0.06) + ((taxableincome - 12000) * 0.09);
		cout << name << " would pay" << "$" << tax << endl; //tax is non negative as there is no child tax deductions, hence no additional if statements is needed.
	}
}

