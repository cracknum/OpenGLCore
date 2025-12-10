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

	void resize(int width = -1, int height = -1) override;
	void maximum();
	void fullScreen();

    void end() override;
};
#endif // OPENGL_CONTEXT_H