#include <limits>
#include <vector>
#include <utility>
#include <cmath>
#include "TGA/TGAColor.h"
#include "Canvas.h"
#include "Sphere.h"
#include "Camera.h"

using namespace std;

// Get viewport location from our canvas coordinates.
Vec3f canvasPointToViewport(Canvas &canvas, int canvasX, int canvasY, Camera &camera) {
    float viewportX = 1.0f * canvasX * (1.0f * camera.getViewportDimensions().x / canvas.width());
    float viewportY = 1.0f * canvasY * (1.0f * camera.getViewportDimensions().y / canvas.height());
    float viewportZ = 1.0f * camera.getViewPortDistance();

    return { viewportX, viewportY, viewportZ};
}

// Haven't implemented vector or matrix math functions yet
pair<float, float> intersectRayWithSphere(Camera &camera, Vec3f &viewportPoint, Sphere &sphere) {
    Vec3 camPosition = camera.getPosition();

    // CO = [Camera Position] - [Sphere Center]
    Vec3f CO = {
            (1.0f * camPosition.x - sphere.center.x),
            (1.0f * camPosition.y - sphere.center.y),
            (1.0f * camPosition.z - sphere.center.z)
    };

    // Quadratic equation
    float a = viewportPoint.dot(viewportPoint);
    float b = 2 * CO.dot(viewportPoint);
    float c = CO.dot(CO) - (sphere.radius * sphere.radius);

    float discriminant = b*b - 4*a*c;
    if (discriminant <= 0) {
        return {std::numeric_limits<float>::max(), std::numeric_limits<float>::max()};
    }

    float t1 = (-b + sqrt(discriminant)) / (2*a);
    float t2 = (-b - sqrt(discriminant)) / (2*a);

    return {t1, t2};
}

TGAColor traceRay(Camera &camera, Vec3f &viewportPoint, vector<Sphere> spheres) {
    float maximumT = 100000.0f;
    float closestTSoFar = std::numeric_limits<float>::infinity();
    int indexOfClosestSphere = -1;

    // Would love a for(:) loop, but decided to use indices to track spheres
    for (int i = 0; i < spheres.size(); ++i) {
        Sphere sphere = spheres[i];

        pair<float, float> t1t2 = intersectRayWithSphere(camera, viewportPoint, sphere);
        float t1 = t1t2.first;
        float t2 = t1t2.second;

        if (t1 >= camera.getViewPortDistance() && t1 <= maximumT && t1 <= closestTSoFar) {
            closestTSoFar = t1;
            indexOfClosestSphere = i;
        }

        if (t2 >= camera.getViewPortDistance() && t2 <= maximumT && t2 <= closestTSoFar) {
            closestTSoFar = t2;
            indexOfClosestSphere = i;
        }
    }

    // No sphere intersected
    if (indexOfClosestSphere == -1) {
        return TGAColor::rgb(255, 255, 255);
    }

    // Closest sphere
    return spheres[indexOfClosestSphere].color;
}

int main() {
    // Our Canvas
    Canvas canvas = Canvas(500, 500);

    // Our Scene Data
    auto red = TGAColor::rgb(255, 0, 0);
    auto blue = TGAColor::rgb(0, 0, 255);
    auto green = TGAColor::rgb(0, 255, 0);
    int sphereRadius = 1;

    vector<Sphere> spheres = {
            {{0, -1, 3}, sphereRadius, red},
            {{2, 0, 4}, sphereRadius, blue},
            {{-2, 0, 4}, sphereRadius, green}
    };

    Camera camera = Camera();

    // Paint our canvas
    for (int x = canvas.lowestValidX(); x <= canvas.highestValidX(); ++x) {
        for (int y = canvas.lowestValidY(); y <= canvas.highestValidY(); ++y) {
            Vec3f viewportPoint = canvasPointToViewport(canvas, x, y, camera);
            TGAColor color = traceRay(camera, viewportPoint, spheres);
            canvas.putPixel(x, y, color);
        }
    }

    // A stolen joke: "Britney Spheres"
    canvas.saveImage("britney");
    return 0;
}
