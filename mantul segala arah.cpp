#include <bits/stdc++.h>
using namespace std;

const double dt=0.01;
const double y_bawah=0.0;
const double x_bawah=0.0;
const double y_atas=60.0;
const double x_kanan=10.0;
const double elastisitas=0.8;
const double waktu=20.0;


int main (){
	double y=50.0;
	double x=5.0;
	double v0=1;
	double teta=30.0*M_PI/180.0;
	double vx=v0*cos(teta);
	double vy=v0*sin(teta);
	double t_0=0;
	
	ofstream output;
	output.open("posisi_bola.txt");
	output<<setprecision(6);
		while (t_0<= waktu){
		output<<x<<","<<y<<endl;
		y=y+vy*dt;
		
		t_0=t_0+dt;
		
		vx+=vx*dt;
		x=x+vx*dt;
		
		if (x <= x_bawah) {
            x = x_bawah;
            vx = -vx * elastisitas;
        } else if (x >= x_kanan) {
            x = x_kanan;
            vx = -vx * elastisitas;

	}
		if (y <= y_bawah) {
            y = y_bawah;
            vy = -vy * elastisitas;
        } else if (y >= y_atas) {
            y = y_atas;
            vy = -vy * elastisitas;
        }

	}
	output.close();
		
	return 0;
}
