// namespace tests

namespace RootNS {
    namespace L1 {
	namespace L2 {
	    class A {
		public:
	    
		static int m;

		void foo();
		void bar();
		void baz();
		void qux();
	    };
	}
    }
}

// rel path
namespace RootNS {
    void L1::L2::A::foo() {}

    int L1::L2::A::m = 1;
}


// abs path
void ::RootNS::L1::L2::A::bar() {
    ::RootNS::L1::L2::A::m = 2;
}

// still abs
void RootNS::L1::L2::A::qux() {
    RootNS::L1::L2::A::m = 3;
}

// local path
namespace RootNS {
    namespace L1 {
	namespace L2 {
	    void A::baz() {
		A::m = 4;
	    }
	}
    }
}

int main() {

    ::RootNS::L1::L2::A a;
    ::RootNS::L1::L2::A::m = 6;
    RootNS::L1::L2::A b;
    RootNS::L1::L2::A::m = 7;

    using namespace RootNS;
    L1::L2::A c;
    L1::L2::A::m = 8;

    using namespace RootNS::L1;
    L2::A d;
    L2::A::m = 9;

    using namespace RootNS::L1::L2;
    A e;
    A::m = 10;

    a.foo();
    b.bar();
    c.baz();
    d.qux();
    e.foo();

}


