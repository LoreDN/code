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