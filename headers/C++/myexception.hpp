#include <iostream>
#include <type_traits>
#include <cmath>
#include <fstream>


// Root ----- abstract class MyException
class MyException {

    protected:

        // error message attribute
        std::string message;

    public:

        // constructor
        MyException(std::string msg) : message(msg) {}

        // method 1 ----- print error message
        virtual void print() = 0;
};


// Exception 1 ----- abstract class Math_Error
template <typename Type, typename = std::enable_if_t<
    (std::is_integral_v<Type> && !std::is_same_v<Type, char> && !std::is_same_v<Type, bool>) || std::is_floating_point_v<Type>
>> class Math_Error : public MyException {

    protected:

        // expression value attribute
        Type value;

    public:

        // constructor
        Math_Error(Type x, std::string msg) : value(x), MyException(msg) {}

        // method 1 ----- get the value
        virtual Type get() = 0;
};


// Exception 1.1 ----- Zero_Division
class Zero_Division : public Math_Error<float> {

    public:

        // constructor
        Zero_Division(std::string msg) : Math_Error(0,msg) {}

        // copy constructor
        Zero_Division(Zero_Division &other) : Math_Error(other.value, other.message) {}

        // = operator
        void operator=(Zero_Division &other)
        {
            MyException::message = other.message;
            Math_Error::value = other.value;

            //exit
            return;
        }

        // method 1 ----- get message
        float get() override
        {
            return Math_Error::value;
        }

        // method 2 ----- print message
        void print() override
        {
            std::cout << "Division by Zero Exception!!!\n" << MyException::message << "\nThe operation has returned the value: " << Math_Error::value << "!!!" << std::endl;

            // exit
            return;
        }     
};


// Exception 1.2 ----- Negative_Root
class Negative_Root : public Math_Error<float> {

    public:

        // constructor
        Negative_Root(float x, std::string msg) : Math_Error(abs(x),msg) {}

        // copy constructor
        Negative_Root(Negative_Root &other) : Math_Error(other.value, other.message) {}

        // = operator
        void operator=(Negative_Root &other)
        {
            MyException::message = other.message;
            Math_Error::value = other.value;

            //exit
            return;
        }

        // method 1 ----- get message
        float get() override
        {
            return Math_Error::value;
        }

        // method 2 ----- print message
        void print() override
        {
            std::cout << "Negative Root Exception!!!\n" << MyException::message << "\nThe operation has returned the value: " << Math_Error::value << "!!!" << std::endl;

            // exit
            return;
        }     
};


// Exception 2 ----- Invalid_Index
class Invalid_Index : public MyException {

    public:

        // constructor
        Invalid_Index(std::string msg) : MyException(msg) {}

        // copy constructor
        Invalid_Index(Invalid_Index &other) : MyException(other.message) {}

        // = operator
        void operator=(Invalid_Index &other)
        {
            MyException::message = other.message;

            // exit
            return;
        }

        // method 1 ----- print error message
        void print() override
        {
            std::cout << "Invalid Index Exception!!!\n" << MyException::message << std::endl;

            // exit
            return;
        }        
};


// Exception 3 ----- Null_Pointer
class Null_Pointer : public MyException {

   public:

        // constructor
        Null_Pointer(std::string msg) : MyException(msg) {}

        // copy constructor
        Null_Pointer(Null_Pointer &other) : MyException(other.message) {}

        // = operator
        void operator=(Null_Pointer &other)
        {
            MyException::message = other.message;

            // exit
            return;
        }

        // method 1 ----- print error message
        void print() override
        {
            std::cout << "Null Pointer Exception!!!\n" << MyException::message << std::endl;

            // exit
            return;
        }   
};


// Exception 4 ----- File_Error
class File_Error : public MyException {

    protected:

        // file path attribute
        std::string path;
    
    public:

        // constructor
        File_Error(std::string p, std::string msg) : path(p), MyException(msg) {}

        // copy constructor
        File_Error(File_Error &other) : path(other.path) , MyException(other.message) {}

        // = operator
        void operator=(File_Error &other)
        {
            this->path = other.path;
            MyException::message = other.message;

            // exit
            return;
        }

        // method 1 ----- print error message
        void print() override
        {
            std::cout << "File Exception!!!\n" << MyException::message << "\nFile path: " << this->path <<  std::endl;

            // exit
            return;
        }     
};


// prototype Test 1
void test_division(float const denominator);
void test_root(float const value);

// prototype Test 2
void test_index(int index, int size);

// prototype Test 3
template <typename Type> void test_pointer(Type pointer);

// prototype Test 4
void test_file_ifstream(std::string path, std::ifstream *file);
void test_file_ofstream(std::string path, std::ofstream *file);
void test_file_fstream(std::string path, std::fstream *file);


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