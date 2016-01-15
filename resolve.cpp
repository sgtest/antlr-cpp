namespace {

    void globalfn() {}

    class A {
        public:
        int amember;
        void amethod() {}

        static void staticmethod() {}

        static int staticmember;

    };

    class B : public A {
        public:
        int bmember;
        void bmethod() { 
    	// global ref
	    globalfn(); 
	    // ref to current class member
	    bmember = 1; 
	    // ref to parent class member
	    amember = 2; 
	    // ref to current class method, shorthand
	    bmethod();
	    // ref to parent class method, shorthand
	    amethod(); 
	    // ref to parent class member with this
	    this->amethod();
        }
    };

}

// ref to static member
int A::staticmember = 0;

int main() {
    B b;
    // ref to current class method
    b.bmethod();
    // ref to parent class method
    b.amethod();
    // ref to current class member
    b.bmember;
    // ref to parent class member
    b.amember;
    // global function
    globalfn();

    // ref to static method
    A::staticmethod();
    // ref to static method of parent class
    B::staticmethod();

    // ref to static member
    A::staticmember = 1;

    // ref to static member of parent class
    B::staticmember = 2;
}
