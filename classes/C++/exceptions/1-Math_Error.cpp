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