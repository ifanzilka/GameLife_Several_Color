#pragma once
using namespace System;
using namespace System::Drawing;
ref class GameModel
{
	//���������� ������ �� ������ � ������
	int cols, rows;//������� ����
	//������ �������� ������
	array<Color, 2>^ field;
	Color dead = Color::Gray;//���� ������� ������
	void RecreateArray();
	void SetColor();//������ ���� ���� ���������
	Color ThreeColor(Color a, Color b, Color c);//������� 3 ������
	Color TwoColor(Color a, Color b);//������� 2 ������
	Color GetNextColor(int i, int j);//���� �� ���� ������
	Color GetNeighbourStatus(int i, int j, int k);//���� ������ k
	int GetAliveNeighbourCount(int i, int j);
public:
	virtual void NextGeneration();
	property int Cols
	{
		int get()
		{
			return cols;
		}
		void set(int value)
		{
			SetSize(rows, value);
		}
	}
	property int Rows
	{
		int get()
		{
			return rows;
		}
		void set(int value)
		{
			SetSize(value, cols);
		}
	}
	property Color Field[int, int]
	{
		
		Color get(int i, int j)
		{
			if (i>=0 && j>=0 && i<rows && j<cols)
			{
				return field[i, j];
			}
			return (Color::Gray);
		}
		void set(int i, int j, Color v)
		{
			if (i>=0 && j>=0 && i<rows && j<cols)
			{
				field[i, j] = v;
			}
		}
	}
	GameModel();
	GameModel(int rows, int cols);
	void SetSize(int rows, int cols);
};

