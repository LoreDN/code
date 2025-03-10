// Test 4.1 ----- Test File_Error ifstream exceptions
void test_file_ifstream(std::string path, std::ifstream *file)
{
    // exception handling        
    if(!(*file).is_open())
    {
        throw File_Error(path,"Error in opening the file!");
    }
    
    // exit
    return; 
}