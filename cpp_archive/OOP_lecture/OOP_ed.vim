
-----------------------------------------------------------------------------------



-----------------------------------------------------------------------------------



-----------------------------------------------------------------------------------



-----------------------------------------------------------------------------------
170502_화

# 가상함수를 가진 기본클래스의 목적
	


# 가상함수 오버라이딩



# 추상클래스와 순수가상함수

class Shape{                           // 추상클래스
	public:
		virtual void draw() = 0;
};



class Circle : public Shape{            // 추상클래스
	public:
		string toString() { return "Circle 객체"; }
};



class Circle2 : public Shape{           // 추상클래스 아님
	public:
		virtual void draw(){
			cout << "circle";
		}
		string toString() { return "Circle 객체"; }
};

















-----------------------------------------------------------------------------------
170501_월

# 가상함수와 추상클래스
	# Virtual Function  &  Function Overriding
		# 오버로딩과 오버라이딩의 차이점
	    	Overloading  <==>  Overriding

		# Overriding의 목적 :

		# 파생클래스의 virtual 키워드는 생략가능하다

		# 동적바인딩
			# 실행시간까지 함수의 바인딩을 미루는것
			# virtual 함수의 특성

		# 범위지정연산자(::)
			# 정적바인딩을 호출한다. 
			# 기본클래스의 가상함수를 사용하고 싶을 때 사용한다



# 가상소멸자
	ex) virtual ~Base();
	    virtual ~Derived();

		Base *p = new Derived();
		delete p;

	# ~Base() 소멸자 호출 --> ~Derived() 실행 --> ~Base() 실행
	# 복잡한 상속관계에서 소멸자 오류발생을 막을 수 있다		









$ 중간고사 점검
	$ p261 10번문제(중간고사 16번문제) : 문제가 약간 애매해서 전부 맞게 처리해줬다



-----------------------------------------------------------------------------------
170418_화

# 페르마의 마지막 정리 
	# 페르마가 자신의 책에 마지막장에 x^n + y^n = z^n 의 증명을 풀었으나 용지가 없어서 싣지는 않겠다고 함
	# 350년정도 된 문제
	# 앤드류 와일스에 의해 증명되었다





$ 중간고사 25 화 저녁 7시 공학관별관 217호 2시간 


-----------------------------------------------------------------------------------
170417_월

# 8장 고고


# 상속과 객체 포인터
	# 업-캐스팅 up-casting
		# 파생클래스 포인터가 기본클래스 포인터에 치환되는 것

	# 다운-캐스팅 down-casting
		# 기본클래스 포인터가파생클래스 포인터에 치환되는 것


	# protected 멤버에 대한 접근





# pdf 질문 2개! 잘 보기
	# 상속관계의 생성자와 소멸자의 실행
	


-----------------------------------------------------------------------------------
170411_화

!! 4/25(화) 저녁 7시에 시험본다 
	! 공학관 별관 217호








-----------------------------------------------------------------------------------
170410_월


# 7장 프렌드와 연산자 중복

	# 프렌드의 의미

	# 연산자중복 operator overide

		# c++의 다형성 성질을 가진다
		# 반드시 클래스와 관계를 가진다

	ex) 
		class Power
		{
			int kick;
			int punch;
		public:
			Power(int kick = 0, int punch =0)
			{
				this->kick = kick;
				this->punch = punch;
			}
			Power operator+(Power op2);
			Power operator+=(Power op2);
		};

		// 연산자중복
		Power Power::operator(Power op2)
		{
			Power tmp;
			tmp.kick = this->kick + op2.kick;
			tmp.punch = this->punch + op2.punch;
			return tmp;
		}

		# c = a+b 의 경우 --> 컴파일러는 c = a.+(b) 로 해석한다
		  c = a+=b 구문 오류 없다!
		  






$$ 5장 과제 : p305 실습 2
	$ 5/2 (화)까지 4장 문제랑 같이 제출하기


!! 중간고사는 7장까지
	! 개념을 잘 파악하기
	! 문제는 20문제 
		! 4지선다, 코딩 내용을 분석하기, 코딩을 채우는 내용 등등

	! 5/2일(화) 시험 2시간






-----------------------------------------------------------------------------------
170403_월

# 함수 오버라이딩
	# 파라미터가 달라야 한다

	int sum(int a, int b)
	double sum(double a, double b)

	int big(int a, int b)
	int big(int a[], int size)



# 디폴트 매개변수
	int sum(int a = 10, int b = 20)










-----------------------------------------------------------------------------------
170328_화

# 얕은 복사와 깊은 복사
# 복사 생성자

	# 얕은 복사
		Circle::Circle(Circle& c)  // 복사 생성자
		{
			this->radius = c.radius;
			cout << "복사 생성자 실행 radius = " << radius << endl;
		}

	# 깊은 복사
		Person::Person(Person& person)  // 복사 생성자 
		{
			this->id = person.id; 					// id 값 복사
			int len = strlen(person.name);			// name의 문자 개수
			this->name = new char [len+1]; 			// name을 위한 공간 핟당
			strcpy(this->name, person.name); 		// name의 문자열 복사
			cout << "복사 생성자 실행. 원본 객체의 이름 " << this->name << endl;
		}




	$$ p206 4번 문제 풀어보기
		$ 2주 뒤에 제출하기 4/11(화)까지









-----------------------------------------------------------------------------------
170327_월

# 값에 의한 호출 <==> 주소에 의한 호출
	void swap(int a, int b)
	void swap(int *a, int *b)


# 객체 치환 및 객체 리턴
	Circle getCircle()
	{
		Circle tmp(30);
		return tmp;
	}


# 참조자 &
	# 주로 call by reference를 위해 사용한다
	void increaseCircle(Circle &c)
	{
		int r = c.getRadius();
		c.setRadius(r+1);
	}


	# 참조 리턴
		char& find(char s[], int index)
		{
			return s[index];
		}

		int main()
		{
			char name[] = "Mike";
			cout << name << endl;
			
			find(name,0) = 'S';    // 이런 문법이 가능하다

			char& ref = find(name,2);
			ref = 't';
			cout << name << endl;
		}








-----------------------------------------------------------------------------------
170321_화

# 1024크기 만큼 메모리 누수 발생한다
	char n = 'a';
	char *p = new char[1024];
	p = &n;


# this 포인터
	this->radius = radius;
	또는
	return this;



# string 클래스
		#include <string>
		using namespace std;
		string str = "I love ";
		str.append("C++");
	
	# 문자열 복사
		string address("abcdef");
		string copyAddress(address);
	
		char text[] = {'L','o','v','e',',','C','+','+','\0'};
		string title(text);

	# 문자열 --> 숫자 변환
		string s = "123";
		int n = stoi(s);

		string *p = new string("C++");
		cout << *p;
		p->append(" good man");
		delete p;


	# getline() 함수로 string을 입력받는다

	string names[5]; // 문자열 배열 선언
	for(int i=0; i<5; i++) 
	{
		cout << "이름 >> ";
		getline(cin, names[i], '\n');
	}

	string latter = names[0];

	for(int i=1; i<5; i++) 
	{
		if(latter < names[i]) // 사전 순으로 latter 문자열이 앞에 온다면
		{ 
			latter = names[i]; // latter 문자열 변경
		}
	}
	cout << "사전에서 가장 뒤에 나오는 문자열은 " << latter << endl;















-----------------------------------------------------------------------------------
170320_월

# 포인터는 c와 거의 똑같다

# 객체 배열
	Circle circleArray[3]; 
		# 항상 파라미터가없는 생성자가 호출된다


# 동적메모리 할당
	# malloc, free ==> new, delete
	







-----------------------------------------------------------------------------------
170314_화


# 지역객체와 전역객체 
	# 소멸자의 소멸 순서


# 캡슐화
	# 접근지정자
		# private :
		# public :
		# protected :


# inline  인라인 함수
	# 오버헤드를 막을 수 있다 
	# 컴파일러에 의해 함수의 코드가 main에(주로) 삽입된다

inline int odd(int x)
{ ... }




# struct 구조체
	# c언어와 호환성을 위해 그대로 사용한다
	# 클래스와 똑같이 private, public 작성 가능하다
		# 기본 접근지정자는 public이다 (class는 private)

	
# 아래 구문을 이용해 중복호출을 막는다
	#ifndef CIRCLE_H
	#define CIRCLE_H
	...
	#endif




	$ p145 실습문제 4 
	  p147 실습문제 8
	  결과값이 의미하는 건 뭐다
	
	$ 프린트로 2주 뒤 28일_화 까지 제출













-----------------------------------------------------------------------------------
170313_월

# Object Oriented Programming 객체지향 프로그래밍
	# 캡슐화

	# class 클래스
		# 멤버변수
		# 멤버함수



	







-----------------------------------------------------------------------------------
170307_화

# 임베디드 시스템이란
	# 프로그래밍하는 host와 실제 사용할 target이 다르다


# cin.getline() 을 이용해 문자열을 입력받을 수 있다
	
	int main()
	{
		cout << "주소를 입력하세요" << endl;

		char address[100];
		cin.getline(address, 100, '\n');

		cout << "주소는 " << address << " 입니다\n";

		return 0;
	}



# iostream.h 는 구버전 c++의 헤더파일이다



















