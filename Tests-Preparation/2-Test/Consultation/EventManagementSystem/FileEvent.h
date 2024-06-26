#include "Event.h"
#include "FilePath.h"


class FileEvent : public Event {

public:

    Event* clone() const override;
    const char* check() const override;

private:

    FilePath filePath;
    unsigned fileSize;

};