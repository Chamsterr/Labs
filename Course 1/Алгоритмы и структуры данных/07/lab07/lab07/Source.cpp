#include <iostream>
using namespace std;

void hanoi(int i, int k, int n)
{
    if (n == 1) {
        cout << "Move disk 1 from pin " << i << " to pin " << k << ".\n";
    }
    else {
        int tmp = 6 - i - k;
        hanoi(i, tmp, n - 1);
        cout << "Move disk " << n << " from pin " << i << " to pin " << k << ".\n";
        hanoi(tmp, k, n - 1);
    }
}

int main()
{
    int n, i, k = 0;


    do
    {
        cout << "Choose start pin (1, 2, 3): ";
        cin >> i;

        cin.clear();
        cin.ignore(32767, '\n');
    } while (i != 1 &&  i != 2 && i != 3);

    do
    {
        cout << "Choose finish pin (remaining): ";
        cin >> k;

        cin.clear(); 
        cin.ignore(32767, '\n');
    } while (k == i || !(k == 1 or k == 2 or k == 3));

    do
    {
        cout << "How many disks: ";
        cin >> n;

        cin.clear();
        cin.ignore(32767, '\n');
    } while (n <= 0);

    hanoi(i, k , n);
    return 0;
}
