#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// Пример с задачата за N триъгълника.

struct Point {
	int x;
	int y;
};

struct Triangle {
	Point A;
	Point B;
	Point C;
};

void EnterPoint(Point& point) {
	cin >> point.x;
	cin >> point.y;
}

void EnterTriangles(size_t n, Triangle* triangles) {
	for (int i = 0; i < n; i++) {
		EnterPoint(triangles[i].A);
		EnterPoint(triangles[i].B);
		EnterPoint(triangles[i].C);
	}
}

double CalcSide(const Point& A, const Point& B) {
	int dx = abs(A.x - B.x);
	int dy = abs(A.y - B.y);
	return sqrt(dx * dx + dy * dy);
}

double CalcAreaTriangle(const Triangle& triangle) {
	
	// Heron
	// sqrt(p * (p-a) * (p-b) * (p-c))

	double a = CalcSide(triangle.A, triangle.B);
	double b = CalcSide(triangle.B, triangle.C);
	double c = CalcSide(triangle.C, triangle.A);
	double p = (a + b + c) / 2;

	return sqrt(p * (p - a) * (p - b) * (p - c) );
}

void Evaluate(size_t n, Triangle* triangles) {
	double* areas = new double[n];
	
	for (int i = 0; i < n; i++) {
		areas[i] = CalcAreaTriangle(triangles[i]);
		//cout << areas[i] << endl;
	}

	for (int i = 0; i < n; i++) {
		int minIndex = i;
		for (int k = i + 1; k < n; k++) {
			if (areas[i] > areas[k]) {
				minIndex = k;
			}
		}

		if (minIndex != i) {
			std::swap(areas[i], areas[minIndex]);
			std::swap(triangles[i], triangles[minIndex]);
		}
	}

	delete[] areas;
}

void PrintPoint(const Point& point) {
	cout << point.x << " " << point.y << " ";
}

void PrintTriangle(const Triangle& triangle) {
	PrintPoint(triangle.A);
	PrintPoint(triangle.B);
	PrintPoint(triangle.C);
	cout << endl;
}

void Print(size_t n, Triangle* triangles) {
	for (int i = 0; i < n; i++) {
		PrintTriangle(triangles[i]);
	}
}

//Bonus
struct Line
{
	Point p1;
	Point p2;
};

double CalcSlope(const Line& l) {
	double dy = l.p1.y - l.p2.y;
	double dx = l.p1.x - l.p2.x;
	if (dx == 0)
		return 0;

	return abs(dy / dx);
	// double cna be +inf, -inf or NaN (int cannot be those things)
}

const static double error = 0.0001;
bool AreEqualDoubles(double d1, double d2) {
	return (d1 - d2) > error;
}

bool areParallel(const Line& p1, const Line& p2){
	double slope1 = CalcSlope(p1);
	double slope2 = CalcSlope(p2);
	
	return AreEqualDoubles(slope1, slope2);
}

int main()
{
	size_t n;
	cin >> n;

	/* Input Data:
		3
		10 20 20 10 30 30
		100 200 200 100 300 300
		1 2 2 1 3 3
	*/

	Triangle* triangles = new Triangle[n];
	EnterTriangles(n, triangles);

	Evaluate(n, triangles);

	Print(n, triangles);
	delete[] triangles;

	//Test of areParellel
	//Line l1 { Point{ 0, 0}, Point{ 1, 1} };
	//Line l2 { Point{ 2, 2}, Point{ 4, 4} };
	//cout << areParallel(l1, l2);

	return 0;
}
