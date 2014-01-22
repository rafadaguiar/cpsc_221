#include <iostream>

using namespace std;

void hannoi_tower(int disk, char current, char temp, char target){
    if(disk != 0){
        hannoi_tower(disk-1, current, target, temp);
        cout << "Move disk from peg " << current << " to peg " << target << endl;
        hannoi_tower(disk-1, temp, current, target);
    }
}

int main(){
    int x;
    cout << "Enter number of disks: ";
    cin >> x;
    hannoi_tower(x, 'A', 'B', 'C');
    return 0;
}