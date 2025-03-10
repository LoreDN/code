#include </media/lorenzo/Work/code/headers/C++/myexception.hpp>


// Vector template class
template <typename Type, typename = std::enable_if_t<
    (std::is_integral_v<Type> && !std::is_same_v<Type, char> && !std::is_same_v<Type, bool>) || std::is_floating_point_v<Type>
>> class Vector {

    // members declaration
    Type* vector;
    int dim;

    public:

        // constructor
        Vector(int size)
        {
            // initialize the variables
            this->dim = size;
            this->vector = new Type[this->dim];

            // set the Vector to 0
            for(int i = 0; i < this->dim; i++)
            {
                this->vector[i] = 0;
            }
        }

        // destructor
        ~Vector()
        {
            // delete the Vector
            delete[] this->vector;
        }

        // Method 1 ----- Scan the Vector
        void scan()
        {
            // scan the elements of the Vector
            std::cout << "\n\nScan the Vector:" << std::endl;
            for(int i = 0; i < this->dim; i++)
            {
                std::cout << "Element " << i + 1 << ": ";
                std::cin >> this->vector[i];
            }

            // exit
            return;
        }

        // Method 2 ----- Scan from a file
        void scan_file(std::string path)
        {
            // open the file
            std::ifstream file(path);
            
            // handle file exception
            try {
                test_file_ifstream(path, &file);
            } catch (File_Error &error) {
                error.print();

                // exit
                exit(-1);
            }

            // scan the size of the Vector
            file >> this->dim;

            // allocate the Vector
            delete[] this->vector;
            this->vector = new Type[this->dim];

            // scan the elements of the Vector
            std::cout << "\n\nScan the Vector from the file " << path << "..." << std::endl;
            for(int i = 0; i < this->dim; i++)
            {
                file >> this->vector[i];
            }
            std::cout << "Vector has been scanned!" << std::endl;

            // close the file
            file.close();

            // exit
            return;
        }    

        // Method 3 ----- Set an element
        void set(Type const element, int const index)
        {
            // handle index exception
            try {
                test_index(index, this->dim);
            } catch(Invalid_Index &error) {
                error.print();

                // exit
                return;
            } 

            // set the element
            this->vector[index] = element;

            // exit
            return;
        }

        // Method 4 ----- Print the Vector
        void print()
        {
            // print the elements of the Vector
            std::cout << "\n\nPrint the Vector:" << std::endl;
            for(int i = 0; i < this->dim; i++)
            {
                std::cout << "Element " << i + 1 << ": " << this->vector[i] << std::endl;
            }

            // exit
            return;
        }

        // Method 5 ----- Print to a file
        void print_file(std::string path)
        {
            // open the file
            std::ofstream file(path);
            
            // handle file exception
            try {
                test_file_ofstream(path, &file);
            } catch (File_Error &error) {
                error.print();

                // exit
                exit(-1);
            }

            // print the size of the Vector
            file << this->dim << std::endl;

            // print the elements of the Vector
            std::cout << "\n\nPrint the Vector to the file " << path << "..." << std::endl;
            for(int i = 0; i < this->dim; i++)
            {
                file << this->vector[i] << std::endl;
            }
            std::cout << "Vector has been printed!" << std::endl;

            // close the file
            file.close();

            // exit
            return;
        }

        // Method 6 ----- Check if the Vector is a null Vector
        bool is_null()
        {
            // check the null Vector
            for(int i = 0; i < this->dim ; i++)
            {
                if(this->vector[i] != 0)
                {
                    return false;
                }
            }

            // exit
            return true;
        }

        // Method 7 ----- Get an element
        Type get(int const index)
        {
            // handle index exception
            try {
                test_index(index, this->dim);
            } catch(Invalid_Index &error) {
                error.print();

                // exit
                return 0;
            } 
            
            // get the element
            return this->vector[index];
        }

        // Method 8 ----- Get a pointer to the elements
        Type* data()
        {
            return vector;
        }

        // Method 9 ----- Get the size of the Vector
        int size()
        {
            return this->dim;
        }

        // Method 10 ----- Resize the Vector
        void resize(int const newsize)
        {
            // allocate new Vector
            Type* newvector = new Type[newsize];

            // copy the elements
            for(int i = 0; i < this->dim && i < newsize; i++)
            {
                newvector[i] = this->vector[i];
            }

            // set new elements to 0
            for(int i = this->dim; i < newsize; i++)
            {
                newvector[i] = 0;
            }

            // deallocate old Vector
            delete[] this->vector;

            // set the new Vector
            this->dim = newsize;
            this->vector = newvector;

            // exit
            return;
        }
        
        // Method 11 ----- Counting the occurrences of an element
        int count(Type const element)
        {
            // counter declaration
            int counter = 0;
            
            // count the occurrences
            for(int i = 0; i < this->dim; i++)
            {
                if(this->vector[i] == element)
                {
                    counter++;
                }
            }

            // exit
            return counter;
        }

        // Method 12 ----- Swap two elements
        void swap(int const index1, int const index2)
        {
            // handle index1 exception
            try {
                test_index(index1, this->dim);
            } catch(Invalid_Index &error) {
                std::cout << "\nIndex 1:\n" << std::endl;
                error.print();

                // exit
                return;
            }

            // handle index2 exception
            try {
                test_index(index2, this->dim);
            } catch(Invalid_Index &error) {
                std::cout << "\nIndex 2:\n" << std::endl;
                error.print();

                // exit
                return;
            }          

            // swap the elements
            Type temp = this->vector[index1];
            this->vector[index1] = this->vector[index2];
            this->vector[index2] = temp;

            // exit
            return;
        }

        // Method 13 ----- Sort the Vector
        void sort()
        {
            // sort the Vector
            std::cout << "\nStart of the Bubble Sort..." << std::endl;
            for(int i = 0; i < this->dim - 1; i++)
            {
                for(int j = 0; j < this->dim - i - 1; j++)
                {
                    if(this->vector[j] > this->vector[j+1])
                    {
                        this->swap(j,j + 1);
                    }
                }
            }
            std::cout << "Vector has been Sorted!" << std::endl;
            
            // exit
            return;
        }

        // Method 14 ----- Check if sorted
        bool is_sorted()
        {
            // check the elements order
            for(int i = 0; i < this->dim - 1; i++)
            {
                if(this->vector[i] > this->vector[i + 1])
                {
                    return false;
                }
            }

            // exit
            return true;
        }

        // Method 15 ----- Reverse the Vector
        void reverse()
        {
            // reverse the Vector
            std::cout << "\nReversing the Vector..." << std::endl;
            for(int i = 0; i < this->dim / 2; i++)
            {
                this->swap(i, this->dim - 1 - i);
            }
            std::cout << "Vector has been Reversed!" << std::endl;

            // exit
            return;
        }

        // Method 16 ----- Scalar multiplication of the Vector
        void scalar_multiplication(Type scalar)
        {
            // calculate the scalar multiplication
            std::cout << "\n\nCalculating the Scalar Multiplication between the Vector and " << scalar << "..." << std::endl;
            for(int i = 0; i < this->dim; i++)
            {
                this->set((this->vector[i] * scalar), i);
            }
            std::cout << "Vector has been multiplied by " << scalar << "!" << std::endl;

            // exit
            return;
        }

        // Method 17 ----- Norm of the Vector
        float norm()
        {
            // norm declaration
            float norm = 0;
            
            // calculate the norm
            for(int i = 0; i < this->dim; i++)
            {
                norm += pow(this->vector[i], 2);
            }
            norm = sqrt(norm);

            // exit
            return norm;
        }

        // Method 18 ----- Normalize the Vector
        void normalize()
        {
            // divide by the norm
            std::cout << "\n\nNormalizing the Vector..." << std::endl;
            this->scalar_multiplication(1/norm());
            std::cout << "Vector has been Normalized!" << std::endl;

            // exit
            return;
        }

        // Method 19 ----- Check if the Vector is normalized
        bool is_normalized()
        {
            // variables declaration
            const float tolerance = 1e-6;

            // check the norm with tolerance
            if(std::abs(this->norm() - 1.0) < tolerance)
            {
                return true;
            }
            
            // exit
            return false;
        }
};


// prototypes
template <typename Type> bool vector_equal(Vector<Type> &v1, Vector<Type> &v2);
template <typename Type> void vector_sum(Vector<Type> &v1, Vector<Type> &v2);
template <typename Type> Type vector_scalar_product(Vector<Type> &v1, Vector<Type> &v2);
template <typename Type> bool vector_orthogonal(Vector<Type> &v1, Vector<Type> &v2);
template <typename Type> bool vector_orthonormal(Vector<Type> &v1, Vector<Type> &v2);


// 1 ----- Check the equality of two Vectors
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


// 2 ----- Sum of two Vectors
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


// 3 ----- Scalar product of two Vectors
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


// 4 ----- Check the orthogonality of two Vectors
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


// 5 ----- Check the orthonormality of two Vectors
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