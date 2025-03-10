// Test 4.3 ----- Test File_Error fstream exceptions
void test_file_fstream(std::string path, std::fstream *file)
{
    // exception handling        
    if(!(*file).is_open())
    {
        throw File_Error(path,"Error in opening the file!");
    }
    
    // exit
    return; 
}