#pragma once
#include "GameModel.h"
using namespace System;
using namespace System::Drawing;

ref class GameField: public GameModel
{
	Object^ lock = gcnew Object();
	Graphics^ mainG;//�������� (�������) �����
	Graphics^ g; //����� � ������
	BufferedGraphics^ bg;//�����
	int w, h;
	void CreateDblBuff();
	Point GetCell(int i, int j);
	void PaintCell(Rectangle r, Color c);
	void Start();
	bool started = false;
	Threading::Thread^ t;
	value struct Box
	{
		int dx, dy; //����� ���� �� ������ ���������
		int w, h; //�������� ������ � ������ ����
		int wsz, hsz;// ������ � ������ ������ �� ����
		Box(int w, int h, int rows, int cols)
		{
			wsz = w / cols;
			hsz = h / rows;
			this->w = wsz * cols;
			this->h = hsz * rows;
 			dx = (w - this->w)/2;
			dy = (h - this->h)/2;
		}
	};
public:
	int speed;
	GameField(int w, int h, Graphics^ g);
	GameField(int rows, int cols, int w, int h, Graphics^ g);
	//���������� �������� ��������� �������� ����
	void Paint();
	void ChangeState(int x, int y,Color c);//������ ����
	void NextGeneration() override;
	void StartLife();
	void StopLife();
	~GameField();
	void Update(int width, int height, Graphics^ graphics);
};

