// Sum of two Vectors
template <typename Type> void vector_sum(Vector<Type> &v1, Vector<Type> &v2)
{    
    // Vector sum initialization
    Vector<Type> sum(v1.size());
    
    // check the size
    if(v1.size() != v2.size())
    {
        std::cout << "\nError: Vectors have different sizes!\n" << std::endl;
        
        // exit
        return;
    }

    // calculate the sum
    std::cout << "\n\nCalculating the Sum of the two Vectors..." << std::endl;
    for(int i = 0; i < v1.size(); i++)
    {
        sum.set((v1.get(i) + v2.get(i)), i);
    }
    std::cout << "Vector Sum has been calculated!" << std::endl;

    // print the sum
    sum.print();

    // exit
    return;
}