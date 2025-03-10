// Test 4.2 ----- Test File_Error ofstream exceptions
void test_file_ofstream(std::string path, std::ofstream *file)
{
    // exception handling        
    if(!(*file).is_open())
    {
        throw File_Error(path,"Error in opening the file!");
    }
    
    // exit
    return; 
}