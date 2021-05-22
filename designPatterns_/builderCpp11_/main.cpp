// The Builder separates the creation of the object from its representation
#include <iostream>
#include <string>
#include <vector>

class HTMLElement {
public:
    HTMLElement(
        const std::string & name,
        const std::string & text = "")
        : name_(name), text_(text) {}

    HTMLElement(
        const std::string & name,
        const std::string & text,
        const std::vector<HTMLElement> && children)
        : name_(name)
        , text_(text)
        , children_(std::move(children)) {}

    friend std::ostream & operator<<(std::ostream & os, const HTMLElement & elem) {
        Write(os, elem, 0);
        return os;
    }

private:
    friend void Write(std::ostream& os, const HTMLElement& elem, size_t level) {
        const size_t indentWidth = 4;
        const std::string indent(level * indentWidth, ' ');
        os << indent << elem.name_ << " " << elem.text_ << "\n";
        for (const auto & child : elem.children_) {
            Write(os, child, level + 1);
        }
    }

    std::string name_;
    std::string text_;
    std::vector<HTMLElement> children_;
    static std::size_t identationLevel_;
};

struct UL : public HTMLElement {
    UL()
        : HTMLElement("ul") {}

    UL(std::initializer_list<HTMLElement> children)
        : HTMLElement("ul", "", children) {};
};

template <typename ... Children>
struct LI : public HTMLElement {
    explicit LI(const std::string & text, const Children& ... children)
        : HTMLElement("li", text, std::initializer_list<HTMLElement> {children ...}) {}

};

int main()
{
    std::cout <<
        UL {
            LI {"item 1"},
            LI {"item 2",
                 UL {
                    LI {"sub-item 2.1"},
                    LI {"sub-item 2.2"}
                }
            }
        };
}
