#include <iostream>
#include <chrono>

#include "vec3.h"
#include "ray.h"
#include "sphere.h"
#include "camera.h"

using namespace std;

int main()
{
    auto startTime = chrono::high_resolution_clock::now();

    //ofstream image("image.ppm");
    
    double aspectRatio = 16.0 / 9.0;

    vec3 up = vec3(0, 1, 0);

    camera camera1 = camera(100, aspectRatio, 1, vec3(0, 0, -1), up, 0, 0, 0, 1);

    camera1.render("image.ppm");

    auto endTime = std::chrono::high_resolution_clock::now();
    auto renderTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    cout << "\ndone in " << renderTime << " ms";
}