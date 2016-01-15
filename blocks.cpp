int main() {
    {
	// first x
	int x = 5;
	{
	    int y = 5;
	    // I see you
	    x = 6;
	}
    }

    {
	// second x
	int x = 5;
    }

    // yet another x
    for (int x = 5; x < 10; x++) {
	x = 42;
    }
}