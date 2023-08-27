#include <iostream>
#include "Varparm.h"

using namespace std;
using namespace Varparm;

void main()
{
    setlocale(LC_ALL, "RU");

    int ivarparm1, ivarparm2, ivarparm3, ivarparm4;
   
    ivarparm1 = ivarparm(0);
    ivarparm2 = ivarparm(1, 3);
    ivarparm3 = ivarparm(2, 5, 6);
    ivarparm4 = ivarparm(6, 8, 9, 10, 11, 12, 13);

    cout << "Функция ivarparm:\n";
    cout << "\nivarparm 1 = " << ivarparm1;
    cout << "\nivarparm 2 = " << ivarparm2;
    cout << "\nivarparm 3 = " << ivarparm3;
    cout << "\nivarparm 4 = " << ivarparm4;

    int svarparm1, svarparm2, svarparm3, svarparm4;
    
    svarparm1 = svarparm(0);
    svarparm2 = svarparm(1, 3);
    svarparm3 = svarparm(2, 5, 6);
    svarparm4 = svarparm(6, 8, 9, 10, 11, 12, 13);;

    cout << "\n\nФункция svarparm:\n";
    cout << "\nsvarparm 1 = " << svarparm1;
    cout << "\nsvarparm 2 = " << svarparm2;
    cout << "\nsvarparm 3 = " << svarparm3;
    cout << "\nsvarparm 4 = " << svarparm4;


    double fvarparm1, fvarparm2, fvarparm3, fvarparm4;

    fvarparm1 = fvarparm(FLT_MAX);
    fvarparm2 = fvarparm(1.75, FLT_MAX);
    fvarparm3 = fvarparm(2.0, 8.94, FLT_MAX);
    fvarparm4 = fvarparm(3.14, 5.56, 101.15, 7.6, 8.24, 15.2, FLT_MAX);

    cout << "\n\nФункция fvarparm:\n";
    cout << "\nfvarparm 1 = " << fvarparm1;
    cout << "\nfvarparm 2 = " << fvarparm2;
    cout << "\nfvarparm 3 = " << fvarparm3;
    cout << "\nfvarparm 4 = " << fvarparm4;

    double dvarparm1, dvarparm2, dvarparm3, dvarparm4;
    
    dvarparm1 = dvarparm(DBL_MAX);
    dvarparm2 = dvarparm(1.75, DBL_MAX);
    dvarparm3 = dvarparm(2.0, 8.94, DBL_MAX);
    dvarparm4 = dvarparm(3.14, 5.56, 101.15, 7.6, 8.24, 15.2, DBL_MAX);

    cout << "\n\nФункция dvarparm:\n";
    cout << "\ndvarparm 1 = " << dvarparm1;
    cout << "\ndvarparm 2 = " << dvarparm2;
    cout << "\ndvarparm 3 = " << dvarparm3;
    cout << "\ndvarparm 4 = " << dvarparm4;
}