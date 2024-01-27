#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

int main()
{
    if (!glfwInit())
    {
        std::cout << "Failed to init glfw." << std::endl;
        return -1;
    }

    GLFWwindow *pWindow = glfwCreateWindow(
        800, 600,
        "OpenGL Window",
        nullptr, nullptr);

    if (pWindow == nullptr)
    {
        std::cout << "Failed to create glfw-window." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(pWindow);
    if (!gladLoadGL())
    {
        std::cout << "Cannot load glad." << std::endl;
        return -1;
    }

    glfwWindowHint(GL_MAJOR_VERSION, 4);
    glfwWindowHint(GL_MINOR_VERSION, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glClearColor(1, 1, 0, 1);
    while (!glfwWindowShouldClose(pWindow))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(pWindow);
        glfwPollEvents();
    }

    glfwSetWindowShouldClose(pWindow, false);
    glfwTerminate();
    std::cout << "Hello!\n";
    return 0;
}