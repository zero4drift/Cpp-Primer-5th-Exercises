// function make_shared behaves almost like emplace_back illustrated in section 16.4.3;

#include <memory>

using std::shared_ptr;

template <typename T, typename... Args>
shared_ptr<T> my_make_shared(Args&&... args)
{
  return shared_ptr<T>(new T(std::forward<Args>(args)...));
}
