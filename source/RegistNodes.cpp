#include "editoplab/RegistNodes.h"

#include <ee0/ReflectPropTypes.h>

#include <js/RTTR.h>

RTTR_REGISTRATION
{

// base

rttr::registration::class_<editoplab::Node>("editoplab::node")
.property("name", &editoplab::Node::GetName, &editoplab::Node::SetName)
(
	rttr::metadata(ee0::UIMetaInfoTag(), ee0::UIMetaInfo("Name"))
)
;

#define EXE_FILEPATH "editoplab/node_rttr_gen.h"
#define SKIP_FILE_NODE
#include "editoplab/node_regist_cfg.h"
#undef SKIP_FILE_NODE
#undef EXE_FILEPATH

}

namespace editoplab
{

void nodes_regist_rttr()
{
}

}