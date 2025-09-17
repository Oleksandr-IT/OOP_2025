#include <iostream>

using namespace std;

int main()
{
    int k=0, N, c;
    cout<<"Ведіть кількість елементів масиву: ";
    cin>>N; //N-кількість елементів масиву, що введе користувач з клавіатури
    int A[N];
    for(int r=0; r<N; r++){ //заповнення масиву з клавіатури
        cout<<"Ведіть елемент: ";
        cin>>c;
        A[r]+=c;
    }
    for(int i=0; i<4; i++){ //перевірка чи співпадає елемент з нулем
        if (A[i]==0) k++;
        else continue;
    }
    cout<<k;
}