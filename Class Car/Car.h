
const int N = 20;
const int M = 4;

class Car
{
public:
	Car();
	~Car();
	void SetModel(char*);
	void SetColor(char*);
	void SetSirealNumber(char*);
	void SetRelease(int);
	void SetInspection(char*);
	void SetValue(char*);
	void SetCar(char*, char*, char*, int, char*, char*);
	char* GetModel();
	char* GetColor();
	char* GetSirealNumber();
	int GetRelease();
	char* GetInspection();
	char* GetValue();
	void DisplayCar();
	void SetKey(int);
	int GetKey();
	void DisplayKey();
private:
	char model[N], color[N], mk[N], yinsp[N], val[N];
	int key, yrel;
};

