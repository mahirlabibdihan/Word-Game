#include "Headers.h"
extern bool gameover;
extern WordsManager words;
extern Ball ball;
extern string input;

vector<Draw::vertice> Draw::vertices;
GLfloat Draw::r, Draw::g, Draw::b, Draw::a;
GLuint Draw::shaderProgram, Draw::VBO, Draw::VAO;
const GLchar* Draw::vertexShaderSource = "#version 430 core\n"
"layout (location = 0) in vec2 aPos;\n"
"uniform mat4 projection;\n"
"uniform mat4 translation;\n"
"void main()\n"
"{\n"
"   gl_Position =  translation * projection * vec4(aPos,0.0, 1.0);\n"
"}";

const GLchar* Draw::fragmentShaderSource = "#version 430 core\n"
"out vec4 FragColor;\n"
"uniform vec4 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = ourColor;\n"
"}";
void Draw::draw()
{
	clear();
	if (gameover)
	{
		setColor(1,1,1);
		Text::render(165,320, "GAME OVER" ,2);
	}

	else
	{
		ball.draw();
		words.draw();
		setColor(1,1,1);
		Draw::filledRectangle(0, 0, 700, 45);
		setColor(0,0,0);
		Text::render(295, 0, input);
	}
	
}
