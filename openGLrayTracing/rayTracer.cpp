#include <iostream>
#include <vector>
#include <cmath>
#include <GLFW/glfw3.h>

// Vector3 class for 3D math operations
struct Vec3 {
    float x, y, z;
    
    Vec3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
    
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator*(float scalar) const { return Vec3(x * scalar, y * scalar, z * scalar); }
    Vec3 operator/(float scalar) const { return Vec3(x / scalar, y / scalar, z / scalar); }

    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    Vec3 normalize() const { float len = std::sqrt(x * x + y * y + z * z); return Vec3(x / len, y / len, z / len); }
};

// Sphere class for storing position and radius
struct Sphere {
    Vec3 center;
    float radius;
    Vec3 color;

    Sphere(const Vec3& center, float radius, const Vec3& color) 
        : center(center), radius(radius), color(color) {}

    bool intersect(const Vec3& origin, const Vec3& direction, float& t) const {
        Vec3 oc = origin - center;
        float b = 2.0f * oc.dot(direction);
        float c = oc.dot(oc) - radius * radius;
        float discriminant = b * b - 4 * c;
        if (discriminant < 0) return false;
        else {
            t = (-b - std::sqrt(discriminant)) / 2.0f;
            return (t > 0);
        }
    }
};

// Function to compute the color of each pixel
Vec3 traceRay(const Vec3& origin, const Vec3& direction, const std::vector<Sphere>& spheres) {
    float t_min = 1e20;  // large value for initial minimum intersection distance
    Vec3 color(0, 0, 0); // background color (black)

    for (const auto& sphere : spheres) {
        float t;
        if (sphere.intersect(origin, direction, t) && t < t_min) {
            t_min = t;
            Vec3 hitPoint = origin + direction * t;
            Vec3 normal = (hitPoint - sphere.center).normalize();
            float intensity = std::max(0.0f, normal.dot(Vec3(1, -1, -1).normalize())); // simple diffuse light
            color = sphere.color * intensity;
        }
    }
    return color;
}

// Render scene
void renderScene(std::vector<unsigned char>& pixels, int width, int height) {
    Vec3 camera(0, 0, -5);
    std::vector<Sphere> spheres = {
        Sphere(Vec3(0, 0, 3), 1.0, Vec3(255, 0, 0)),
        Sphere(Vec3(-2, 0, 4), 1.0, Vec3(0, 255, 0)),
        Sphere(Vec3(2, 0, 4), 1.0, Vec3(0, 0, 255))
    };

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float u = (x - width / 2.0f) / width;
            float v = (y - height / 2.0f) / height;
            Vec3 direction = Vec3(u, v, 1).normalize();
            Vec3 color = traceRay(camera, direction, spheres);

            // Store color in pixel array
            int index = (y * width + x) * 3;
            pixels[index] = static_cast<unsigned char>(color.x);
            pixels[index + 1] = static_cast<unsigned char>(color.y);
            pixels[index + 2] = static_cast<unsigned char>(color.z);
        }
    }
}

int main() {
    const int width = 800;
    const int height = 600;
    
    if (!glfwInit()) return -1;
    GLFWwindow* window = glfwCreateWindow(width, height, "Simple Ray Tracer", NULL, NULL);
    if (!window) { glfwTerminate(); return -1; }
    glfwMakeContextCurrent(window);

    std::vector<unsigned char> pixels(width * height * 3);

    renderScene(pixels, width, height);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels.data());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}