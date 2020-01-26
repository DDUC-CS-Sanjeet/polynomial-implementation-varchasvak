#include<iostream>
using namespace std;
class Polynomial
{
  private:
    // Variables to store information about polynomial
    int deg;
    int *coefficient;
  public:
    Polynomial()
    {
      // Behavior of default constructor
      deg = 0;
      coefficient = new int[1];
      coefficient[0] = 0;
    }
    Polynomial(int deg)
    {
      // Behavior of constructor with arguments
      this->deg = deg;
      coefficient = new int[deg+1];
    }
    ~Polynomial()
    {
      // Behavior of destructor
        cout<<"Destructor Called\n";
    }
    //  Overload copy constructor, +, - and = operators
    Polynomial(const Polynomial &obj)
    {
        deg = obj.deg;
        coefficient = new int[deg+1];
        for(int i=0;i<deg+1;i++)
        coefficient[i]=obj.coefficient[i];
    }
    // Overloaded + operator
    Polynomial operator+(const Polynomial &obj)
    {
       int max_deg = max( deg,obj.deg );
       int min_deg = min( deg,obj.deg );
       int i=max_deg, j=min_deg;
       Polynomial sum(max_deg);
       if( deg == obj.deg )
       {
         while( i>=0 )
         {
           sum.coefficient[i] = coefficient[i] + obj.coefficient[i];
           i--;
         }
       }
       else if( deg > obj.deg )
       {    
          while( j>=0 )
          {
            sum.coefficient[i] = coefficient[i] + obj.coefficient[j]; 
            i--;
            j--;
          }
          while( i>=0 )
          {
            sum.coefficient[i] = coefficient[i];
            i--;
          }
       }
       else
       {
         while( j>=0 )
          {
            sum.coefficient[i] = coefficient[j] + obj.coefficient[i]; 
            j--;
            i--;
          }
          while( i>=0 )
          {
            sum.coefficient[i] = obj.coefficient[i];
            i--;
          }
       }
       return sum;  
    }
    // Overloaded - operator
    Polynomial operator-(Polynomial &obj)
    {
       int max_deg = max( this->deg,obj.deg );
       int min_deg = min( this->deg,obj.deg );
       int i=max_deg, j=min_deg;
       Polynomial diff(max_deg);
       if( this->deg == obj.deg )
       {
          while( i>=0 )
         {
         diff.coefficient[i] = coefficient[i] - obj.coefficient[i];
           i--;
         }
       }
       else if( deg > obj.deg )
       {    
          while( j>=0 )
          {
         diff.coefficient[i] = coefficient[i] - obj.coefficient[j]; 
            i--;
            j--;
          }
          while( i>=0 )
          {
            diff.coefficient[i] = coefficient[i];
            i--;
          }
       }
       else
       {
         while( j>=0 )
          {
            diff.coefficient[i] = coefficient[j] - obj.coefficient[i]; 
            j--;
            i--;
          }
          while( i>=0 )
          {
         diff.coefficient[i] = -obj.coefficient[i];
            i--;
          }
       }
       return diff;  
    }
    // Overloaded = operator
    void operator=(const Polynomial &obj)
    {
        deg = obj.deg;
        coefficient = new int[deg+1];
        for(int i=0; i<=deg; i++)
        {
          coefficient[i] = obj.coefficient[i]; 
        }
    }
    void storePolynomial()
    {
      //  Code to enter and store polynomial
      int temp_deg = deg;
      for(int i=0; i<=deg; i++)
      {
        cout<<"\nEnter coefficient of (X^"<<temp_deg--<<")";
        cin>>coefficient[i];
      }
      cout<<"\n";
    }
    void display()
    {
      //  Code to print the polynomial in readable format
      int temp_deg = deg;
      for(int i=0; i<=deg; i++)
      {
          cout<<"("<<coefficient[i]<<"X^"<<temp_deg--<<")";
          if(!(temp_deg<0))
          {
              cout<<" + ";
          }
      }
      cout<<"\n";
    }
};
int main()
{
  int degFirst, degSecond;
  // Ask user to input the values of degFirst and degSecond 
  cout<<"Enter deg of first polynomial ";
  cin>>degFirst;
  cout<<"\nEnter deg of second polynomial ";
  cin>>degSecond;
  Polynomial firstPolynomial(degFirst);
  Polynomial secondPolynomial(degSecond);
  Polynomial thirdPolynomial;
  cout<<"Enter first polynomial\n";
  firstPolynomial.storePolynomial();
  cout<<"\nEnter second polynomial\n";
  secondPolynomial.storePolynomial();
  thirdPolynomial=firstPolynomial+secondPolynomial;
  Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  cout<<"\nFirst polynomial =>";
  firstPolynomial.display();
  cout<<"\nSecond polynomial =>";
  secondPolynomial.display();
  cout<<"\nThird polynomial =>";
  thirdPolynomial.display();
  cout<<"\nFourth polynomial =>";
  fourthPolynomial.display();
  return 0;
}