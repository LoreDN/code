// Test 1.2 ----- Test Negative_Root exceptions
void test_root(float const value)
{
    // exception handling        
    if(value < 0)
    { 
        throw Negative_Root(sqrt(abs(value)), "Square Root of a Negative Number!");
    }           

    // exit
    return;
}