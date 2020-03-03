#pragma once

#include <blueprint/typedef.h>

#include <cu/cu_macro.h>

#include <vector>
#include <memory>

namespace editoplab
{

class EditOpLab
{
public:
    auto& GetAllNodes() { return m_nodes; }

private:
    void RegistRTTR();
    void InitNodes();

private:
    std::vector<bp::NodePtr> m_nodes;

    CU_SINGLETON_DECLARATION(EditOpLab)

}; // EditOpLab

}