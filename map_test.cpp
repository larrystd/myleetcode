#include <map>
#include <iostream>
#include <unordered_map>
using namespace std;

class A {
public:
    void setA(int x) {
        cout << "set A" << x << "\n";
    }
};

int test(int a)
{
    cout << "A" << a << "\n";
}

int main(){
    int (*fp)(int a);
    fp=test;
    fp(20);
    //void (A::*p) (int) = &A::setA;
    A a;
    void (A::*fa)(int);
    fa = &A::setA;
    (a.*fa)(10000);

    map<int,int> mp;
    mp[0] = 1;
    cout << mp[0]<<endl;
    cout << mp[1]<<endl;    // 索引直接默认0

    unordered_map<int,int> unorder_mp;
    cout<< unorder_mp[1]<<endl;
    return 0;
}