// No;
// explicit instantiation of 'template <typename T> vector<T>' would instantiates every member of this class;
// for some constructors of class vector<T> would call class T's default constructor, this requiers that type T owns a default constructor;
// if there is no default constructor defined within class NoDefault, corresponding constructor as member function could not be instantiated;
// then this explicit instantiation failed.
