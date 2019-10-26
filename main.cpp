#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include "Output_dictionary.h"
using namespace std;

DATA newItem;


void print(DATA ss){
    ofstream outFile;
    outFile.open("G:\\\\Elias Ennebt 18391679 DSA 2\\\\Elias Ennebt 18391679 DSA 2 copy 2\\\\Dictionary.txt", fstream :: app );
    if(outFile.is_open()){
        outFile << ss.key << " = " << ss.age << endl;
        cout << ss.key << "= " << ss.age << endl;


    }

}
int counter;
dictionary dictionary1;
void  Deleter(DATA ss){
    double value;


    if(counter == 0){
        cin >> value1;
    }

    counter++;
    double num1 = double(ss.age);
    double num2 = double(ss.counter);
    value = (num1 /num2)* 1000;


    if(value > value1){
        cout << ss.key << ":  " << "( "<< value << " Per Thousand words )"<< endl;
        dictionary1.c++;

    }else {
        dictionary1.DELETEKEY.push(ss.key);

    }




}

int main() {

    int x;

    cout << " ================================ " << endl;
    cout << " pick a choice " << endl;
    cout << "  load dictionary 1: " << endl;
    cout << " print 2:" << endl;
    cout << " Phrases  3:" << endl;
    cout << " DELETE  4:" << endl;
    cout << " WORDSEARCH  5:" << endl;
    cout << " FILE ADDRESSES 6:" << endl;
    cout << " PRINT TREEE 7:" << endl;
    cout << " READ DICTIONARY 8:" << endl;
    cout << " INDEXING 9 :" << endl;
    cout << " EXIT 0: " << endl;
    cout << " ================================ " << endl;
    cin >> x;

    ifstream ifstream1;

ifstream1.open ("G:\\\\Elias Ennebt 18391679 DSA 2\\\\Elias Ennebt 18391679 DSA 2 copy 2\\\\Dictionary.txt", fstream ::app);


    do {

        switch (x) {

            case 1:
                dictionary1.readTextFile(newItem);
                break;
            case 2:

                dictionary1.AVL_Traverse(print);
                break;
            case 3:
                dictionary1.phrases(newItem);
                dictionary1.AVL_Traverse(print);
                break;
            case 4:
                cout << "Input a Threshold (say 0.5 ptw ) "<< endl;
               dictionary1.AVL_Traverse(Deleter);
               dictionary1.total();
               dictionary1.DELETE();
                break;
            case 5:
                dictionary1.wordsearch(newItem);
                break;

            case 6:
                dictionary1.Address(newItem);
                break;
            case 7:
                dictionary1.AVL_Print();
                break;
            case 8:
                dictionary1.read(ifstream1, newItem);
                dictionary1.AVL_Print();
                break;
            case 0:
                return 0;
            default:
                cout << "wrong input sorry try again " << endl;

        }

        cout << " ================================ " << endl;
        cout << " pick a choice " << endl;
        cout << "  load dictionary 1: " << endl;
        cout << " print 2:" << endl;
        cout << " Phrases  3:" << endl;
        cout << " DELETE  4:" << endl;
        cout << " WORDSEARCH  5:" << endl;
        cout << " FILE ADDRESSES 6:" << endl;
        cout << " PRINT TREEE 7:" << endl;
        cout << " READ DICTIONARY 8:" << endl;
        cout << " EXIT 0" << endl;
        cout << " ================================ " << endl;
        cin >> x;

    } while (x < 10 );



    return 0;
}


