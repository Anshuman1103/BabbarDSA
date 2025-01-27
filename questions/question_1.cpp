#include<iostream>
#include<climits>
using namespace std;

/*Suppose given ₹1330 , find how many 100, 50, 20 and 10 rupees note are needed in order to make it */

int main(){

    int amount;
    cin >> amount;
    int h = 0, f = 0, t = 0, ten = 0 ;

    while (amount != 0)
    {
        switch (amount) {
            case 100 ... INT_MAX:
                h++;
                amount -= 100;
                break;
            case 50 ... 99:
                f++;
                amount -= 50;
                break;
            case 20 ... 49:
                t++;
                amount -= 20;
                break;
            case 10 ... 19:
                ten++;
                amount -= 10;
                break;
            default:
                // In case the amount is less than the smallest note denomination (e.g., not divisible by 10)
                cout << "Amount cannot be broken down into the specified denominations." << endl;
                return 1; // Exiting with an error code
        }
    }

    cout <<"The notes required are: "<< endl;
    cout << "100 notes = " << h << endl;
    cout << "50 notes = " << f << endl;
    cout << "20 notes = " << t << endl;
    cout << "10 notes = " << ten << endl;
    
}