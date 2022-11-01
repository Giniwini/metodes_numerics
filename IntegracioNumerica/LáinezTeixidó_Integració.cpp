#include <iostream>
#include <math.h>
#include<fstream>
#include<conio.h>
#include<iomanip>

using namespace std;

//definim la funció que volem integrar
double k(double X, double MU){
double k=1/sqrt(1-MU*pow(sin(X),2));
}

int main()
{double g, L, b, w,e, x=0, mu, r,  s, d;
	int j, i, N=4, n, m, Nmax;
	
cout<<setprecision(12);	
ofstream Hey;
Hey.open("LainezTeixido.txt");


cout<<"introdueix el valor de g"<<endl;cin>>g;
Hey<<"introdueix el valor de g   "<<endl<<g<<endl;

cout<<"introdueix la longitud del pendul"<<endl;cin>>L;
Hey<<"introdueix la longitud del pendul"<<endl<<L<<endl;

cout<<"introdueix el valor del angle inicial en radiants"<<endl;cin>>b;
Hey<<"introdueix el valor del angle inicial en radiants"<<endl<<b<<endl;

cout<<"introdueix el nombre d'iteracions n fins el qual arribara Romberg. Rnxn"<<endl;cin>>n; double h[n], S[n], R[n][n];
Hey<<"introdueix el nombre d'iteracionsn fins el qual arribara Romberg. Rnxn"<<endl<<n<<endl;

cout<<"introdueix el nombre de divisions maxim del trapezi  "<<endl; cin>>Nmax; cout<<endl<<endl; double T[Nmax+1];
Hey<<"introdueix el nombre de divisions maxim del trapezi  "<<endl<<Nmax<<endl;

cout<<"introdueix el valor de l'error"<<endl;cin>>e;
Hey<<"introdueix el valor de l'error   "<<endl<<e<<endl;


 mu=pow(sin(b/2),2);	
	
              //MÉTODE DELS TRAPEZIS
			  
			  
T[N-1]=0;
T[N-2]=0;
T[N]=0;			  
 while (fabs(T[N-2]-T[N-1])>=e*(T[N-1]+T[N])*0.5 and Nmax+1>=N ) {
	s=0;x=0;	  	

	d=3.141592653589793/(2*N);
	for (j=1; j<N; j++){
			
		s=s+k(x,mu)	;
		x=x+d	;	}	
		
	T[N]=((1+k(3.141592653589793/2,mu)+2*s)/2)*d; 
	Hey<<N<<T[N]*4*sqrt(L/g)<<endl<<endl<<endl<<endl;
	N=N+1; } 	

if(N-2==Nmax){cout<<"Hem arribat al nombre maxim de divisions del trapezi sense arribar a la tolerancia que has dit"<<endl;
Hey<<"Hem arribat al nombre maxim de divisions del trapezi sense arribar a la tolerancia que has dit"<<endl;}
	
cout<<"El periode pel metode dels trapezis val  "<<T[N-2]*4*sqrt(L/g)<<" s"<<endl<<endl<<endl;
Hey<<"El periode pel metode dels trapezis val  "<<T[N-2]*4*sqrt(L/g)<<" s"<<endl<<endl<<endl;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	

	
              //MÉTODE DE ROMBERG
              
N=N-2;	 
	//ens definim les diferents h[i] amb les que farem el métode dels trapezis per aconseguir T(h), T(h/2), T(h/4)...
	for (i=1; i<=n; i++){
	 h[i]=3.141592653589793/(pow(2,i)*N);	
	 
	 S[i]=0; x=0;
	//utilitzem el métode dels trapezis per a calcular diferents T(h[i])
	for (j=1; j<N*pow(2,i-1); j++){
			
		S[i]=S[i]+k(x,mu)	;
		x=x+h[i]	;	}	
		
	R[i][1]=((1+k(3.141592653589793/2,mu)+2*S[i])/2)*h[i];    	}
	
	//calculem, combinant T(h), T(h/2), T(h/4)... amb el métode de Romberg les nostres integrals R amb un error menor.  
	for (j=2; j<=n; j++){
	for (m=j; m<=n; m++){
		R[m][j]=(pow(4, j-1)*R[m][j-1]-R[m-1][j-1])/(pow(4, j-1)-1)	;	     	}}
	
	//Donem les nostres integrals R en forma de matriu triangular per qüestions estètiques. 
	for (m=1; m<=n; m++){
	for (j=1; j<=m; j++){
	cout<<R[m][j]*4*sqrt(L/g)<<"  "; Hey<<R[m][j]*4*sqrt(L/g)<<"  ";   }     
	     cout<<endl;Hey<<endl;        	}
	
	cout<<endl<<endl<<"el Periode pel metode de Romberg resulta   "<<R[n][n]*4*sqrt(L/g)<<" s";
	Hey<<endl<<endl<<"el Periode pel metode de Romberg resulta   "<<R[n][n]*4*sqrt(L/g)<<" s";
	     
	     Hey.close();
		cin.ignore(); return 0;} 
		
		
	//falta saber que és l'error dels collons i crear un fitxer on també surtin la resposta
