// Check the orthonormality of two Vectors
template <typename Type> bool vector_orthonormal(Vector<Type> &v1, Vector<Type> &v2)
{
    // check the orthonormality
    if(v1.is_normalized() && v2.is_normalized() && vector_orthogonal(v1, v2))
    {
        return true;
    }

    // exit
    return false;
}