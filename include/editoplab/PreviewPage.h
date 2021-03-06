#pragma once

#include <ee0/Observer.h>

#include <vector>

namespace ur { class Device; }
namespace ee0 { class WxStagePage; class RenderContext; }

namespace editoplab
{

class PreviewPage : public ee0::Observer
{
public:
    PreviewPage(const ur::Device& dev,
        ee0::WxStagePage& stage_page, const ee0::RenderContext& rc);
    virtual ~PreviewPage();

    virtual void OnNotify(uint32_t msg, const ee0::VariantSet& variants) override;

private:
    void Init(const ur::Device& dev, const ee0::RenderContext& rc);

private:
    ee0::WxStagePage& m_stage_page;

    std::vector<uint32_t> m_messages;

}; // PreviewPage

}