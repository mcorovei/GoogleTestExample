#include <memory>

#include "AInterface.h"

using namespace std;

class AClass {
    public:
        AClass(std::weak_ptr<AInterface> aInterface);
        
        void doSomething();
        int doSomethingElse(int aValue);
    private:
        std::weak_ptr<AInterface> m_interface;
};