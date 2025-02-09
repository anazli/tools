#pragma once

#include "tools/tools.h"

class Ray {
 public:
  Ray() = default;
  Ray(const Point3D &origin, const Vec3D &direction)
      : m_origin(origin), m_direction(direction) {}

  void setOrigin(const Point3D &origin) { m_origin = origin; }
  void setDirection(const Vec3D &direction) { m_direction = direction; }
  Point3D origin() const { return m_origin; }
  Vec3D direction() const { return m_direction; }
  Point3D position(const float &parameter) const {
    return origin() + parameter * direction();
  }
  Ray transform(const Mat4D &matrix) const {
    Ray transformed_ray;

    Vec4D vector4d(origin());
    vector4d = matrix * vector4d;
    transformed_ray.setOrigin(Point3D(vector4d));

    vector4d = direction();
    vector4d = matrix * vector4d;
    transformed_ray.setDirection(Vec3D(vector4d));
    return transformed_ray;
  }

 private:
  Point3D m_origin;
  Vec3D m_direction;
};
