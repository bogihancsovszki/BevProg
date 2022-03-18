#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main(){
	

	Simple_window win{Point{100,100},600,600,"Function Graphs"};

	Axis x(Axis::x, Point(100,600/2), 400, 400/20, "x== 20 pixels");
	x.set_color(Color::red);
	win.attach(x);

	Axis y(Axis::y, Point(600/2,400+100),400, 400/20, "y== 20 pixels");
	y.set_color(Color::red);
	win.attach(y);


	win.wait_for_button();




}