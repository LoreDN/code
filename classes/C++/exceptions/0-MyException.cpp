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