#include <iostream>
#include <math.h>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include <ctime>
/////////////////////////////////////////GENÍS LÁINEZ MORENO i ORIOL TEIXIDÓ GARCIA ////////////////////////////
///////////////////////////////////////////////1420606///////////////1426827///////////////////////////////////
//////////////////RESOLUCIÓ DE L'EQUACIÓ DE LAPLACE SOTA UNES CONDICIONS DE CONTORN DETERMINADES//////////////
///////////////////////////////////////////////MÈTODES NUMÈRICS II///////////////////////////////////////////

using namespace std;

int main()
{	
	
cout<<"Valor de L"<<endl;
int L,L2; cin>>L;

    float t1 = clock();//iniciem rellotge
    
L2=L*L;

////////////////////////////////////DEFINIM LA MATRIU A ///////////////////////////////////

int A[L2+1][L2]= {{0}}; //pq al principi sigui una matriu de 0 i només haguem de canviar els altres valors

int ai=1, aj=1, r, a=3, n;
int T=((L-a)*(L+1))/2+1;

for (ai=1; ai<=L2; ai++){             
	r=ai%L;							 
	if(r==1){A[ai][ai]=1;}  //part per escriure canòniques a les eq de contorn de les vores
	else {A[ai][ai-1]=1;  A[ai][ai]=-4; A[ai][ai+1]=1; A[ai][ai+L]=1; A[ai][ai-L]=1;}}//part per escriure les condicions de laplace discretitzades


for(n=0; n<a; n++){			//part per esciure condicions de contorn (files canòniques) del quadrat interior a
for(ai=T+n*L;ai<=T+a-1+n*L; ai++){
for(aj=1; aj<=L2; aj++){
	A[ai][aj]=0; A[ai][ai]=1;  }}}

	
	
for (ai=2; ai<=L; ai++){      //part per arreglar els 1 que surten de més ales components "negatives" d'A. 
   A[ai][ai-L]=0; A[ai+L2-L+1-2][ai+L2-L+1-2+L]=0; }	
   

	
int ei=1, ej=1;	
//for (ei=1; ei<L2+1; ei++){                //part per activar si es vol imprimir la matriu A
//for (ej=1; ej<L2+1; ej++){ cout<<A[ei][ej]<<" ";
//}cout<<endl;}



///////////////////////////////MÈTODE DE FACTORITZACIÓ DE LU///////////////////////////////////

int i,k,j,p;
    double l[L2][L2]={{0}},u[L2][L2]={{0}},sum,z[L2]={0},x[L2]={0};
    
 
    for(k=1;k<=L2;k++)
    {
        u[k][k]=1;
        
        //construcció de la matriu L
        for(i=k;i<=L2;i++)
        {
            sum=0;
            for(p=1;p<=k-1;p++)
                sum=l[i][p]*u[p][k]+sum;
            l[i][k]=A[i][k]-sum;
        }
		//construcció de la matriu U
        for(j=k+1;j<=L2;j++)
        {
            sum=0;
            for(p=1;p<=k-1;p++)
                sum=l[k][p]*u[p][j]+sum;
            u[k][j]=(A[k][j]-sum)/l[k][k];
        }
    }
  
 
 int b[L2]={0}, pA=10;
 
//definim el vector b
for(n=0; n<a; n++){		
for(ai=T+n*L;ai<=T+a-1+n*L; ai++){
	b[ai]=10;										
	}}
 

  
    //Resolem el sistema Lz=b;

    for(i=1;i<=L2;i++)
    {                   
        sum=0;
        for(p=1;p<i;p++)
        sum+=l[i][p]*z[p];
        z[i]=(b[i]-sum)/l[i][i];
    }
    
	//Resolem el sistema Ux=z;
    for(i=L2;i>0;i--)
    {
        sum=0;
        for(p=L2;p>i;p--)
            sum+=u[i][p]*x[p];
        x[i]=(z[i]-sum)/u[i][i];
    }


///////////////////////////////PART D'IMPRESIÓ DELS RESULTATS OBTINGUTS///////////////////////////////////
ei=0; j=1;

int yy=1, xx=1;


ofstream Ori;
Ori.open("LainezTeixidoEDP.txt");

cout<<"x    "<<"y    "<<"f(x,y)"<<endl;
for (xx=1 ;xx<=L; xx++){
for (yy=1; yy<=L; yy++){ cout<<xx<<"    "<<yy<<"    "<<x[L*(xx-1)+yy]<<endl;

}}
Ori<<"x    "<<"y    "<<"f(x,y)"<<endl;
for (xx=1 ;xx<=L; xx++){
for (yy=1; yy<=L; yy++){ Ori<<xx<<"    "<<yy<<"    "<<x[L*(xx-1)+yy]<<endl;

}}

float t2 = clock(); cout<<"El temps te calcul emprat es de  "<<(t2-t1)/1000<<" s"; //parem el rellotge

		cin.ignore(); return 0;} 
