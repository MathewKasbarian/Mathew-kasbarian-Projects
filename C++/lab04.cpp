#include <iostream>

#include <cmath>

using namespace std;

const int numFactories = 3;//varible never changes and is the amount of factories


//declaring all the functions in the program
void plantNum(int a[], int factoryRange);
void unitToThous(int a[], int indexRange);
void graphUni(const int anArray[], int factoryRange);
void unitProductionNum(int& sum);
int roundNum(double number); 
void outputGraph(int graphRange);

int main( ) //main function
{
	int production[numFactories];

    cout << "This program displays a graph showing production " << endl;
	cout << "for each factory in the company. " << endl;
	plantNum(production, numFactories);
	unitToThous(production, numFactories);
	graphUni(production, numFactories);

    return 0;

} 

//lets user input the numcer of factories set
void plantNum(int a[], int factoryRange)
{

    for (int i = 1; i <= factoryRange; i++)

    {
		cout << "Enter production data for plant number " << i << endl;

        unitProductionNum(a[i - 1]);
	}
}

//user inputs the total amount of units produced in each	
void unitProductionNum(int& sum) 
{
	cout << "Enter number of units produced by each department, in thounsads. " << endl;
	cout << "Append a negative number to the end of the list." << endl;

    sum = 0; 
	
	//inputting first value
	int next;
	cin >> next;

    while (next >= 0) 
	{
		sum = sum + next;
		cin >> next;
    } 
	
	cout << "Total = " << sum << endl;

}

//converts the units to thounsads
void unitToThous(int a[], int indexRange)
{
	for (int i = 0; i < indexRange; i++) 
	{
	a[i] = roundNum(a[i]/1000.0);
	}

}

//basically just rounding the amount of units produced inputed by the user
int roundNum(double number) 
{
	return static_cast<int>(floor(number + 0.5));
}

//outputing the amount of factories  
void graphUni(const int anArray[], int factoryRange)
{
	cout << "Units produced in thousands of units: " << endl;

    for (int i = 1; i <= factoryRange; i++)
	{
		cout << "Factory #" << i << " ";
		outputGraph(anArray[i - 1]);
		cout << endl;
    }
}

//displays the amount of units produceded in thousands as *
void outputGraph(int graphRange) 
{
	for (int i = 1; i <= graphRange; i++)
	{
		cout << "*";
	}
}