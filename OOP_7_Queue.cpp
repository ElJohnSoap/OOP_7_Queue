#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
class Queue
{
	
	int* Wait; //Очередь
	
	int MaxQueueLength; //Максимальный размер очереди
	
	int QueueLength;//Текущий размер очереди

public:
	
	Queue(int m);//Конструктор
	
	~Queue();//Деструктор
	
	void Add(int c);//Добавление элемента
	
	int Extract();//Извлечение элемента
	
	void Clear();//Очистка очереди
	
	bool IsEmpty();//Проверка существования элементов в очереди
	
	bool IsFull();//Проверка на переполнение очереди
		
	int GetCount();//Количество элементов в очереди
	
	void Show();//демонстрация очереди
};

Queue::Queue(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new int[MaxQueueLength];
	//Изначально очередь пуста
	QueueLength = 0;
}

void Queue::Show() //демонстрация очереди
{
	cout << "\n-----------------------------------\n";
	
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n-----------------------------------\n";
}
Queue::~Queue()//удаление очереди
{
	
	delete[]Wait;
}

void Queue::Clear()
{
	//Эффективная "очистка" очереди
	QueueLength = 0;
}

bool Queue::IsEmpty()
{
	//Пуст?
	return QueueLength == 0;
}
bool Queue::IsFull()
{
	//Полон?
	return QueueLength == MaxQueueLength;
}

int Queue::GetCount()
{
	//Количество присутствующих в стеке элементов 
	return QueueLength;
}
void Queue::Add(int c)
{
	//Если в очереди есть свободное место,
	//то увеличиваем количество
	//значений и вставляем новый элемент 
	if (!IsFull())
		Wait[QueueLength++] = c;
}
int Queue::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь 
	if (!IsEmpty()) {
		//запомнить первый
		int temp = Wait[0];
		//сдвинуть все элементы
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];

			//уменьшить количество
			QueueLength--;
		//вернуть первый(нулевой)
		return temp;
	}
	else //Если в стеке элементов нет
		return -1;
}
void main()
{
	srand(time(0));
	//создание очереди
	Queue QU(25);
	//заполнение части элементов
	for (int i = 0; i < 5; i++) {
		QU.Add(rand() % 50);
	}
	//показ очереди
	QU.Show();
	//извлечение элемента
	QU.Extract();
	//показ очереди
	QU.Show();
}
