#pragma once

namespace editoplab
{

enum PinType
{
#define PIN_INFO(type, color, desc) \
    PIN_##type,
#include "editoplab/pin_cfg.h"
#undef PIN_INFO
};

}