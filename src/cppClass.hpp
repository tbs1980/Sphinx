#ifndef CPP_CLASS_HPP
#define CPP_CLASS_HPP

/*!
* \namespace cppclass
* \brief this namesapce defines all the classes for this documentation
*/
namespace cppclass
{

    /*!
    * \class cppClass
    * \brief a test class for Sphinx documentation
    *
    * \tparam _realType a template argument
    */
    template<typename _realType>
    class cppClass
    {
    public:

        /*!
        * \typedef _realType realType
        * \brief defines a floating point type
        */
        typedef _realType realType;


        /*!
        * \brief The default constructor
        */
        cppClass()
        {

        }

        /*!
        * \brief a fuction for setting the value of the private member
        * \param a value the private member to be set
        */
        void setA(realType a)
        {
            m_a = a;
        }

        /*!
        * \brief a function that returns the private member
        * \return value of a
        */
        realType getA(void) const
        {
            return a
        }

    private:

        realType m_a; /*!< a private member */
    };
}

#endif //CPP_CLASS_HPP
