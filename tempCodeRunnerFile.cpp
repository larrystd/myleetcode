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