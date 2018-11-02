#include "MyForm.h"

using namespace TF_Enemigos;

int main()
{
	srand(time(NULL));
	Application::SetCompatibleTextRenderingDefault(true);
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm);

	return 0;
}