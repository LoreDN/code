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