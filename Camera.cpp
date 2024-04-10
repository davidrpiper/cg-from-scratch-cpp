//
// Created by David Piper on 10/4/2024.
//

#include "Camera.h"

Camera::Camera() : Camera({0, 0, 0}, {0, 0, 1}, 1, {1, 1}) { }

Camera::Camera(Vec3 position, Vec3 facing, unsigned int viewportDistance, uVec2 viewportWidthHeight) : position(position), facing(facing), viewportDimensions(viewportWidthHeight), viewportDistance(viewportDistance) { }

Vec3 Camera::getPosition() const {
    return position;
}

Vec3 Camera::getFacing() const {
    return facing;
}

uVec2 Camera::getViewportDimensions() const {
    return viewportDimensions;
}

unsigned int Camera::getViewPortDistance() const {
    return viewportDistance;
}
