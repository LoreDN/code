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