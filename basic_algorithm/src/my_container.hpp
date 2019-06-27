#ifndef my_container_hpp
#define my_container_hpp

#include <optional>
#include <vector>

namespace mystd
{
  template <typename T> struct Stack
  {
    virtual ~Stack() {};
    virtual void push(T val) = 0;
    virtual std::optional<T> pop() = 0;
  };

  template <typename Element> struct VectorStack : Stack<Element>
  {
    VectorStack(std::vector<Element> container)
      :container(container){}
    
    void push(Element ele)
    {
      container.push_back(ele);
    }

    std::optional<Element> pop() 
    {
      if (container.size() == 0)
      {
        return std::nullopt;
      }

      auto ele = container.back();
      container.pop_back();
      return ele;
    }

    private:
      std::vector<Element> container;
  };
} // namespace mystd

#endif