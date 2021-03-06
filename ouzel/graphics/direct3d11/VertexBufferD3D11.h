// Copyright (C) 2016 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#define NOMINMAX
#include <d3d11.h>
#include "graphics/VertexBuffer.h"

namespace ouzel
{
    namespace graphics
    {
        class VertexBufferD3D11: public VertexBuffer
        {
        public:
            VertexBufferD3D11();
            virtual ~VertexBufferD3D11();
            virtual void free() override;

            ID3D11Buffer* getBuffer() const { return buffer; }

        protected:
            virtual bool upload() override;

            ID3D11Buffer* buffer = nullptr;
            UINT bufferSize = 0;
        };
    } // namespace graphics
} // namespace ouzel
