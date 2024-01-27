#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

#define WIDTH 800
#define HEIGHT 600

void glfwWindowSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void glfwKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

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

    glfwWindowHint(GL_MAJOR_VERSION, 4);
    glfwWindowHint(GL_MINOR_VERSION, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pWindow, glfwKeyCallback);

    glfwMakeContextCurrent(pWindow);

    if (!gladLoadGL())
    {
        std::cout << "Cannot load glad." << std::endl;
        return -1;
    }

    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    // std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

    glClearColor(1, 1, 0, 1);

    while (!glfwWindowShouldClose(pWindow))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(pWindow);
        glfwPollEvents();
    }

    glfwSetWindowShouldClose(pWindow, GL_TRUE);
    glfwTerminate();
    std::cout << "Hello!\n";
    return 0;
}