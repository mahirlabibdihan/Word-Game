#include "Headers.h"
GLFWwindow* window;
Ball ball;
string input;
WordsManager words;
bool gameover;
int main()
{
	srand(time(NULL));

	if (!glfwInit()) { exit(EXIT_FAILURE); }
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(700,745, "Dxball", NULL, NULL);
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); }

	glfwSetKeyCallback(window, Keyboard::keyHandler);	// Callback for keyboard interactions

	glEnable(GL_BLEND);     // Transparent Color
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);   // Transparent Color
	glLineWidth(2.0);   // Set drawing line width

	Draw::start();	// Necessary initializations for drawing
	Text::init();  // Necessary initializations for text rendering
	// Main loop
	int timebase = glfwGetTime();	// Timer for new word
	while (!glfwWindowShouldClose(window))
	{
		Draw::draw();

		if (!gameover)
		{
			ball.update();	// Moving the ball
			words.update(); 
			if (glfwGetTime() - timebase > 3)	// A new word will appear after every 3 seconds
			{
				words.generate();
				timebase = glfwGetTime();
			}
		}
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	Draw::end();
	glfwTerminate();
	glfwDestroyWindow(window);
	exit(EXIT_SUCCESS);
	return 0;
}