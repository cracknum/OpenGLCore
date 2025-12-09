#ifndef OPENGL_CONTEXT_H
#define OPENGL_CONTEXT_H
#include "ContextExport.h"
#include "RenderContext.hpp"
#include "IWindow.hpp"

class CONTEXT_API OpenGLContext final : public RenderContext
{
public:
    using superclass = RenderContext;
    bool init(IWindow *window) override;

    void preRender() override;

    void postRender() override;

    void end() override;
};
#endif // OPENGL_CONTEXT_H