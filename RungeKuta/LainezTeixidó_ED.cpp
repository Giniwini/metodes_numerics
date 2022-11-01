#include <iostream>
#include <math.h>
#include<fstream>
#include<conio.h>
#include<iomanip>

using namespace std;

//definim el sistema d'equacions diferencials

double b, r, sigma, Tmax; int N;


double x1(double x, double y){
return sigma*(y-x);
}

double y1(double xa, double ya, double za){
return xa*(r-za)-ya;
}

double z1(double xb,double yb,double zb){
return xb*yb-b*zb;
}



int main()
{	

int o;
cout<<"Si vols resoldre el sistema pel Metode d'Euler, prem 1. Si el vols resoldre per Runge-Kutta, prem 2.   "; cin>>o;


cout<<"Put the b value  "; cin>>b;
cout<<"Put the r value  "; cin>>r; 
cout<<"Put the sigma value  "; cin>>sigma;
cout<<"Put the Tmax value  "; cin>>Tmax; 
cout<<"Put the N value  "; cin>>N; 

	int i, j;
	double h, y[N+1], x[N+1], z[N+1];
	
cout<<"Put the initial x value  "; cin>>x[1]; 	
cout<<"Put the initial y value  "; cin>>y[1];
cout<<"Put the initial z value  "; cin>>z[1];	


cout<<setprecision(12);	
ofstream Yep;
Yep.open("LainezTeixidoED.txt");
ofstream Yay;
Yay.open("LainezTeixidoEDintensitat.txt");	
	
h=Tmax/N;

cout<<"sigma= "<<sigma<<",   "<<"b=  "<<b<<",   "<<"r= "<<r<<endl;
Yep<<"sigma= "<<sigma<<",   "<<"b=  "<<b<<",   "<<"r= "<<r<<endl;
Yay<<"sigma= "<<sigma<<",   "<<"b=  "<<b<<",   "<<"r= "<<r<<endl;


//MÈTODE D'EÜLER 	
if(o==1){	

	for (i=2; i<N+1; i++){

	x[i]=x[i-1]+x1(x[i-1], y[i-1])*h;  
	y[i]=y[i-1]+y1(x[i-1], y[i-1], z[i-1])*h;
	z[i]=z[i-1]+z1(x[i-1], y[i-1], z[i-1])*h; }
		
		
	for (j=1; j<N+1; j=j+15){
		
	cout<<x[j]<<"   "<<y[j]<<"   "<<z[j]<<endl; 
	Yep<<x[j]<<"   "<<y[j]<<"   "<<z[j]<<endl; 
	Yay<<(j-1)<<"  "<<pow(x[j],2)<<endl; }
}

//MÈTODE RE RUNGE-KUTTA
if (o==2){
	
	
	double K1x, K1y, K1z, K2x, K2y, K2z, K3x, K3y, K3z, K4x, K4y, K4z, mx, my, mz;	
	
		for (i=2; i<N+1; i++){		
	
	K1x=x1(x[i-1], y[i-1]);
	K1y=y1(x[i-1], y[i-1], z[i-1]);
	K1z=z1(x[i-1], y[i-1], z[i-1]);
	
	K2x=x1(x[i-1]+h/2*K1x, y[i-1]+h/2*K1y);
	K2y=y1(x[i-1]+h/2*K1x, y[i-1]+h/2*K1y, z[i-1]+h/2*K1z);
	K2z=z1(x[i-1]+h/2*K1x, y[i-1]+h/2*K1y, z[i-1]+h/2*K1z);
	
	K3x=x1(x[i-1]+h/2*K2x, y[i-1]+h/2*K2y);
	K3y=y1(x[i-1]+h/2*K2x, y[i-1]+h/2*K2y, z[i-1]+h/2*K2z);
	K3z=z1(x[i-1]+h/2*K2x, y[i-1]+h/2*K2y, z[i-1]+h/2*K2z);
	
	K4x=x1(x[i-1]+h*K3x, y[i-1]+h*K3y);
	K4y=y1(x[i-1]+h*K3x, y[i-1]+h*K3y, z[i-1]+h*K3z);
	K4z=z1(x[i-1]+h*K3x, y[i-1]+h*K3y, z[i-1]+h*K3z);
	
	mx=(K1x+2*(K2x+K3x)+K4x)*h/6;
	my=(K1y+2*(K2y+K3y)+K4y)*h/6;
	mz=(K1z+2*(K2z+K3z)+K4z)*h/6;
		
	x[i]=x[i-1]+mx;  
	y[i]=y[i-1]+my;
	z[i]=z[i-1]+mz; }
		
			

	for (j=1; j<N+1; j=j+100){
	cout<<j-1<<"  "<<x[j]<<"   "<<y[j]<<"   "<<z[j]<<endl; 
	Yep<<j-1<<"  "<<x[j]<<"   "<<y[j]<<"   "<<z[j]<<endl;
	Yay<<(j-1)<<"  "<<pow(x[j],2)<<endl; } 
	

}	
	
		cin.ignore(); return 0;} 
