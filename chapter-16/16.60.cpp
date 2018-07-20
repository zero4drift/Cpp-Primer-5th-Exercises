// function make_shared behaves almost like emplace_back illustrated in section 16.4.3;
// make_shared should be a variadic template function that forwards all arguments to underlying constructors that allocate and initializes an object in dynamic memroy and build a shared_ptr by wrapping the raw pointer.

#include <memory>

using std::shared_ptr;

template <typename T, typename... Args>
shared_ptr<T> my_make_shared(Args&&... args)
{
  return shared_ptr<T>(new T(std::forward<Args>(args)...));
}
