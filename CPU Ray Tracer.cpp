#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout << "Hello World!\n";

    ofstream image("image.ppm");

    int width = 150;
    int height = 150;

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