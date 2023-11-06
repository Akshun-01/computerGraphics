#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Define a 3D point structure
struct Point3D {
    double x, y, z;
};

// Translation function
void translate(vector<Point3D>& points, double dx, double dy, double dz) {
    for (int i = 0; i < points.size(); i++) {
        points[i].x += dx;
        points[i].y += dy;
        points[i].z += dz;
    }
}

// Rotation function (around the X-axis)
void rotateX(vector<Point3D>& points, double angle) {
    double radian = angle * 3.14159265 / 180;
    double cosTheta = cos(radian);
    double sinTheta = sin(radian);

    for (int i = 0; i < points.size(); i++) {
        double newY = points[i].y * cosTheta - points[i].z * sinTheta;
        double newZ = points[i].y * sinTheta + points[i].z * cosTheta;
        points[i].y = newY;
        points[i].z = newZ;
    }
}

// Rotation function (around the Y-axis)
void rotateY(vector<Point3D>& points, double angle) {
    double radian = angle * 3.14159265 / 180;
    double cosTheta = cos(radian);
    double sinTheta = sin(radian);

    for (int i = 0; i < points.size(); i++) {
        double newX = points[i].x * cosTheta + points[i].z * sinTheta;
        double newZ = -points[i].x * sinTheta + points[i].z * cosTheta;
        points[i].x = newX;
        points[i].z = newZ;
    }
}

// Scaling function
void scale(vector<Point3D>& points, double sx, double sy, double sz) {
    for (int i = 0; i < points.size(); i++) {
        points[i].x *= sx;
        points[i].y *= sy;
        points[i].z *= sz;
    }
}

int main() {
    // Create a 3D cube represented by its vertices
    vector<Point3D> cube;
    cube.push_back({0, 0, 0});
    cube.push_back({1, 0, 0});
    cube.push_back({1, 1, 0});
    cube.push_back({0, 1, 0});
    cube.push_back({0, 0, 1});
    cube.push_back({1, 0, 1});
    cube.push_back({1, 1, 1});
    cube.push_back({0, 1, 1});

    // Apply transformations to the cube
    translate(cube, 1, 2, 3);
    rotateX(cube, 45);
    rotateY(cube, 30);
    scale(cube, 2, 1.5, 0.5);

    // Display the transformed vertices
    for (int i = 0; i < cube.size(); i++) {
        cout << "X: " << cube[i].x << ", Y: " << cube[i].y << ", Z: " << cube[i].z << endl;
    }

    return 0;
}

