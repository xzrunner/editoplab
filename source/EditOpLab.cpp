#include "editoplab/EditOpLab.h"
#include "editoplab/PinCallback.h"
#include "editoplab/Node.h"
#include "editoplab/RegistNodes.h"

#include <blueprint/NodeBuilder.h>
#include <blueprint/node/Commentary.h>

#include <editopgraph/EditOpGraph.h>

namespace bp
{
extern void regist_sm_rttr();
extern void regist_pt0_rttr();
}

namespace editoplab
{

CU_SINGLETON_DEFINITION(EditOpLab);

EditOpLab::EditOpLab()
{
    editopgraph::EditOpGraph::Instance();

    RegistRTTR();

	InitNodes();

    InitPinCallback();
}

void EditOpLab::RegistRTTR()
{
    bp::regist_sm_rttr();
    bp::regist_pt0_rttr();

    //	prop_types_regist_rttr();
    nodes_regist_rttr();
}

void EditOpLab::InitNodes()
{
    const int bp_count = 1;

	auto list = rttr::type::get<Node>().get_derived_classes();
	m_nodes.reserve(bp_count + list.size());

    m_nodes.push_back(std::make_shared<bp::node::Commentary>());

	for (auto& t : list)
	{
		auto obj = t.create();
		assert(obj.is_valid());
		auto node = obj.get_value<bp::NodePtr>();
		assert(node);
		m_nodes.push_back(node);
	}
}

}