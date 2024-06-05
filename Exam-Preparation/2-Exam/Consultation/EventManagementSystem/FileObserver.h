#include "Observer.h"
#include "FilePath.h"

class FileObserver : public Observer{

    FilePath filePath;
    
public:

    Observer* clone() const override;
    void notify(const char*) const override;

};