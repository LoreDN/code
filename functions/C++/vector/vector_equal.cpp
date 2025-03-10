// Check the equality of two Vectors
template <typename Type> bool vector_equal(Vector<Type> &v1, Vector<Type> &v2)
{
    // check the size
    if(v1.size() != v2.size())
    {
        return false;
    }

    // check the elements
    for(int i = 0; i < v1.size(); i++)
    {
        if(v1.get(i) != v2.get(i))
        {
            return false;
        }
    }

    // successfull exit
    return true;
}