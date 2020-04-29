#pragma once

#include <ee3/WxStageCanvas.h>
#include <blueprint/WxGraphPage.h>

#include <editopgraph/ParamType.h>
#include <editopgraph/typedef.h>

namespace editoplab
{

class WxEditorPanel;

class WxPreviewCanvas : public ee3::WxStageCanvas
{
public:
    WxPreviewCanvas(const ur::Device& dev, ee0::WxStagePage* stage,
        ECS_WORLD_PARAM const ee0::RenderContext& rc);
    virtual ~WxPreviewCanvas();

    virtual void OnNotify(uint32_t msg, const ee0::VariantSet& variants) override;

    void SetGraphPage(const bp::WxGraphPage<editopgraph::ParamType>* graph_page);

protected:
    virtual void DrawBackground3D() const override;
    virtual void DrawForeground3D() const override;
    virtual void DrawForeground2D() const override;

private:
    void OnSelectionInsert(const ee0::VariantSet& variants);
    void OnSelectionClear(const ee0::VariantSet& variants);

    void DrawSelected(tess::Painter& pt, const sm::mat4& cam_mat) const;

    bp::NodePtr GetSelectedNode() const;

private:
    const bp::WxGraphPage<editopgraph::ParamType>* m_graph_page = nullptr;

    n0::SceneNodePtr m_selected = nullptr;

}; // WxPreviewCanvas

}