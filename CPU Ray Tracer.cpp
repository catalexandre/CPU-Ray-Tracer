#include <iostream>
#include <fstream>
#include <cmath>

#include "vec3.h"
#include "ray.h"
#include "sphere.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";

    ofstream image("image.ppm");

    auto aspectRatio = 16.0 / 9.0;

    int width = 100;
    int height = width / aspectRatio;

    double focalLength = 1.0; //the focal length is the distance from the camera where the viewport plane is placed
    vec3 lookAt = vec3(0.08, 0.2, -1); //Consider making this a unit vector
    lookAt = unitVector(lookAt);
    vec3 up = vec3(0, 1, 0); //What direction is considered up. It is used to find what is right by doing a cross product lookAt cross up
    vec3 right = cross(lookAt, up);

    cout << "right vector: " << right << "\n";

    vec3 cameraLocation = vec3(0, 0, 0);

    auto viewScale = 1.0;

    auto viewWidth = right * viewScale;
    auto viewHeight = (viewWidth / (double(width) / height)).length() * -up;
    cout << "viewWidth: " << viewWidth << "\n";
    cout << "viewHeight: " << viewHeight << "\n";

    vec3 deltaX = viewWidth / width;
    cout << "delta x: " << deltaX << "\n";
    vec3 deltaY = viewHeight / height;
    cout << "delta y: " << deltaY << "\n";
    vec3 zerothPixelLocation = cameraLocation + lookAt * focalLength - viewWidth / 2 + deltaX / 2 - viewHeight / 2 + deltaY / 2;
    cout << "zeroth pixel location: " << zerothPixelLocation << "\n";

    image << "P3\r" << width << " " << height << "\r255\r";

    sphere s = sphere(vec3(0, 0, 4), 1.0, vec3(0, 120, 200));

    cout << s.getColor() << "\n";

    for (int y = 0; y < height; y++)
    {
        clog << "\rScanlines remaining: " << (height - y) << ' ' << flush;

        for (int x = 0; x < width; x++)
        {

            ray currentRay = ray(cameraLocation, zerothPixelLocation + y * deltaY + x * deltaX - cameraLocation);

            if (s.hit(currentRay))
            {
                vec3 normalAtHit = vec3();

                image << s.getColor() << " ";
            }

            else
            {
                vec3 currentRayDirection = currentRay.direction();
                vec3 currentRayDirectionXZ = vec3(currentRayDirection.x(), 0, currentRayDirection.z());

                auto currentRayUpwardsAngle = acos(dot(currentRayDirection, currentRayDirectionXZ) / (currentRayDirection.length() * currentRayDirectionXZ.length()));

                image << vec3(int(0 * currentRayUpwardsAngle) + int(255 * (1 - currentRayUpwardsAngle)), int(0 * currentRayUpwardsAngle) + int(255 * (1 - currentRayUpwardsAngle)), int(255 * currentRayUpwardsAngle) + int(255 * (1 - currentRayUpwardsAngle))) << " ";
            }

            image << "\r";
        }

    }
    cout << "\ndone";

    image.close();
}