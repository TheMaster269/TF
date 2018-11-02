#pragma once
#include "Horde.h"
#include <time.h>

namespace TF_Enemigos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			G = CreateGraphics();
			espaceBuffer = BufferedGraphicsManager::Current;
			BG = espaceBuffer->Allocate(G, ClientRectangle);
			MeleBitmap = gcnew Bitmap("MeleSprite.png");
			ShootBitmap = gcnew Bitmap("ShootSprite.png");
			BulletBitmap = gcnew Bitmap("BulletSprite.png");
			background = gcnew Bitmap("background.jpg");
			horde = new Horde(3, 4, G->VisibleClipBounds.Width, G->VisibleClipBounds.Height);

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Graphics^ G;
		BufferedGraphics^ BG;
		Bitmap^ MeleBitmap;
		Bitmap^ ShootBitmap;
		Bitmap^ background;
		Bitmap^ BulletBitmap;
		Horde* horde;
	private: System::Windows::Forms::Timer^  deltaTime;
			 BufferedGraphicsContext^ espaceBuffer;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->deltaTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// deltaTime
			// 
			this->deltaTime->Enabled = true;
			this->deltaTime->Tick += gcnew System::EventHandler(this, &MyForm::deltaTime_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void deltaTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		horde->CheckLive();
		BG->Graphics->Clear(Color::Black);
		BG->Graphics->DrawImage(background, 0.0f, 0.0f, G->VisibleClipBounds.Width, G->VisibleClipBounds.Height);
		horde->Mostrar(BG->Graphics, MeleBitmap, ShootBitmap, BulletBitmap);
		BG->Render(G);
	}
	};
}
