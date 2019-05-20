#include "GameField.h"
using namespace System::Drawing::Drawing2D;

void GameField::CreateDblBuff()
{
	BufferedGraphicsContext^ bgc =
		BufferedGraphicsManager::Current;
	bg = bgc->Allocate(mainG, Rectangle(0, 0, w, h));
	g = bg->Graphics;
}

Point GameField::GetCell(int x, int y)
{
	Box b(w, h, Rows, Cols);
	Point p(-1, -1);
	if (x >= b.dx && y >= b.dy && x < b.w + b.dx &&y < b.h + b.dy)
	{
		p.Y = (x - b.dx)/b.wsz;
		p.X = (y - b.dy)/b.hsz;
	
	}
	return p;
}

void GameField::PaintCell(Rectangle r, Color c)
{
	LinearGradientBrush^ lb;
	/*if (status)
	{
		lb = gcnew LinearGradientBrush(
			r, 
			Color::OrangeRed, 
			Color::Coral, 
			90);
	} else
	{
		lb = gcnew LinearGradientBrush(
			r,
			Color::LightGray,
			Color::Gray,
			90
		);
	}*/
	lb = gcnew LinearGradientBrush(
		r,
		c,
		c,
		90);

	Threading::Monitor::Enter(lock);
	g->FillRectangle(lb, r);
	Threading::Monitor::Exit(lock);
}

void GameField::Start()
{
	while (started)
	{
		NextGeneration();
		Threading::Thread::Sleep(speed);
	}
}

GameField::GameField(int _w, int _h, Graphics^ g): 
mainG(g), w(_w), h(_h)
{
	CreateDblBuff();
}

GameField::GameField(int rows, int cols, int _w, int _h, Graphics^ g):
GameModel(rows, cols), mainG(g), w(_w), h(_h)
{
	CreateDblBuff();
}

void GameField::Paint()
{
	Threading::Monitor::Enter(lock);
	g->Clear(Color::White);
	Threading::Monitor::Exit(lock);
	Pen^ p = gcnew Pen(Color::Gray);
	Box b(w, h, Rows, Cols);
	for (int i = b.dy; i<b.h+b.dy; i+=b.hsz)
	{
		for (int j = b.dx; j<b.w+b.dx; j+= b.wsz)
		{
			Rectangle r(j+1, i+1, b.wsz-1, b.hsz-1);
			Point cell = GetCell(j, i);
		//	Field[cell.X, cell.Y] = true;
			PaintCell(r, Field[cell.X, cell.Y]);
		}
	}
	Threading::Monitor::Enter(lock);
	bg->Render();
	Threading::Monitor::Exit(lock);
}

void GameField::ChangeState(int x, int y,Color c)
{
	Point p = GetCell(x, y);
	if (p.X != -1 && p.Y != -1)
	{
		Field[p.X, p.Y] = c;
		Paint();
	}
}

void GameField::NextGeneration()
{
	GameModel::NextGeneration();
	Paint();
}

void GameField::StartLife()
{
	if (!started){
		Threading::ThreadStart^ ts = //поток 
			gcnew Threading::ThreadStart(
				this, 
				&GameField::Start
			);
		t = gcnew Threading::Thread(ts);
		t->Start();
		started = true;
	}
}

void GameField::StopLife()
{
	started = false;
	try {
		t->Abort();
		t->Join();
	} catch (...)
	{
		
	}
}

GameField::~GameField()
{
	StopLife();
}

void GameField::Update(int width, int height, Graphics^ graphics)
{
	try {
		w = width;
		h = height;
		mainG = graphics;
		CreateDblBuff();
		Paint();
	}
	catch (...) {}
}
