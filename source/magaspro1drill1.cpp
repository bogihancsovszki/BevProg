/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include <stdexcept>



using namespace Graph_lib;

int main()
try
{
	Point tl{100,100};
	Simple_window win{tl,600,400,"Canvas"};
	win.wait_for_button();

	Axis xa{Axis::x, Point{20,300},280,10,"x axis"};
	win.attach(xa);
	win.set_label("Canvas #2");
	win.wait_for_button();

	Axis ya {Axis::y, Point{20,300},280,10,"y axis"};
	ya.set_color(Color::red);
	ya.label.set_color(Color::dark_blue);
	win.attach(ya);
	win.set_label("Cancas #3");
	win.wait_for_button();
	Function sine {sin,0,100,Point{20,150},1000,50,50};
	win.attach(sine);
	win.set_label("Canvas #4");
	win.wait_for_button();

	sine.set_color(Color::magenta);
	Polygon poly;
	poly.add(Point{100,200});
	poly.add(Point{200,200});
	poly.add(Point{300,300});
	poly.set_color(Color::green);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Canvas #5");
	win.wait_for_button();

	Rectangle r {Point{200,200},100,50};
	win.attach(r);
	win.set_label("Canvas #6");
	win.wait_for_button();

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);
	poly_rect.add(Point{50,75});
	r.set_fill_color(Color::white);
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,6));
	poly_rect.set_fill_color(Color::cyan);
	win.set_label("Canvas #7");
	win.wait_for_button();

	Text t{Point{150,150},"Hello,graphical world!"};
	win.attach(t);
	win.set_label("Canvas #8");
	win.wait_for_button();

	t.set_font(Font::times_bold);
	t.set_font_size(30);

	Image ii {Point{100,50},"badge.jpg"};
	win.attach(ii);
	win.set_label("Canvas #10");
	win.wait_for_button();

	ii.move(100,200);
	win.set_label("Canvas #11");
	win.wait_for_button();

	Circle c{Point{100,200},50};
	Ellipse e{Point{100,200},75,25};
	e.set_color(Color::dark_red);
	Mark m{Point{100,200},'x'};

	ostringstream oss;
	oss << "screen size:" <<x_max() << y_max() <<", window size: " << win.x_max() << "*" <<win.y_max();
	Text sizes{Point{100,20},oss.str()};

	Image cal{Point{225,225},"badge.jpg"};
	cal.set_mask(Point{40,40},200,150);

	win.attach(c);
	win.attach(m);
	win.attach(e);

	win.attach(sizes);
	win.attach(cal);
	win.set_label("Canvas #12");
	win.wait_for_button();
	

}
catch(exception& e){

	return 1;
}
catch(...){

	return 2;
}

 
