#include <iostream>
#include <fstream>

#include "vec3.h"
#include "ray.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";

    ofstream image("image.ppm");

    auto aspectRatio = 16.0 / 9.0;

    int width = 100;
    int height = width / aspectRatio;

    double focalLength = 1.0; //the focal length is the distance from the camera where the viewport plane is placed
    vec3 lookAt = vec3(0, 0, 1); //Consider making this a unit vector
    vec3 up = vec3(0, 1, 0); //What direction is considered up. It is used to find what is right by doing a cross product lookAt cross up
    vec3 right = cross(lookAt, up);
    vec3 cameraLocation = vec3(0, 0, 0);

    auto viewWidth = 2.0;
    auto viewHeight = viewWidth / (double(width) / height);

    vec3 deltaX = vec3(viewWidth / width, 0, 0);
    vec3 deltaY = vec3(0, viewHeight / height, 0);

    cout << width << " | " << height << " | " << viewWidth << " | " << viewHeight << "\n";

    image << "P3\r" << width << " " << height << "\r255\r";

    for (int y = 0; y < height; y++)
    {

        clog << "\rScanlines remaining: " << (height - y) << ' ' << flush;

        for (int x = 0; x < width; x++)
        {
            image << x << " " << x << " " << x << " ";
        }

        image << "\r";
}

    cout << "\ndone";

    image.close();
}