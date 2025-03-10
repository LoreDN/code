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