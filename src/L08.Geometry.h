#ifndef __L08_GEOMETRY_H__
#define __L08_GEOMETRY_H__

#include "Base.h"

class Geometry : public Base
{
public:
~Geometry();
static Geometry* create(GlobalConfig* config, Screen* screen)
{
    return new Geometry(config, screen);
}

virtual void update();
protected:
virtual bool createSWSurface();
virtual bool createHWSurface();
Geometry(GlobalConfig* config, Screen* screen);
private:
};

#endif
