#pragma once
#include <cmath>

namespace ThirdBlock {

	//class Tree;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int n = 4;
	const int numLevel = 10;
	const int dEllipse = 10;

	//enum Colors {Black, Red, Green, Blue, Yellow};

	


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		Tree* tree = new Tree(200);

		
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	


	private: void Paint() {
		Graphics^ Графика = pictureBox1->CreateGraphics();
		int width = pictureBox1->Width;
		int height = pictureBox1->Height;
		Графика->TranslateTransform(width / 2, height / 2);
		Tree* tree = new Tree(200);

		tree->AddNumLevel(4, width, height);
		tree->PaintTree(Графика);


		/*int a;


		a = int((height - 10) / 2);

		int y = a * cos(60);

		Point p1 = Point(0, int(-y / 2));
		Point p2 = Point(int(-a / 2), int(y / 2));
		Point p3 = Point(int(a / 2), int(y / 2));

		Графика->DrawLine(Pens::Black, p1, p2);
		Графика->DrawLine(Pens::Black, p2, p3);
		Графика->DrawLine(Pens::Black, p3, p1);

		Fractal(p1, p2, p3, n - 1, width, height);
		Fractal(p2, p3, p1, n - 1, width, height);
		Fractal(p3, p1, p2, n - 1, width, height); */
	}

	/*private: int Fractal(Point p1, Point p2, Point p3, int iter, int width, int height) {
		Graphics^ Графика = pictureBox1->CreateGraphics();
		Графика->TranslateTransform(width / 2, height / 2);

		//n -количество итераций

		if (iter > 0)  //условие выхода из рекурсии
		{
			//средняя треть отрезка
			Point p4 = Point((p2.X + 2 * p1.X) / 3, (p2.Y + 2 * p1.Y) / 3);
			Point p5 = Point((2 * p2.X + p1.X) / 3, (p1.Y + 2 * p2.Y) / 3);
			//координаты вершины угла
			Point ps = Point((p2.X + p1.X) / 2, (p2.Y + p1.Y) / 2);
			Point pn = Point((4 * ps.X - p3.X) / 3, (4 * ps.Y - p3.Y) / 3);
			//рисуем его
			Графика->DrawLine(Pens::Green, p4, pn);
			Графика->DrawLine(Pens::Green, p5, pn);
			Графика->DrawLine(Pens::Green, p4, p5);


			//рекурсивно вызываем функцию нужное число раз
			Fractal(p4, pn, p5, iter - 1, width, height);
			Fractal(pn, p5, p4, iter - 1, width, height);
			Fractal(p1, p4, Point((2 * p1.X + p3.X) / 3, (2 * p1.Y + p3.Y) / 3), iter - 1, width, height);
			Fractal(p5, p2, Point((2 * p2.X + p3.X) / 3, (2 * p2.Y + p3.Y) / 3), iter - 1, width, height);

		}
		return iter;
	}*/


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1352, 655);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(599, 674);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(201, 33);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1384, 759);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Paint();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Text = "Снежинка Коха";
		button1->Text = "Рисовать";
	}
};

class Tree {
private:
	class Node {
	public: Point coordF;
		  Point coordT;
		  int level;
		  double angle;
		  //у каждого родителя по три ребёнка, то есть по три новые координаты
		  Node* First;
		  Node* Second;
		  Node* Third;
		  Node* Fourth;
		  Node* Fifth;
		  Node* Sixth;
		  Node* Parent;

		  Node() {
			  coordF = Point(0, 0);
			  coordT = Point(0, 0);
			  level = 0;
			  angle = 0;
			  First = NULL;
			  Second = NULL;
			  Third = NULL;
			  Fourth = NULL;
			  Fifth = NULL;
			  Sixth = NULL;
			  Parent = NULL;
		  }

		  Node(Point _coordF, Point _coordT, int _level, double _angle) {
			  coordF = _coordF;
			  coordT = _coordT;
			  level = _level;
			  angle = _angle;
			  First = NULL;
			  Second = NULL;
			  Third = NULL;
			  Fourth = NULL;
			  Fifth = NULL;
			  Sixth = NULL;
			  Parent = NULL;
		  }
	};

	static Node* root;

	Node* lvl1[6];
	Node* lvl2[18];
	Node* lvl3[54];
	Node* lvl4[162];
	Node* lvl5[486];
	Node* lvl6[1458];
	Node* lvl7[4374];
	Node* lvl8[13122];
	Node* lvl9[39366];

	int side;

	int numElOfLvl[10] = { 1, 6, 18, 54, 162, 486, 1458, 4374, 13122, 39366 };

	void AddLevel(int numOfLevel, int _width, int _height) {
		Point tree;
		Point fract;
		int _level;
		double _angle;
		if (numOfLevel == 0) {
			int xT, yT;
			xT = _width / 2;
			yT = _height / (2 * numLevel);
			tree = Point(xT, yT);
			fract = Point(0, 0);
			_level = numOfLevel;
			_angle = 0;
			Node* newNode = new Node(tree, fract, _level, _angle);
			newNode->First = NULL;
			newNode->Second = NULL;
			newNode->Third = NULL;
			newNode->Fourth = NULL;
			newNode->Fifth = NULL;
			newNode->Sixth = NULL;
			newNode->Parent = NULL;
			root = newNode;
		}

		switch (numOfLevel) {
		case 0: break;
		case 1: AddChildren(*root, _width, _height); break;
		case 2:
			for (int i = 0; i < 6; i++) {
				AddChildren(*lvl1[i], _width, _height);
			}
			break;
		case 3:
			for (int i = 0; i < 18; i++) {
				AddChildren(*lvl2[i], _width, _height);
			}
			break;
		case 4:
			for (int i = 0; i < 54; i++) {
				AddChildren(*lvl3[i], _width, _height);
			}
			break;
		case 5:
			for (int i = 0; i < 162; i++) {
				AddChildren(*lvl4[i], _width, _height);
			}
			break;
		case 6:
			for (int i = 0; i < 486; i++) {
				AddChildren(*lvl5[i], _width, _height);
			}
			break;
		case 7:
			for (int i = 0; i < 1458; i++) {
				AddChildren(*lvl6[i], _width, _height);
			}
			break;
		case 8:
			for (int i = 0; i < 4374; i++) {
				AddChildren(*lvl7[i], _width, _height);
			}
			break;
		case 9:
			for (int i = 0; i < 13122; i++) {
				AddChildren(*lvl8[i], _width, _height);
			}
			break;
		}

	}

	void AddChildren(Node _parent, int _width, int _height) {
		Point tree;
		Point fract;
		int _level;
		double _angle;

		int xT, yT, xF, yF;

		if (_parent.level == 1) {
			//первый ребёнок
			xF = _parent.coordF.X + sqrt(3) * side / 6 * cos(0.52);
			yF = _parent.coordF.Y + sqrt(3) * side / 6 * sin(0.52);

			xT = _width / 12;
			yT = 3 * _height / (2 * numLevel);

			tree = Point(xT, yT);
			fract = Point(xF, yF);
			_level = _parent.level + 1;
			_angle = 0.52; // 30
			Node* newFirstNode = new Node(tree, fract, _level, _angle);
			newFirstNode->First = NULL;
			newFirstNode->Second = NULL;
			newFirstNode->Third = NULL;
			newFirstNode->Fourth = NULL;
			newFirstNode->Fifth = NULL;
			newFirstNode->Sixth = NULL;
			newFirstNode->Parent = &_parent;
			_parent.First = newFirstNode;

			//второй ребёнок
			xF = _parent.coordF.X + sqrt(3) * side / 6 * cos(1.57);
			yF = _parent.coordF.Y + sqrt(3) * side / 6 * sin(1.57);

			xT = 3 * _width / 12;
			yT = 3 * _height / (2 * numLevel);

			tree = Point(xT, yT);
			fract = Point(xF, yF);
			_level = _parent.level + 1;
			_angle = 1.57; // 90
			Node* newSecondNode = new Node(tree, fract, _level, _angle);
			newSecondNode->First = NULL;
			newSecondNode->Second = NULL;
			newSecondNode->Third = NULL;
			newSecondNode->Fourth = NULL;
			newSecondNode->Fifth = NULL;
			newSecondNode->Sixth = NULL;
			newSecondNode->Parent = &_parent;
			_parent.Second = newSecondNode;

			//третий ребёнок
			xF = _parent.coordF.X + sqrt(3) * side / 6 * cos(2.62);
			yF = _parent.coordF.Y + sqrt(3) * side / 6 * sin(2.62);

			xT = 5 * _width / 12;
			yT = 3 * _height / (2 * numLevel);

			tree = Point(xT, yT);
			fract = Point(xF, yF);
			_level = _parent.level + 1;
			_angle = 2.62; // 150
			Node* newThirdNode = new Node(tree, fract, _level, _angle);
			newThirdNode->First = NULL;
			newThirdNode->Second = NULL;
			newThirdNode->Third = NULL;
			newThirdNode->Fourth = NULL;
			newThirdNode->Fifth = NULL;
			newThirdNode->Sixth = NULL;
			newThirdNode->Parent = &_parent;
			_parent.Third = newThirdNode;

			//четвёртый ребёнок
			xF = _parent.coordF.X + sqrt(3) * side / 6 * cos(3.67);
			yF = _parent.coordF.Y + sqrt(3) * side / 6 * sin(3.67);

			xT = 7 * _width / 12;
			yT = 3 * _height / (2 * numLevel);

			tree = Point(xT, yT);
			fract = Point(xF, yF);
			_level = _parent.level + 1;
			_angle = 3.67; // 210
			Node* newFourthNode = new Node(tree, fract, _level, _angle);
			newFourthNode->First = NULL;
			newFourthNode->Second = NULL;
			newFourthNode->Third = NULL;
			newFourthNode->Fourth = NULL;
			newFourthNode->Fifth = NULL;
			newFourthNode->Sixth = NULL;
			newFourthNode->Parent = &_parent;
			_parent.Fourth = newFourthNode;

			//пятый ребёнок
			xF = _parent.coordF.X + sqrt(3) * side / 6 * cos(4.71);
			yF = _parent.coordF.Y + sqrt(3) * side / 6 * sin(4.71);

			xT = 9 * _width / 12;
			yT = 3 * _height / (2 * numLevel);

			tree = Point(xT, yT);
			fract = Point(xF, yF);
			_level = _parent.level + 1;
			_angle = 4.71; // 270
			Node* newFifthNode = new Node(tree, fract, _level, _angle);
			newFifthNode->First = NULL;
			newFifthNode->Second = NULL;
			newFifthNode->Third = NULL;
			newFifthNode->Fourth = NULL;
			newFifthNode->Fifth = NULL;
			newFifthNode->Sixth = NULL;
			newFifthNode->Parent = &_parent;
			_parent.Fifth = newFifthNode;

			//шестой ребёнок
			xF = _parent.coordF.X + sqrt(3) * side / 6 * cos(5.76);
			yF = _parent.coordF.Y + sqrt(3) * side / 6 * sin(5.76);

			xT = 11 * _width / 12;
			yT = 3 * _height / (2 * numLevel);

			tree = Point(xT, yT);
			fract = Point(xF, yF);
			_level = _parent.level + 1;
			_angle = 5.76; // 330
			Node* newSixthNode = new Node(tree, fract, _level, _angle);
			newSixthNode->First = NULL;
			newSixthNode->Second = NULL;
			newSixthNode->Third = NULL;
			newSixthNode->Fourth = NULL;
			newSixthNode->Fifth = NULL;
			newSixthNode->Sixth = NULL;
			newSixthNode->Parent = &_parent;
			_parent.Sixth = newSixthNode;
		}

		if (_parent.level > 1) {
			int tempSide = side / pow(3, _parent.level - 1);
			int tempX = _parent.coordF.X + sqrt(3) / 6 * tempSide * cos(_parent.angle);
			int tempY = _parent.coordF.Y + sqrt(3) / 6 * tempSide * sin(_parent.angle);

			int parentWidth = _width / (numElOfLvl[_parent.level]);
			int step = (parentWidth - 3 * dEllipse) / 6;

			//первый ребёнок
			xF = tempX + sqrt(3) * tempSide / 6 * cos(-0.52 + _parent.angle);
			yF = tempY + sqrt(3) * tempSide / 6 * sin(-0.52 + _parent.angle);

			xT = _parent.coordT.X - 2 * step - dEllipse;
			yT = _parent.coordF.Y + _height / (2 * numLevel);

			tree = Point(xT, yT);
			fract = Point(xF, yF);
			_level = _parent.level + 1;
			_angle = -0.52 + _parent.angle; // 30
			Node* newFirstNode = new Node(tree, fract, _level, _angle);
			newFirstNode->First = NULL;
			newFirstNode->Second = NULL;
			newFirstNode->Third = NULL;
			newFirstNode->Fourth = NULL;
			newFirstNode->Fifth = NULL;
			newFirstNode->Sixth = NULL;
			newFirstNode->Parent = &_parent;
			_parent.First = newFirstNode;

			//второй ребёнок
			xF = tempX + sqrt(3) * tempSide / 6 * cos(_parent.angle);
			yF = tempY + sqrt(3) * tempSide / 6 * sin(_parent.angle);

			xT = _parent.coordT.X;
			yT = _parent.coordF.Y + _height / (2 * numLevel);

			tree = Point(xT, yT);
			fract = Point(xF, yF);
			_level = _parent.level + 1;
			_angle = _parent.angle; // 
			Node* newSecondNode = new Node(tree, fract, _level, _angle);
			newSecondNode->First = NULL;
			newSecondNode->Second = NULL;
			newSecondNode->Third = NULL;
			newSecondNode->Fourth = NULL;
			newSecondNode->Fifth = NULL;
			newSecondNode->Sixth = NULL;
			newSecondNode->Parent = &_parent;
			_parent.Second = newSecondNode;

			//третий ребёнок
			xF = tempX + sqrt(3) * tempSide / 6 * cos(0.52 + _parent.angle);
			yF = tempY + sqrt(3) * tempSide / 6 * sin(0.52 + _parent.angle);

			xT = _parent.coordT.X + 2 * step + dEllipse;
			yT = _parent.coordF.Y + _height / (2 * numLevel);

			tree = Point(xT, yT);
			fract = Point(xF, yF);
			_level = _parent.level + 1;
			_angle = 0.52 + _parent.angle; // 30
			Node* newThirdNode = new Node(tree, fract, _level, _angle);
			newThirdNode->First = NULL;
			newThirdNode->Second = NULL;
			newThirdNode->Third = NULL;
			newThirdNode->Fourth = NULL;
			newThirdNode->Fifth = NULL;
			newThirdNode->Sixth = NULL;
			newThirdNode->Parent = &_parent;
			_parent.Third = newThirdNode;
		}
	}


public:
	Tree(int _side) {
		side = _side;
		root = NULL;
	}

	void AddNumLevel(int _level, int _width, int _height) {
		for (int i = 0; i <= _level; i++) {
			AddLevel(i, _width, _height);
		}
	}

	void PaintTreeLayer(int numLayer, Graphics^ Графика) {
		switch (numLayer) {
		case 0:
			Графика->DrawEllipse(Pens::Black, root->coordT.X - 5, root->coordT.Y - 5, 10, 10);
			break;

		}
	}

	void PaintTree(Graphics^ Графика) {
		PaintTreeLayer(0, Графика);
	}


};


}


