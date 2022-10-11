#include "AClass.h"

AClass::AClass(std::weak_ptr<AInterface> aInterface) {
    m_interface = aInterface;
}

void AClass::doSomething() {
    auto rawInterface = m_interface.lock();
    if(rawInterface != nullptr) {
        rawInterface->doSomething();
    }
}

int AClass::doSomethingElse(int aValue) {
    auto rawInterface = m_interface.lock();
    if(rawInterface != nullptr) {
        return rawInterface->doSomethingElse(aValue);
    }
}