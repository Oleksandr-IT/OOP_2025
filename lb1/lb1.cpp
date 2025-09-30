#include <iostream>
#include <fstream>
#include <cstdlib> // Для rand() і srand()
#include <ctime> // Для time()

using namespace std;

void taskMenu(){
    cout<<"=== МЕНЮ ==="<<endl;
    cout<<"1. Завдання 1" <<endl;
    cout<<"2. Завдання 2" <<endl;
    cout<<"3. Завдання 3" <<endl;
    cout<<"0. Вихід" << endl;
    cout<<"Ведіть число(1-3, 0): ";
}

int a()
{
    int k=0, N;
    cout<<"Ведіть кількість елементів масиву: ";
    cin>>N; //N-кількість елементів масиву, що введе користувач з клавіатури
    int A[N];
    for(int r=0; r<N; r++){ //заповнення масиву з клавіатури
        cout<<"Ведіть елемент: ";
        cin>>A[r];
        if (A[r]==0) k++;
    }

    ofstream arr;
    arr.open("files/array1.txt");

    for(int i=0; i<N; i++){
        arr<<A[i]<<" ";
    }

    return k;
}

void b(){
    int n, a[n];
    ofstream arr2("files/array2.bin", ios::binary);
    cout<<"Ведіть кількість елементів масиву: ";
    cin>>n;
    size_t size = sizeof(a) / sizeof(a[0]);
    srand(time(nullptr));

    for (int i=0; i<n; ++i) {
        a[i] += rand() % 15; // Випадкові числа від 0 до 14
    }

    arr2.write(reinterpret_cast<const char*>(a), size * sizeof(int));
    arr2.close();
    cout<<"Масив записаний у бінарний файл!"<<endl;
}

int main()
{
    int choice;
    do{
        taskMenu();
        cin>>choice;

        switch(choice){
            case 1:
                cout<<endl<<"Ви обрали завдання 1"<<endl;
                //cout<<"*Функція A*"<<endl<<a()<<endl;
                cout<<"*Функція B*"<<endl; 
                b();
                break;
            case 2:
                cout<<"Ви обрали завдання 2"<<endl;
                break;
            case 3:
                cout<<"Ви обрали завдання 3"<<endl;
                break;
            case 0:
                cout<<"Вихід з програми..."<<endl;
                break;
            default:
                cout<<"Попробуйте знову!"<<endl;
        cout<<endl;
        }
    } while (choice != 0);

    return 0;
}