#pragma once

#include <memory>
#include <optional>

#include "GlmTypes.h"

namespace bv {

struct Intersection {
    vec3d pos;
    vec3d normal;
};

class Ray;

class Geometry {
public:

    Geometry(const glm::vec3& colour)
            : colour(colour) {};

    virtual std::optional<Intersection> intersect(const std::unique_ptr<Ray>& ray, vec3d& intersectionPoint) = 0;

    virtual std::pair<vec3d, vec3d> getBoundingBox() = 0;

    vec3f getColour() {
        return colour;
    }

    ~Geometry() = default;

private:
    vec3f colour;
};

std::shared_ptr<Geometry> createTriangle(const vec3d v1, const vec3d v2, const vec3d v3, const vec3f colour);
std::shared_ptr<Geometry> createSphere(const vec3d centre, const double radius, const vec3f colour);
}

