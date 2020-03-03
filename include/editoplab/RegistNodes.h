#pragma once

#include "editoplab/Node.h"

namespace editoplab
{

void nodes_regist_rttr();

namespace node
{

#define EXE_FILEPATH "editoplab/node_def_gen.h"
#include "editoplab/node_regist_cfg.h"
#undef EXE_FILEPATH

}

}