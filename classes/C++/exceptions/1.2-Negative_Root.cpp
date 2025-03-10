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