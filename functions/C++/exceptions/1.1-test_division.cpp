// Test 1.1 ----- Test Zero_Division exceptions
void test_division(float const denominator)
{
    // exception handling        
    if(denominator == 0)
    {
        throw Zero_Division("Division by zero!");
    }           

    // exit
    return;
}