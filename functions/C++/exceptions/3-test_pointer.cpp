// Test 3 ----- Test Null_Pointer exceptions
template <typename Type> void test_pointer(Type pointer)
{
    // exception handling        
    if(pointer == NULL)
    {
        throw Null_Pointer("This pointer leads to NULL!");
    }
    
    // exit
    return;
}