#include <iostream>
using namespace std;

class Calculator
{
	private :
		int val;
		int ans;

	public :


		Calculator():val(0),ans(0)
		{

		}
		Calculator(int value):val(value)
		{

		}

		int getValue()
		{
			return val;
		}

		void setValue(int v)
		{
		    val=v;
		}

		void add(int Value)
		{

			setValue(Value);

			ans += val;
		}

		void subtract(int Value)
		{
			setValue(Value);

			ans -= val;
		}

		void multiply(int Value)
		{
			setValue(Value);

			ans *= val;
		}

		void divideBy(int Value)
		{
			setValue(Value);
			if (val == 0)
			{
				cout << "divide by 0 is undefined" << endl;
				return;
			}
			ans /=val;
		}

		void clear()
		{
           ans=0;
		}

		void display()
		{
			cout << "Calculator display : " << ans << endl;
		}

		~Calculator()
        {
            cout << "Calculator object is destroyed."<<endl;
        }
};

int main()
{
	Calculator c;

     c.add(5);
     c.display();
     c.subtract(3);
     c.display();
     c.multiply(4);
     c.display();
     c.divideBy(2);
     c.display();
     c.clear();

	return 0;
}
