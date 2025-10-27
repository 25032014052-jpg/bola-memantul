#include <bits/stdc++.h>
using namespace std;

const double gravitasi=9.81;
const double dt=0.01;
const double y_bawah=0.0;
const double elastisitas=0.8;
const double waktu=10.0;
const double x=5.0;


int main (){
	double y=50;
	double vy=0;
	double t_0=0;
	
	ofstream output;
	output.open("posisi_bola.txt");
	output<<setprecision(6);
		while (t_0<= waktu){
		output<<x<<","<<y<<endl;
		vy-=gravitasi *dt;
		y=y+vy*dt;
		
		t_0=t_0+dt;
		
		if (y<=y_bawah){
			y=y_bawah;
			vy= -vy*elastisitas;
		}
	}
	output.close();
		
	return 0;
}
