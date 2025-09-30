#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    float a[20];
    srand(static_cast<unsigned>(time(0)));
    cout<<"Заданий масив: ";
    for (int i=0; i<20; ++i) {
        a[i] = static_cast<double>(rand()) / RAND_MAX * 100.0;
        cout << a[i] << " ";
    }
    float min=a[0];
    for (int i=0; i<20; ++i) {
        if(min>a[i]) min=a[i];
    }
    cout<<endl<<"Мінімальний елемент масиву: "<<min;
}