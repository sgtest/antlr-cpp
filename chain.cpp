// testing chains of postfix expressions

namespace {

    class B;

    class A {

	public:

	B* foo;

	A() {}
	virtual ~A() {}

	B *bar() { return foo; }
	
    };    

    class B {

	public:

	A foo;

	int q;

	// testing member initializers as well
	B() : foo(), q(5) {}
	A bar() { return foo; }
	
    };

    class C : public A {};
}

int main() {
    A a;
    a.foo->foo.bar()->bar().foo;
    B().foo.foo->bar().bar()->foo;
    // TODO: not supported yet
    (new B())->foo.foo;

    // also testing "foo& bar"
    A& c = a;
    dynamic_cast<C&>(c).foo;
}