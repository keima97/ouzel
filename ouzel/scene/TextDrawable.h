// Copyright (C) 2016 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#include <string>
#include "scene/Component.h"
#include "utils/Types.h"
#include "math/Color.h"
#include "gui/BMFont.h"

namespace ouzel
{
    namespace scene
    {
        class TextDrawable: public Component
        {
        public:
            TextDrawable(const std::string& fontFile,
                         bool aMipmaps = true,
                         const std::string& aText = std::string(),
                         const Vector2& aTextAnchor = Vector2(0.5f, 0.5f));

            virtual void draw(const Matrix4& transformMatrix,
                              const Color& drawColor,
                              scene::Camera* camera) override;

            virtual void drawWireframe(const Matrix4& transformMatrix,
                                       const Color& drawColor,
                                       scene::Camera* camera) override;

            virtual void setFont(const std::string& fontFile);

            virtual void setTextAnchor(const Vector2& newTextAnchor);
            virtual const Vector2& getTextAnchor() const { return textAnchor; }

            virtual void setText(const std::string& newText);
            virtual const std::string& getText() const { return text; }

            virtual const Color& getColor() const { return color; }
            virtual void setColor(const Color& newColor);

            virtual const graphics::ShaderPtr& getShader() const { return shader; }
            virtual void setShader(const graphics::ShaderPtr& newShader) { shader = newShader; }

            virtual const graphics::BlendStatePtr& getBlendState() const { return blendState; }
            virtual void setBlendState(const graphics::BlendStatePtr& newBlendState)  { blendState = newBlendState; }

        protected:
            void updateText();

            graphics::ShaderPtr shader;
            graphics::BlendStatePtr blendState;

            graphics::MeshBufferPtr meshBuffer;
            graphics::IndexBufferPtr indexBuffer;
            graphics::VertexBufferPtr vertexBuffer;

            graphics::TexturePtr texture;
            graphics::TexturePtr whitePixelTexture;

            BMFont font;
            std::string text;
            Vector2 textAnchor;

            std::vector<uint16_t> indices;
            std::vector<graphics::VertexPCT> vertices;

            Color color = Color::WHITE;

            bool mipmaps = true;
            bool needsMeshUpdate = false;
        };
    } // namespace scene
} // namespace ouzel
