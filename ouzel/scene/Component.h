// Copyright (C) 2016 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

#include <vector>
#include "utils/Noncopyable.h"
#include "math/AABB2.h"
#include "math/Matrix4.h"
#include "math/Color.h"

namespace ouzel
{
    namespace scene
    {
        class Camera;
        class Node;

        class Component: public ouzel::Noncopyable
        {
            friend Node;
        public:
            virtual ~Component();

            virtual void draw(const Matrix4& transformMatrix,
                              const Color& drawColor,
                              scene::Camera* camera);

            virtual void drawWireframe(const Matrix4& transformMatrix,
                                       const Color& drawColor,
                                       scene::Camera* camera);

            virtual const AABB2& getBoundingBox() const { return boundingBox; }
            bool isAddedToNode() const { return node != nullptr; }

            virtual bool pointOn(const Vector2& position) const;
            virtual bool shapeOverlaps(const std::vector<Vector2>& edges) const;

            bool isHidden() const { return hidden; }
            void setHidden(bool newHidden) { hidden = newHidden; }

        protected:
            AABB2 boundingBox;
            bool hidden = false;

            Node* node = nullptr;
        };
    } // namespace scene
} // namespace ouzel
