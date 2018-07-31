#include <exception>
#include <stdexcept>
#include <new>
#include <typeinfo>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
  try
    {
      // ...
    }
  catch(length_error e)
    {
      cerr << e.what() << endl;
      abort(); 
    }
  catch(invalid_argument e)
    {
      cerr << e.what() << endl;
      abort(); 
    }
  catch(out_of_range e)
    {
      cerr << e.what() << endl;
      abort(); 
    }
  catch(domain_error e)
    {
      cerr << e.what() << endl;
      abort(); 
    }
  catch(range_error e)
    {
      cerr << e.what() << endl;
      abort(); 
    }
  catch(underflow_error e)
    {
      cerr << e.what() << endl;
      abort(); 
    }
  catch(overflow_error e)
    {
      cerr << e.what() << endl;
      abort(); 
    }
  catch(logic_error e)
    {
      cerr << e.what() << endl;
      abort(); 
    }
  catch(runtime_error e)
    {
      cerr << e.what() << endl;
      abort(); 
    }
  catch(bad_cast e)
    {
      cerr << e.what() << endl;
      abort(); 
    }
  catch(bad_alloc e)
    {
      cerr << e.what() << endl;
      abort(); 
    }
  catch(exception e)
    {
      cerr << e.what() << endl;
      abort(); 
    }
}
