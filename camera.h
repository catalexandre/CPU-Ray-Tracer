#ifndef CAMERA_H
#define CAMERA_H

#include <cmath>
#include <fstream>
#include <string>

#include "vec3.h"
#include "ray.h"
#include "sphere.h"
#include "scene.h"
#include "hitRecord.h"

using namespace std;

class camera
{
public:

	camera(int w, double AR, double FL, vec3 LA, vec3& u, double x, double y, double z, double VS, scene s) : 
        width(w),
        height(w / AR),
        focalLength(FL),
        lookAt(unitVector(LA)),
        up(u), right(cross(LA, u)),
        cameraLocation(vec3(x, y, z)),
        viewScale(VS),
        viewWidth(right * VS),
        viewHeight((viewWidth / (double(w) / height)).length() * -u),
        deltaX(viewWidth / w),
        deltaY(viewHeight / height),
        zerothPixelLocation(cameraLocation + LA * FL - viewWidth / 2 + deltaX / 2 - viewHeight / 2 + deltaY / 2),
        scene(s){}

	const void render(scene scene, string imageName) const
	{
		std::ofstream image(imageName);

        cout << zerothPixelLocation << "\n";

	    image << "P3\r" << width << " " << height << "\r255\r";

        for (int y = 0; y < height; y++)
        {
            clog << "\rScanlines remaining: " << (height - y) << ' ' << flush;

            for (int x = 0; x < width; x++)
            {
                ray currentRay = ray(cameraLocation, zerothPixelLocation + y * deltaY + x * deltaX - cameraLocation);

                hitRecord hit = scene.sendRay(currentRay);

                if (hit.getDistance() >= 0)
                {
                    vec3 normalAtHit = unitVector(currentRay.pointAlong(distanceAlongRay) - s.getCenter());
                    vec3 rayColor = 255 * 0.5 * vec3(normalAtHit.x() + 1, normalAtHit.y() + 1, normalAtHit.z() + 1);

                    //cout << normalAtHit << "\n";

                    image << int(rayColor.x()) << " " << int(rayColor.y()) << " " << int(rayColor.z()) << " ";
                }

                else
                {
                    vec3 currentRayDirection = currentRay.direction();
                    vec3 currentRayDirectionXZ = vec3(currentRayDirection.x(), 0, currentRayDirection.z());

                    auto currentRayUpwardsAngle = acos(dot(currentRayDirection, currentRayDirectionXZ) / (currentRayDirection.length() * currentRayDirectionXZ.length()));

                    image << vec3(int(255 * (1 - currentRayUpwardsAngle)), int(255 * (1 - currentRayUpwardsAngle)), int(255 * currentRayUpwardsAngle) + int(255 * (1 - currentRayUpwardsAngle))) << " ";
                }

                image << "\r";
            }

        }
        
        image.close();
	}


private:
	int width, height;
	double focalLength, viewScale;
	vec3 lookAt, up, right, cameraLocation, viewWidth, viewHeight, deltaX, deltaY, zerothPixelLocation;
    scene scene;
};

#endif CAMERA_H