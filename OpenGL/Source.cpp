#include "stdio.h"

#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>

#include <gl_core_4_4.h> 
#include <GLFW/glfw3.h> 
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#define PI 3.1415926535897932384626433832795

using glm::vec3;
using glm::vec4;
using glm::mat4;

vec4 white(1);
vec4 yellow(1, 1, 0, 1);
vec4 green(0, 1, 0, 1);
vec4 black(0, 0, 0, 1);
vec4 red(1, 0, 0, 1);
vec4 blue(0, 0, 1, 1);
vec4 light_blue(0, 0.75, 1, 1);
vec4 orange(1, 0.5, 0, 1);
struct Moon_Struct
{
	float radius = 0.01, quality = 10, orbit = 0, angle = 0, speed = 0.01f;
	vec3 pos = { 0, 0, 0 };
	vec4 color = white;
};
struct Planet_Struct
{
	float radius, quality, orbit = 0, angle = 0, speed = 0.001f;
	vec3 pos = { 0, 0, 0 };
	vec4 color = white;
	std::vector<Moon_Struct> Moon;
};

void Init(Planet_Struct*);
void Update(Planet_Struct*);
int main()
{
	srand(time(NULL));

	if (glfwInit() == false)
		return -1;

	int num_monitors[2];
	int size = 20000, up = 1;
	
	float angle[2] = { 0, 45 };
	double mouse_x[1], mouse_y[1];
	double prev_x[1], prev_y[1];

	Planet_Struct Planets[9];
	Init(Planets);

	GLFWmonitor** monitor = glfwGetMonitors(num_monitors);
	const GLFWvidmode* mode = glfwGetVideoMode(monitor[0]);
	GLFWwindow * window = glfwCreateWindow(mode->width, mode->height, "Computer Graphics", nullptr, nullptr);
	glfwSetWindowPos(window, 0, 0);

	if (window == nullptr)
	{
		glfwTerminate();
		return -2;
	}
	//make the glfw window 
	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}

	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf_s("GL: %i.%i\n", major, minor);

	float x = 0, y = 0, z = 0;
	float radius = 10000;
	vec3 quadrant[4] = { {60, 20, 20}, { 60, 20, 20 }, { 60, 20, 20 }, { 60, 20, 20 } };
	//initialize all of our gizmos and set up the virtual camera
	Gizmos::create();
	mat4 view;
	mat4 projection = glm::perspective(glm::pi<float>() * 0.25f,
		16 / 9.f, 0.1f, 100000.f);
	/*
	The Gizmo class works by allowing us to add geometric shapes and lines to it. We can then draw
	anything that has been added to it. The shapes remain until we call Gizmos::clear() which removes
	all shapes and lines, and we can add new ones.
	*/


	glClearColor(0.25f, 0.25f, 0.25f, 1);//set the clear color
	glEnable(GL_DEPTH_TEST); // enables the depth buffer	

	glfwGetCursorPos(window, mouse_x, mouse_y);
	prev_x[0] = mouse_x[0];
	prev_y[0] = mouse_y[0];

	int i, j;
	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		//GL_COLOR_BUFFER_BIT informs OpenGL to wipe the back-buffer colours clean.
		//GL_DEPTH_BUFFER_BIT informs it to clear the distance to the closest pixels.
		//If we didn’t do this then OpenGL may think the image of the last frame is still there
		//and our new visuals may not display
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//clear the backbuffer
		// our game logic and update code goes here!
		// so does our render code!
		Gizmos::clear();
		Gizmos::addTransform(glm::mat4(1));
		Update(Planets);

		/*for (i = 0; i <= size; i += size/50)
		{
			Gizmos::addLine(vec3(-(size / 2) + i, 0, (size / 2)), vec3(-(size / 2) + i, 0, -(size / 2)), i == (size / 2) ? white : black);
			Gizmos::addLine(vec3((size / 2), 0, -(size / 2) + i), vec3(-(size / 2), 0, -(size / 2) + i), i == (size / 2) ? white : black);
		}*/
		for (i = 0; i < (sizeof(Planets) / sizeof(Planets[0])); i++)
		{
			Gizmos::addSphere(Planets[i].pos, Planets[i].radius, Planets[i].quality, Planets[i].quality, Planets[i].color);
			for (j = 0; j < Planets[i].Moon.size(); j++)
			{
				Gizmos::addSphere(Planets[i].Moon[j].pos, Planets[i].Moon[j].radius, Planets[i].Moon[j].quality, Planets[i].Moon[j].quality, Planets[i].Moon[j].color);
			}
		}

		glfwGetCursorPos(window, mouse_x, mouse_y);

		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1))
		{
			angle[0] += (mouse_x[0] - prev_x[0]) / (radius / 750);
			angle[1] += (mouse_y[0] - prev_y[0]) / (radius / 750);
		}

		if (glfwGetKey(window, GLFW_KEY_W))
			radius -= 40;
		if (glfwGetKey(window, GLFW_KEY_S))
			radius += 40;

		if (radius < 2000)
			radius = 2000;

		if (glfwGetKey(window, GLFW_KEY_UP))
			angle[1] += 1;
		if (glfwGetKey(window, GLFW_KEY_DOWN))
			angle[1] -= 1;
		if (glfwGetKey(window, GLFW_KEY_LEFT))
			angle[0] += 1;
		if (glfwGetKey(window, GLFW_KEY_RIGHT))
			angle[0] -= 1;

		if (angle[0] < 0)
			angle[0] = 360;
		if (angle[0] > 360)
			angle[0] = 0;

		if (angle[1] > 90)
			angle[1] = 90;
		if (angle[1] < -90)
			angle[1] = -90;
		

		if (glfwGetKey(window, GLFW_KEY_T))
			view = glm::lookAt(vec3(x, y, z), vec3(0), vec3(0, up, 0));

		prev_x[0] = mouse_x[0];
		prev_y[0] = mouse_y[0];

		view = glm::lookAt(vec3(
			cos(angle[0] * (PI / 180))*(cos(angle[1] * (PI / 180))*radius),
			sin(angle[1] * (PI / 180))*radius,
			sin(angle[0] * (PI / 180))*(cos(angle[1] * (PI / 180))*radius)), vec3(0, 0, 0), vec3(0, 1, 0));

		std::cout << angle[1] << " " << sin(angle[1] * (PI / 180))*radius << std::endl;

		Gizmos::draw(projection * view);

		glfwSwapBuffers(window);
		glfwPollEvents();
		Sleep(10);
	}

	Gizmos::destroy();
	// the rest of our code goes here!
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

void Init(Planet_Struct* p_Planets)
{
	int i, j, hold;
	p_Planets[0].pos = { 0, 0, 0};
	for (i = 1; i < 9; i++)
	{
		p_Planets[i].orbit = 1500 + (i * 1000);
		p_Planets[i].angle = rand() % 359;
		p_Planets[i].pos = { cos(p_Planets[i].angle) * p_Planets[i].orbit, 0, tan(p_Planets[i].angle) * p_Planets[i].orbit };
		p_Planets[i].speed = float((2 + rand() % 20)) / 10000;
	}

	p_Planets[0].color = yellow;
	p_Planets[1].color = red;
	p_Planets[2].color = green;
	p_Planets[3].color = blue;
	p_Planets[4].color = red;
	p_Planets[5].color = orange;
	p_Planets[6].color = blue;
	p_Planets[7].color = light_blue;
	p_Planets[8].color = blue;

	p_Planets[0].radius = 1090;
	p_Planets[1].radius = 3.8;
	p_Planets[2].radius = 9.5;
	p_Planets[3].radius = 10;
	p_Planets[4].radius = 5.3;
	p_Planets[5].radius = 111.9;
	p_Planets[6].radius = 94;
	p_Planets[7].radius = 40.4;
	p_Planets[8].radius = 1.8;

	p_Planets[0].quality = 30;
	p_Planets[1].quality = 8;
	p_Planets[2].quality = 8;
	p_Planets[3].quality = 8;
	p_Planets[4].quality = 8;
	p_Planets[5].quality = 15;
	p_Planets[6].quality = 15;
	p_Planets[7].quality = 10;
	p_Planets[8].quality = 8;

	Moon_Struct temp;
	for (i = 1; i < 9; i++)
	{
		hold = 1 + rand() % 4;
		for (j = 0; j <= hold; j++)
		{
			temp.angle = rand() % 359;
			temp.radius = (p_Planets[i].radius / 5) + (float((rand() % (int(p_Planets[i].radius))) / 5));
			temp.orbit = (p_Planets[i].radius * 1.5) + ((temp.radius*10) / j);
			temp.speed = float((5 + rand() % 9)) / 1000;
			temp.pos = { cos(temp.angle) * temp.orbit, 3, tan(temp.angle) * temp.orbit };
			p_Planets[i].Moon.push_back(temp);
		}
	}
}
void Update(Planet_Struct* p_Planets)
{
	int i, j;
	for (i = 1; i < 9; i++)
	{
		p_Planets[i].angle += p_Planets[i].speed;
		if (p_Planets[i].angle > 360)
			p_Planets[i].angle = 0;

		p_Planets[i].pos = { cos(p_Planets[i].angle) * p_Planets[i].orbit, 3, sin(p_Planets[i].angle) * p_Planets[i].orbit };
		for (j = 0; j < p_Planets[i].Moon.size(); j++)
		{
			p_Planets[i].Moon[j].pos = { (cos(p_Planets[i].Moon[j].angle) * p_Planets[i].Moon[j].orbit) + p_Planets[i].pos[0], 3,
				(sin(p_Planets[i].Moon[j].angle) * p_Planets[i].Moon[j].orbit) + p_Planets[i].pos[2] };
			p_Planets[i].Moon[j].angle += p_Planets[i].Moon[j].speed;
		}
	}
}