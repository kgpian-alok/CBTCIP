#include <iostream>
using namespace std;
void calculator()
{
    double x, y, value;
    bool flag = true;//used if operation entered is wrong
    char operation;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;
    cout << "Enter the operation (+, -, *, /): ";
    cin >> operation;
    switch (operation)
    {
    case '+':
        value = x + y;
        break;
    case '-':
        value = x - y;
        break;
    case '*':
        value = x * y;
        break;
    case '/':
        value = x / y;
        break;
    default:
        flag = false;//changed flag value to print invalid later on this function
        break;
    }
    if (flag)//will execute if operator entered is valid
        cout << "\nHence, (" << x << ") " << operation << " (" << y << ") = " << value;
    else
        cout << "----------INVALID OPERATION----------";
}
int main()
{
    int check = 1;
    cout<<"\n--------------------WELCOME TO YOUR CALCULATOR--------------------\n\n";
    do
    {
        calculator();
        cout << "\n\nDo you want to use calculator again?\nEnter 1: YES\nEnter 0: NO\n";
        cin >> check;
    } while (check);
    cout << "--------------------THANKS FOR USING CALCULATOR--------------------";
    return 0;
}