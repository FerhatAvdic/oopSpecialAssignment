#include<iostream>
#include<iomanip>
#include<string>
using namespace std;


class zipCode{
private:
	string barCode;
	bool checkInput(string b);
	bool countOnes(string b);
public:
	zipCode(string b);
	zipCode(int b);
	string getBarCode();
	int getIntFormat();
};

//Used in constructor to check input
bool zipCode::checkInput(string b){
	bool isCorrect(true);
	if (b.length() != 27)
	{
		cout << "The code must have 27 digits." << endl;
		isCorrect = false;
	}
	for (unsigned int i = 0; i < b.length(); i++)
	if (b[i] != '1' && b[i] != '0')
	{
		cout << "The " << i + 1 << ". digit is not valid. It must be either 0 or 1." << endl;
		isCorrect = false;
	}	
	if (b[0] != '1')
	{
		cout << "The code must start with 1." << endl;
		isCorrect = false;
	}
	if (b[b.length() - 1] != '1')
	{
		cout << "The code must end with 1." << endl;
		isCorrect = false;
	}
	if (isCorrect == false) return isCorrect;
	isCorrect = countOnes(b);
	return isCorrect;
}

//Used in checkInput function to count ones in each group of
//five digits excluding the first and last digit of the input
//the number of ones in each group must be exactly two
bool zipCode::countOnes(string b)
{
	bool isCorrect(true);
	string substr1 = b.substr(1, 5);
	string substr2 = b.substr(6, 5);
	string substr3 = b.substr(11, 5);
	string substr4 = b.substr(16, 5);
	string substr5 = b.substr(21, 5);
	int ones1(0);
	int ones2(0);
	int ones3(0);
	int ones4(0);
	int ones5(0);
	for (int i = 0; i < 5; i++)
	{
		if (substr1[i] == '1') ones1++;
		if (substr2[i] == '1') ones2++;
		if (substr3[i] == '1') ones3++;
		if (substr4[i] == '1') ones4++;
		if (substr5[i] == '1') ones5++;
	}
	if (ones1 != 2)
	{
		cout << "First group of five digits consists of " << ones1 << " ones. The number of ones must be exactly 2." << endl;
		isCorrect = false;
	}
	if (ones2 != 2)
	{
		cout << "Second group of five digits consists of " << ones1 << " ones. The number of ones must be exactly 2." << endl;
		isCorrect = false;
	}
	if (ones3 != 2)
	{
		cout << "Third group of five digits consists of " << ones1 << " ones. The number of ones must be exactly 2." << endl;
		isCorrect = false;
	}
	if (ones4 != 2)
	{
		cout << "Fourth group of five digits consists of " << ones1 << " ones. The number of ones must be exactly 2." << endl;
		isCorrect = false;
	}
	if (ones5 != 2)
	{
		cout << "Fifth group of five digits consists of " << ones1 << " ones. The number of ones must be exactly 2." << endl;
		isCorrect = false;
	}
	return isCorrect;
}

zipCode::zipCode(int b) {
	string s = to_string(b);
	bool isOK = checkInput(s);
	if (isOK) barCode = s;
	else 
	{
		cout << "Wrong input." << endl;
		barCode = '0';
	}
}

zipCode::zipCode(string b){
	bool isOK = checkInput(b);
	if (isOK) barCode = b;
	else
	{
		cout << "Wrong input." << endl;
		barCode = '0';
	}
}

string zipCode::getBarCode() { return barCode; }

//converts one group of five digits into a decimal number
//used in getIntFormat function
int convertOneGroup(string five)
{
	int num;
	if (five[0] == '1' && five[1]=='1')
		num = (0 + (five[2] - 48) * 2 + (five[3] - 48) * 1 + (five[4] - 48) * 0); // ascii trick
	else
		num = ((five[0] - 48) * 7 + (five[1] - 48) * 4 + (five[2] - 48) * 2 + (five[3] - 48) * 1 + (five[4] - 48) * 0);
	return num;
}

//prints the integer format of the input
int zipCode::getIntFormat() {
	string substr1 = barCode.substr(1, 5);
	string substr2 = barCode.substr(6, 5);
	string substr3 = barCode.substr(11, 5);
	string substr4 = barCode.substr(16, 5);
	string substr5 = barCode.substr(21, 5);
	int digit1 = convertOneGroup(substr1);
	int digit2 = convertOneGroup(substr2);
	int digit3 = convertOneGroup(substr3);
	int digit4 = convertOneGroup(substr4);
	int digit5 = convertOneGroup(substr5);
	int num = 10000 * digit1 + 1000 * digit2 + 100 * digit3 + 10 * digit4 + digit5;
	return num;
}


int main(){
	string barCode; // switch for int type to test the other constructor
	cout << "A bar code consists only of 1s and 0s." << endl;
	cout << "The first and last digits must be exactly 1." << endl;
	cout << "The remaining 25 digits must have exactly two 1s in each group of five digits." << endl;
	cout << "Enter your bar code:";
	cin >> barCode;
	zipCode z(barCode);
	if (z.getBarCode()[0] == '0')
	{
		system("Pause");
		return 1;
	}
	else
		cout << "The bar code: " << z.getBarCode() << " decodes to " << setfill('0') << setw(5) << z.getIntFormat() << endl;
	system("Pause");
	return 0;
}