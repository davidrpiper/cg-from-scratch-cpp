//
// Created by David Piper on 10/4/2024.
//

#ifndef CG_FROM_SCRATCH_CPP_CAMERA_H
#define CG_FROM_SCRATCH_CPP_CAMERA_H

#include "math/math.h"

class Camera {
public:
    /**
     * Creates a virtual camera for the three-dimensional Scene.
     * Camera is assumed stable and oriented such that positive Y-axis is "up" and positive X-axis is "right".
     *
     * @param position of the camera in Scene coordinates
     * @param facing unit vector aligning center of camera
     * @param viewportDistance distance of viewport from camera in Scene coordinates
     * @param viewportWidthHeight dimensions of viewport in Scene coordinates
     */
    Camera(Vec3 position, Vec3 facing, unsigned int viewportDistance, uVec2 viewportWidthHeight);

    /**
     * Default camera at (0, 0, 0), facing directly down the positive z-axis (0, 0, 1), with a viewport
     * 1 unit away and a viewport size of 1x1 unit.
     */
    Camera();

    Vec3 getPosition() const;
    Vec3 getFacing() const;
    uVec2 getViewportDimensions() const;

    // Also defines the projection plane (z = d) for the default camera above.
    unsigned int getViewPortDistance() const;

private:
    Vec3 position;
    Vec3 facing;
    uVec2 viewportDimensions;
    unsigned int viewportDistance;
};

#endif //CG_FROM_SCRATCH_CPP_CAMERA_H
