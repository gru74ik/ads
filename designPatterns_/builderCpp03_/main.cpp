// The Builder separates the creation of the object from its representation
#include <iostream>
#include <string>
#include <vector>

class HTMLElement {
public:
    HTMLElement(
        const std::string & name,
        const std::string & text)
        : name_(name), text_(text) {}
private:
    friend class HTMLBuilder;
    std::string name_;
    std::string text_;
    std::vector<HTMLElement> children_;
};

class HTMLBuilder {
public:
    explicit HTMLBuilder(
        const std::string & name,
        const std::string & text = "")
        : root_(name, text) {}

    HTMLBuilder & add_child(
        const std::string & name,
        const std::string & text) {
        root_.children_.push_back(HTMLElement(name, text));
        return *this;
    }

    operator HTMLElement() const { return root_; }
private:
    HTMLElement root_;
};

int main()
{
    HTMLElement el = HTMLBuilder("ul").
            add_child("li", "item1").
            add_child("li", "item2");
}
