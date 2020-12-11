#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

int g_windowsSizeX = 640;
int g_windowsSizeY = 480;
void glfwWindowsSizeCallBack(GLFWwindow* pwindow, int width, int length)
{

	g_windowsSizeX = width;
	g_windowsSizeY = length;
	glViewport(0, 0, g_windowsSizeX, g_windowsSizeY);
}
void glfwKeyCallBack(GLFWwindow* pwindow, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{

		glfwSetWindowShouldClose(pwindow, GL_TRUE);
	}

}
int main(void)
{
     

    /* Initialize the library */
	if (!glfwInit())
	{
		cout << "glfwInit filed" << endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Create a windowed mode window and its OpenGL context */
	GLFWwindow* pwindow = glfwCreateWindow(g_windowsSizeX, g_windowsSizeY, "BattleCity", nullptr, nullptr);
    if (!pwindow)
    {
		cout << "glfwCreateWindow filed" << endl;
        glfwTerminate();
        return -1;
    }
	
	
	glfwSetWindowSizeCallback(pwindow, glfwWindowsSizeCallBack);
	
	glfwSetKeyCallback(pwindow, glfwKeyCallBack);

    /* Make the window's context current */
    glfwMakeContextCurrent(pwindow);
	if(!gladLoadGL())
	{
		std::cout <<"Can,t Load GLAD!"<<std::endl;
		return -1;
	}
	cout << "Renderrer:" << glGetString(GL_RENDERER) << endl;
	cout << "Opengl version:" << glGetString(GL_VERSION) << endl;
	
	
	glClearColor(1,1,0,1);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pwindow))
    {
        /* Render here */
         glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pwindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}