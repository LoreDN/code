// Scalar product of two Vectors
template <typename Type> Type vector_scalar_product(Vector<Type> &v1, Vector<Type> &v2)
{
    // scalar product declaration
    Type product = 0;
    
    // check the size
    if(v1.size() != v2.size())
    {
        std::cout << "\nError: Vectors have different sizes!\n" << std::endl;
        
        // exit
        return 0;
    }

    // calculate the scalar product
    for(int i = 0; i < v1.size(); i++)
    {
        product += v1.get(i) * v2.get(i);
    }

    // exit
    return product;
}