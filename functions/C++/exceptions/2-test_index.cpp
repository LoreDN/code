// Test 2 ----- Test Invalid_Index exceptions
void test_index(int index, int size)
{
    // exception handling        
    if(index < 0 || index >= size)
    {
        throw Invalid_Index("Index out of range!");
    }
    
    // exit
    return;
}