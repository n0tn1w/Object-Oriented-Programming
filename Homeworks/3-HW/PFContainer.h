#pragma once
#include "PF.h"

// Abstract class
class PFContainer : public PF{

public:

    PFContainer() = default;
    PFContainer(const PFContainer&);
    PFContainer(PFContainer&&) noexcept;
    PFContainer& operator=(const PFContainer&);
    PFContainer& operator=(PFContainer&&) noexcept;
    ~PFContainer();

    PFContainer(const PF* const*, size_t);
    PFContainer(PF**&&, size_t);

    bool isEmpty() const;

protected:
    PF** _data = nullptr;
    size_t _size = 0;

private:
    void copyFrom(const PFContainer&);
    void moveFrom(PFContainer&&);
    void free(); 
};