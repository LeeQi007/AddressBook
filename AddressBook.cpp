#include<iostream>
#include<string>
#include<ctime>
using namespace std;

//��Ҫ����������ϵ�������ɷ������ά��
#define MAX 100

void menu()
{
	cout << "****************************" << endl;
	cout << "****   1.�����ϵ�ˣ�   ****" << endl;
	cout << "****   2.ɾ����ϵ�ˣ�   ****" << endl;
	cout << "****   3.�޸���ϵ�ˣ�   ****" << endl;
	cout << "****   4.������ϵ�ˣ�   ****" << endl;
	cout << "****   5.��ʾͨѶ¼��   ****" << endl;
	cout << "****   6.���ͨѶ¼��   ****" << endl;
	cout << "****   0.������˳���   ****" << endl;
	cout << "****************************" << endl;
}


struct person
{
	string name;
	string sex;
	int age;
	//long,int�����ʮλ�������Ա���ʹ��long long���� 
	long long int phone;
	string address;
};

struct Addressbook
{
	//ͨѶ¼�ṹ���鱣��ÿ����
	struct person Parry[MAX];
	int size;
};


//�����ϵ��
void Add(Addressbook *p)
{
	if (p->size == MAX)
	{
		cout << "ͨѶ¼��������ɾ�����ڽ�����ӣ�" << endl;
		return;
	}
	else
	{
		cout << "<----------ϵͳ����:����ͬ������ӱ�ʶ����������---------->" << endl;
		//ע���ģ�鲢û�����ò�����ͬ��������������ͬ���󣬺��������������ܲ�һ��ȫ��ʵ��(��:�޸�)�����Ծ����ӱ�ʶ����������
		string name;
		cout << "����������:" << endl;
		cin >> name;
		p->Parry[p->size].name = name;

		string sex;
		cout << "�������Ա�:" << endl;
		while (true)
		{
			cin >> sex;
			if ((sex == "��") || (sex == "Ů"))
			{
				p->Parry[p->size].sex = sex;
				break;
			}
			else
			{
				cout << "��������,���������룡" << endl;
			}
		}
		

		int age;
		cout << "����������:" << endl;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 120)
			{
				p->Parry[p->size].age = age;
				break;
			}
			else
			{
				cout << "�����������������룡ע��:���䷶Χ[0,120]" << endl;
			}
		}

		long long int phone;
		cout << "��������ϵ��ʽ:" << endl;
		while (true)
		{
			cin >> phone;
			//�����ж����볤������ϲ�������ѻ����Խ����ж��ֻ����Ƿ���ȷ(���Ƿ���ǰ��λ������ͷ���ֻ���)
			//������Ƿ������ͬ�ֻ���
			if (int(log10(phone) + 1)==11)//��ʽ������볤��
			{
				p->Parry[p->size].phone = phone;
				break;
			}
			else
			{
				cout << "�ֻ����빲ʮһλ�����������룡" << endl;
			}
		}
		
		string address;
		cout << "�������ͥסַ:" << endl;
		cin >> address;
		p->Parry[p->size].address = address;

		//�������鳤��
		p->size++;
		cout << "ϵͳ��ʾ:��ϵ�˳ɹ���ӣ�" << endl;
		//�밴���������
		system("pause");
		//��������
		system("cls");
	}
}

//ɾ��ָ������ϵ��
void deletPerson(Addressbook *p)
{
	if(p->size==0)
	{
		cout << "��ϵ��Ϊ�գ�" << endl;
	}
	else
	{
		string name;
		cout << "������Ҫɾ������ϵ������:" << endl;
		cin >> name;
		for (int i = 0; i < p->size; i++)
		{
			if (name == p->Parry[i].name)
			{
				for (int j = i; j < p->size; j++)
				{
					p->Parry[j] = p->Parry[j + 1];//������ǰ�ƶ�
				}
				p->size--;//ɾ��֮����������ֵ
				cout << "ϵͳ��ʾ:��ϵ��ɾ���ɹ���" << endl;
				break;
			}
			if((name != p->Parry[i].name) && (i == p->size-1))//�Ѿ�����������������Ȼû���ҵ�ɾ���˵�����
			{
				cout << "�����ڸ���ϵ��!!!" << endl;
			}
		}
	}
	//�밴���������
	system("pause");
	//��������
	system("cls");
}

//�޸���ϵ��
void CorrectPerson(Addressbook *p)
{
	if (p->size == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	}
	else
	{
		int CorArry[5];
		string name;
		string sex;
		int age;
		long long int phone;
		string address;
		cout << "������Ҫ�޸ĵ���ϵ������:" << endl;
		cin >> name;
		for (int i = 0; i < p->size; i++)
		{
			if (p->Parry[i].name == name)
			{
				cout << "�޸�ǰ����ϵ�˵�������ϢΪ:" << endl;
				cout << "����:" << p->Parry[i].name << "\t";
				cout << "�Ա�:" << p->Parry[i].sex << "\t";
				cout << "����:" << p->Parry[i].age << "\t";
				cout << "��ϵ��ʽ:" << p->Parry[i].phone << "\t";
				cout << "��ͥסַ:" << p->Parry[i].address << endl;
				//}
				cout << "�밴�������Ա����䣬��ϵ��ʽ����ͥסַ��˳����������(1/0),1����Ҫ�޸Ĵ˴���ÿ�����ּ��Կո������" << endl;
				for (int j = 0; j < 5; j++)
				{
					cin >> CorArry[j];
				}
				for (int k = 0; k < 5; k++)
				{
					if ((CorArry[k] == 1) && (k == 0))
					{
						cout << "�������޸ĺ������:" << endl;
						cin >> name;
						p->Parry[i].name = name;
					}
					else if ((CorArry[k] == 1) && (k == 1))
					{
						cout << "�������޸ĺ���Ա�:" << endl;
						while (true)
						{
							cin >> sex;
							if (sex == "��" || sex == "Ů")
							{
								p->Parry[i].sex = sex;
								break;
							}
							else {
								cout << "������������������!" << endl;
							}
						}
					}
					else if ((CorArry[k] == 1) && (k == 2))
					{
						cout << "�������޸ĺ������:" << endl;
						while (true)
						{
							cin >> age;
							if (age > 0 && age < 120)
							{
								p->Parry[i].age = age;
								break;
							}
							else
							{
								cout << "�����������������룡" << endl;
							}
							
						}
					}
					else if ((CorArry[k] == 1) && (k == 3))
					{
						cout << "�������޸ĺ����ϵ��ʽ:" << endl;
						while (true)
						{
							cin >> phone;
							if (int(log10(phone) + 1) == 11)
							{
								p->Parry[i].phone = phone;
								break;
							}	
							else
							{
								cout << "�����������������룡" << endl;
							}
						}
					}
					else if ((CorArry[k] == 1) && (k == 4))
					{
						cout << "�������޸ĺ�ļ�ͥסַ:" << endl;
						cin >> address;
						p->Parry[i].address = address;
					}
				}
				cout << "�޸ĳɹ���" << endl;
			}
			else
			{
				cout << "�����ڸ���ϵ�ˣ�" << endl;
				break;
			}
		}
	}
	//�밴���������
	system("pause");
	//��������
	system("cls");
}


//������ϵ�˹���
void FindPerson(Addressbook *p)
{
	string name;
	int flag = 0;
	int flag1 = 0;
	if (p->size == 0)
	{ 
		flag1 = 1;
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫ���ҵ���ϵ�˵�����:" << endl;
		cin >> name;
		for (int i = 0; i < p->size; i++)
		{
			if (p->Parry[i].name == name)
			{
				flag = 1;
				cout << "����:" << p->Parry[i].name << "\t";
				cout << "�Ա�:" << p->Parry[i].sex << "\t";
				cout << "����:" << p->Parry[i].age << "\t";
				cout << "��ϵ��ʽ:" << p->Parry[i].phone << "\t";
				cout << "��ͥסַ:" << p->Parry[i].address << endl;
			}
		}
	}
	if (flag == 0 && flag1 == 0)
	{
		cout << "�����ڸ���ϵ�ˣ�" << endl;
	}

	//�밴���������
	system("pause");
	//��������
	system("cls");
}

//��ʾ��ϵ�˹���
void  showPerson(Addressbook *p)
{
	if (p->size == 0)
	{
		cout << "��ϵ��Ϊ��!!" << endl;
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			cout << "����:" << p->Parry[i].name << "\t";
			cout << "�Ա�:" << p->Parry[i].sex << "\t";
			cout << "����:" << p->Parry[i].age << "\t";
			cout << "��ϵ��ʽ:" << p->Parry[i].phone << "\t";
			cout << "��ͥסַ:" << p->Parry[i].address << endl;
		}
	}
	//�밴���������
	system("pause");
	//��������
	system("cls");
}


void CleanPerson(Addressbook *p)
{
	//��size��Ϊ�㼴�ɡ�
	int num = 0;
	cout << "ȷ������밴-->1" << endl;
	cin >> num;
	if (num == 1)
	{
		p->size = 0;
		cout << "��ϵ���Ѿ���գ�" << endl;
	}
	//�밴���������
	system("pause");
	//��������
	system("cls");
}

int main()
{
	Addressbook p;
	p.size = 0;

	while (true)
	{
		menu();
		cout << "������Ҫ����ͨѶ¼����ǰ�����:";
		int Chosenum;
		cin >> Chosenum;
		switch (Chosenum)
		{
		case 1:
			Add(&p);//���õ�ַ��������ʵ��
			break;
		case 2:
			deletPerson(&p);
			break;
		case 3:
			CorrectPerson(&p);
			break;
		case 4:
			FindPerson(&p);
			break;
		case 5:
			showPerson(&p);
			break;
		case 6:
			CleanPerson(&p);
			break;
		case 0:
			cout << "ϵͳ��ʾ:ͨѶ¼ϵͳ���˳�����ӭ����ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}