#include "editoplab/Node.h"
#include "editoplab/PinType.h"

#include <blueprint/Pin.h>
#include <blueprint/BackendAdapter.h>

#include <editopgraph/ParamType.h>

namespace editoplab
{

Node::Node(const std::string& title)
    : bp::Node(title)
{
}

void Node::InitPins(const std::string& name)
{
    auto back2front = [](const dag::Node<editopgraph::ParamType>::Port& back) -> bp::PinDesc
    {
        bp::PinDesc front;

        switch (back.var.type)
        {
        case editopgraph::ParamType::Port:
            front.type = PIN_PORT;
            break;
        case editopgraph::ParamType::Any:
            front.type = PIN_ANY;
            break;

        case editopgraph::ParamType::Camera:
            front.type = PIN_CAMERA;
            break;
        case editopgraph::ParamType::Viewport:
            front.type = PIN_VIEWPORT;
            break;
        case editopgraph::ParamType::Publisher:
            front.type = PIN_PUBLISHER;
            break;

        case editopgraph::ParamType::ScreenPos:
            front.type = PIN_SCREEN_POS;
            break;
        case editopgraph::ParamType::Float3:
            front.type = PIN_FLOAT3;
            break;

        case editopgraph::ParamType::Ray:
            front.type = PIN_RAY;
            break;
        case editopgraph::ParamType::Plane:
            front.type = PIN_PLANE;
            break;

        default:
            assert(0);
        }

        front.name = back.var.full_name;

        return front;
    };

    bp::BackendAdapter<editopgraph::ParamType>
        trans("editopgraph", back2front);
    trans.InitNodePins(*this, name);
}

}