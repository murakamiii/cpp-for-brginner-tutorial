#ifndef my_container_hpp
#define my_container_hpp

#include <optional>
#include <vector>
#include <memory>

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

  template <typename Element> struct LinkedList
  {
    std::unique_ptr<LinkedList<Element>> next;
    const Element value;

    LinkedList(LinkedList<Element> next, Element value)
      :next(new LinkedList<Element>(next)), value(value){}
    LinkedList(std::unique_ptr<LinkedList<Element>> next, Element value)
      :next(std::move(next)), value(value){}
  };

  template <typename Element> struct LLStack : Stack<Element>
  {
    LLStack(): head(nullptr){}
    
    void push(Element ele)
    {
      head.reset(new LinkedList<Element>(std::move(head), ele));
    }

    std::optional<Element> pop() 
    {
      if (head == nullptr)
      {
        return std::nullopt;
      }
      auto ele = head->value;
      head = std::move(head->next);

      return ele;
    }

    private:
      std::unique_ptr<LinkedList<Element>> head;
  };
} // namespace mystd

#endif