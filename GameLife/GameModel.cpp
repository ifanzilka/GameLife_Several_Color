#include "GameModel.h"

void GameModel::RecreateArray()
{
	field = gcnew array<Color, 2>(rows, cols);

	
}
void GameModel::SetColor() //задает цвет всем элементам
{
	
	for (int i = 0; i < this->Rows; i++) {
		for (int j = 0; j < this->Cols; j++) {
			Field[i, j] = dead;
		}

	}

}
Color GameModel::ThreeColor(Color a, Color b, Color c)//слияние 3 цветов
{
	int alph = (a.A + b.A + c.A) / 3;
	int blue = (a.B+b.B+c.B)/3;
	int red = (a.R + b.R + c.R) / 3;
	int green = (a.G + b.G + c.G) / 3;
	Color color = Color::FromArgb(alph,red, green, blue);//цвет образуется от трех параметров зеленый красныйй синий ,значения от 0-255 это интенсивность каждого из цветов
	return color;

}
Color GameModel::TwoColor(Color a, Color b)//слияние 2 цветов
{
	int alph = (a.A + b.A) / 2;
	int blue = (a.B + b.B ) / 2;
	int red = (a.R + b.R ) / 2;
	int green = (a.G + b.G ) / 2;
	Color color = Color::FromArgb(alph, red, green, blue);//цвет образуется от трех параметров зеленый красныйй синий ,значения от 0-255 это интенсивность каждого из цветов
	return color;

}
Color GameModel::GetNextColor(int i, int j)//цвет на сдеж уровне
{
	int kolvocolor = 0;
	array<Color, 1>^ mas;
	int nc = GetAliveNeighbourCount(i, j);//кол во живых клеток

	if (Field[i, j] != dead && (nc == 2 || nc == 3))
	{

		mas = gcnew array<Color, 1>(3);
		for (int m = 0; m < 8; m++) {

			if (GetNeighbourStatus(i, j, m) != (Color::Gray) && kolvocolor < 3) {
				mas[kolvocolor] = GetNeighbourStatus(i, j, m);
				kolvocolor++;
			}

		}

		if (nc == 3) {
			return ThreeColor(mas[0], mas[1], mas[2]);
		}
		else {
		
			return TwoColor(mas[0], mas[1]);
		
		}
	}
	else {

		if (nc == 3) {
			mas = gcnew array<Color, 1>(3);
			for (int m = 0; m < 8; m++) {

				if (GetNeighbourStatus(i, j, m) != (Color::Gray) && kolvocolor < 3) {
					mas[kolvocolor] = GetNeighbourStatus(i, j, m);
					kolvocolor++;
				}

			}
			return ThreeColor(mas[0], mas[1], mas[2]);
		}
		else {
			return dead;
		}
				
			}
			
		}


Color GameModel::GetNeighbourStatus(int i, int j, int k)
{
	int pi = ((i-1)>=0)?i-1:(rows-1);
	int ni = ((i+1)<(rows))?(i+1):0;
	int pj = ((j-1)>=0)?j-1:(cols-1);
	int nj = ((j+1)<(cols))?(j+1):0;

	switch (k)
	{
	case 0: return Field[pi, pj];
	case 1: return Field[pi, j];
	case 2: return Field[pi, nj];
	case 3: return Field[i, pj];
	case 4: return Field[i, nj];
	case 5: return Field[ni, pj];
	case 6: return Field[ni, j];
	case 7: return Field[ni, nj];
	default: return (dead);
	}
}

int GameModel::GetAliveNeighbourCount(int i, int j)
{
	int cnt = 0;
	for (int k = 0; k < 8; k++)
	{
		if (GetNeighbourStatus(i, j, k)!=(dead)) cnt++;
	}
	return cnt;
}

void GameModel::NextGeneration()
{
	array<Color, 2>^ newGen = 
		gcnew array<Color, 2>(rows, cols);
	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			newGen[i, j] = GetNextColor(i, j);
		}
	}
	field = newGen;
}

GameModel::GameModel()
{
	SetSize(20, 20);
	SetColor();
}

GameModel::GameModel(int rows, int cols)
{
	
	SetSize(rows, cols);
	SetColor();
}

void GameModel::SetSize(int rows, int cols)
{
	bool changed = false;
	if (rows<10) rows = 10;
	else if (rows>100) rows = 100;
	if (rows!=this->rows){
		changed = true;
		this->rows = rows;
	}
	if (cols<10) cols = 10;
	else if (cols>100) cols = 100;
	if (cols!=this->cols){
		changed = true;
		this->cols = cols;
	}
	if (changed) RecreateArray();
}
