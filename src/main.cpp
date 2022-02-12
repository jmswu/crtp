#include <cstdio>

template<typename T>
struct Base {
    void foo() {
        (static_cast<T*>(this))->foo();
    }
};

struct DerivedA : public Base<DerivedA> {
    void foo() {
        std::printf("Derived A foo\n");
    }
};

struct DerivedB : public Base<DerivedB> {
    void foo() {
        std::printf("Derived B foo\n");
    }
};

template<typename T>
void ProcessFoo(Base<T>* b) {
    b->foo();
};

int main() {
    auto foo_a = DerivedA();
    auto foo_b = DerivedB();
    ProcessFoo(&foo_a);
    ProcessFoo(&foo_b);

    return 0;
}