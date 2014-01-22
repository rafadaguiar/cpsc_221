#include <iostream>

using namespace std;

void ToH(int dskToMv, char cLocation, char tmpLocation, char fLocation)
{
    if( dskToMv != 0 ) 
    {
        ToH( dskToMv-1, cLocation, fLocation, tmpLocation );
        cout << "Move disk from peg " << cLocation << " to peg " << fLocation << endl;
        ToH( dskToMv-1, tmpLocation, cLocation, fLocation );
    }
}

int main()
{
    int x;
    cout << "Enter number of disks: ";
    cin >> x;
    ToH(x, 'A', 'B', 'C');
    return 0;
}