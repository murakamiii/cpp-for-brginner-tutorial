#ifndef my_container_h
#define my_container_h

#include <optional>
#include <vector>

namespace mystd
{
  int two();

  template <typename T> struct Stack
  {
    virtual ~Stack() {};
    virtual void push(T val);
    virtual std::optional<T> pop();
  };

  template <typename Element> struct VectorStack: Stack<Element> {
    VectorStack(std::vector<Element> container){};
    void push(Element ele);
    std::optional<Element> pop();
    private:
      std::vector<Element> container;
  };
}

#endif