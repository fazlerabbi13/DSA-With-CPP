#include<iostream>
using namespace std;

void TowerOfHanoi(int n, char from, char to, char aux){
    if(n == 1){
        cout << from << to << "\n";
        return;
    }
    TowerOfHanoi(n-1,from,aux,to);
    cout << n << from << to << "\n";
    TowerOfHanoi(n-1,aux,to,from);
}

int main(){
    int n;
    cin >> n;

    TowerOfHanoi(n,'A','C','B');
    return 0;
}