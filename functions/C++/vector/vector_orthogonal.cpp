// Check the orthogonality of two Vectors
template <typename Type> bool vector_orthogonal(Vector<Type> &v1, Vector<Type> &v2)
{
    // check the orthogonality
    if(vector_scalar_product(v1, v2) == 0)
    {
        return true;
    }

    // exit
    return false;
}