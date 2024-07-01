//Programa para calcular sistema de planilla
#include <iostream>
//Librerï¿½a principal
#include <iomanip>
//Libreria para decir cuantos deciamles se quieren mostrar
#include "wchar.h"
//Librerï¿½a para caracteres especiales

using namespace std;

int main(){ 
	
	setlocale(LC_ALL, "");
	//Funciï¿½n para caracteres especiales
	
	double salario,isss,afp,renta,tablaretencion,vacaciones,recargo,div,indemnizacion,year,incapacidad,hnocturnas,hferiados, total;
	int opcion;
	bool fin = false;
	//Declaraciï¿½n de variables
	
	do{	//Inicio del ciclo do while
	for(;;){
		cout<<"******************"<<endl;
		cout<<"Ingrese su salario"<<endl; 
		cout<<"******************"<<endl;
		cin>>salario;
		//El usuario ingresa su salario
		
		if (salario>0){
			break;
		}else {
			cout<<"***********************"<<endl;
			cout<<"Ingrese un valor vï¿½lido"<<endl;
			cout<<"***********************"<<endl;
			//El salario debe ser mayor a 0, sino, se pedirï¿½ al usuario ingresar un valor vï¿½lido de forma cï¿½clica hasta que lo haga
		}
	}
	
	cout<<"************************************"<<endl;
	cout<<"Ingrese la opciï¿½n que desea calcular"<<endl;
	cout<<"0. Salir"<<endl;
	cout<<"1. ISSS"<<endl;
	cout<<"2. AFP"<<endl;
	cout<<"3. Renta del 10%"<<endl;
	cout<<"4. Renta con retenciï¿½n"<<endl;
	cout<<"5. Vaciones anual"<<endl;
	cout<<"6. Indemnizaciï¿½n"<<endl;
	cout<<"7. Incapacidad (3 dï¿½as o mï¿½s)"<<endl;
	cout<<"8. Horas extras nocturnas"<<endl;
	cout<<"9. Horas extras en dï¿½as feriados"<<endl;
	cout<<"************************************"<<endl;
	cin>>opcion;
	//El usuario escogerï¿½ la opciï¿½n que desea calcular
	
	if(opcion==0){
		
		cout<<"****************************"<<endl;
		cout<<"Usted ha salido del programa"<<endl;
		cout<<"****************************"<<endl;
		fin = true;
		//El usuario seleccinï¿½ la opciï¿½n para salir del programa
		
	}else {
		fin = false;
	}
	
	switch(opcion){
		
		case 1 : //El usuario seleccionï¿½ calcular el ISSS
		
		if(salario<1000){
			
		isss = salario*0.03;
		total = salario - isss;
		//Se calcula el ISSS de un salario menor a 1,000
									
		cout<<fixed<<setprecision(2)<<" Su ISSS es: ";cout<<isss<<endl;
		cout<<fixed<<setprecision(2)<<" Su salario restando el ISSS es: ";cout<<total<<endl; break;
		//Se deja saber el resultado
			
		} else {
		
		isss= 30;	
		total = salario-isss;
		//Se calcula el ISSS de un salario mayor a 1,000
		
		cout<<fixed<<setprecision(2)<<" Su ISSS es: ";cout<<isss<<endl;
		cout<<fixed<<setprecision(2)<<" Su salario restando el ISSS es: ";cout<<total<<endl; break;
		//Se deja saber el resultado
		
		}
		
		case 2: //El usuario seleccionï¿½ calcular el AFP
			
		if(salario<7028.29){
			
		afp = salario * 0.0725;
		total = salario - afp;
		//Se calcula el AFP de un salario menor a 7028.29
		
		cout<<fixed<<setprecision(2)<<" Su AFP es: ";cout<<afp<<endl;
		cout<<fixed<<setprecision(2)<<" Su salario restando el AFP es: ";cout<<total<<endl; break;
		//Se deja saber el resultado
			
		} else {
			
		afp = 725;
		total = salario - afp; 
		//Se calcula el AFP de un salario mayor a 7028.29
		
		cout<<fixed<<setprecision(2)<<" Su AFP es: ";cout<<afp<<endl;
		cout<<fixed<<setprecision(2)<<" Su salario restando el AFP es: ";cout<<total; break;
		//Se deja saber el resultado
			
		}
	
		
		case 3: //El usuario selecciono la renta del 10%
		renta = salario * 0.10;
		total = salario - renta;
		//Se calcula la renta del 10%
		
		cout<<fixed<<setprecision(2)<< " Su renta es de: ";cout<<renta<<endl;
		cout<<fixed<<setprecision(2)<< " Su salario restando la renta es de: ";cout<<total<<endl; break;
		//Se deja saber el resultado
		
		
		case 4: //El usuario selecciono la tabla de retencion
		afp = salario * 0.0725;
		total = salario - afp;
		
			if(total<=0.01 || total<=472){
				
				cout<<fixed<<setprecision(2)<<"Su salario no tiene retenciï¿½n"<<endl; break;
				//Se deja saber al usuario que su salario no tiene retenciï¿½n
				
			} else {
				
				if(total >= 472.01 || total<= 895.24){
					
					tablaretencion = (total - 472) * 0.1 + 17.67;
					cout<<fixed<<setprecision(2)<<" Su ISR es de: "<<tablaretencion<<endl; break;
					//Se calcula la retenciï¿½n de un salario entre 472.01$ y 895.24$
					
				} else {
					
					if(total >= 895.25 || total <= 2038.10){
						
						tablaretencion = (total - 895.24) * 0.20 + 60; break;
						cout<<fixed<<setprecision(2)<<" Su ISR es de: "<<tablaretencion<<endl; break;
						//Se calcula la retenciï¿½n de un salario entre 895.25$ y 2,038.10$
					
					} else {
						
						if(total >=2038.11 ) {
							
							tablaretencion = (total - 2038.10) * 0.30 + 288.57; break;
							cout<<fixed<<setprecision(2)<<" Su ISR es de: "<<tablaretencion<<endl; break;
							//Se calcula la retenciï¿½n de un salario mayor a 2,038.11$
							
						} 
						
					}
					
					
				}
				
			}
			
		case 5: 
		div = salario / 30;
		vacaciones = div*15;
		recargo = vacaciones * 0.30;
		total = vacaciones + recargo;
		//Se calcula el salario en vacaciones
			
			cout<<fixed<<setprecision(2)<<"Su paga en vacaciones es de: "<<total<<endl; break;
			//Se deja saber el resultado
				
		case 6: 
		
			cout<<"ï¿½Cuï¿½ntos aï¿½os lleva trabajando?"<<endl;
			cin>>year ;
			//Se pregunta al usuario cuantos aï¿½os lleva trabajando
			
			for(;;){
				
			cout<<"ï¿½Quï¿½ porcentaje de indemnizaciï¿½n le entrego la empresa donde trabaja?"<<endl;
			cin>>recargo;
			//Se pregunta al usuario su porcentaje de indemnizaciï¿½n
			
				if(recargo<0 || recargo>100){
					
					cout<<"Ingrese un porcentaje vï¿½lido"<<endl; break;
					//Si ingresa un valor menor a 0 o mayor que 100 se le pedirï¿½ que ingrese un valor vï¿½lido de forma cï¿½clica hasta que lo haga
					
					
				}else {
					
					indemnizacion = (salario * year)*recargo/100;
					//Se calcula la indemnizacion
					
					cout<<fixed<<setprecision(2)<<"Su indemnizaciï¿½n es de: "<<indemnizacion<<endl; break;
					//Se deja saber el resultado
							
				} 
				
			
			} break;
			
		case 7: 
					
			cout<<"ï¿½Cuï¿½ntos dias tiene de incapacidad?"<<endl; 
			cin>>incapacidad;
			//Se pregunta al usuario cuantos dias de incapacidad tiene
			
			 if(incapacidad>=3){
			 	
			 		total = salario * 0.75;
			 		//Se calcula el salario con incapacidad
			 		
			 		cout<<fixed<<setprecision(2)<<" Su salario devengado durante sus dias de incapacidad es: "<<total<<endl; break;
			 		//Se deja saber el resultado
			 		
			 }else {
			 	
			 	cout<<"No tiene los suficientes dias de incapacidad para realizar el cï¿½lculo"<<endl; break;
			 	//Se deja saber al usuario que no tiene los suficientes dias de incapacidad para realizar el cï¿½lculo
			 	
			 }
			 
		case 8: 
		
		cout<<"ï¿½Cuantas horas nocturnas ha trabajado?"<<endl;
		cin>>hnocturnas;
		//Se pregunta al usuario cuantas horas nocturnas ha trabajado
		
		div = (salario / 30)/8;
		total = (((hnocturnas * div)* 2)*1.25);
		//Se realiza el cï¿½lculo del sueldo con horas nocturnas
		
		cout<<fixed<<setprecision(2)<<"Su sueldo con horas nocturnas de trabajo es: "<<total<<endl; break;
		//Se deja saber el resultado
		
		case 9:
		
		cout<<"ï¿½Cuantas horas feriadas ha trabajado?"<<endl;
		cin>>hferiados;
		//Se pregunta al usuario cuantas horas feriadas ha trabajado
		
		div = (salario / 30)/8;
		total = ((hferiados * div)* 2);
		//Se realiza el calculo del sueldo con horas feriadas
		
		cout<<fixed<<setprecision(2)<<"Su sueldo con horas feriadas de trabajo es: "<<total<<endl; break;
		//Se deja saber el resultado
					
		} 
		
	}while(!fin);//Fin del ciclo do while
	
	return 0;
}