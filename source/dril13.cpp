#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <iostream>

int main()
{
	try{

	
		Point t1{300,50};
		Simple_window win{t1,1000,800, "Simple_window"};

		Lines grid;
		int x_size = 800;
		int y_size = 800;

		for(int i =100;i<=x_size;i+=100){
			grid.add(Point(i,0), Point(i,y_size));
			grid.add(Point(0,i), Point(x_size,i));

		}
		win.attach(grid);
		win.wait_for_button();

		Vector_ref<Rectangle> v;

		for(int i=0;i<9;i++){

			v.push_back(new Rectangle(Point(i*100,i*100), 101 ,101));
			v[v.size()-1].set_fill_color(Color::red);
			win.attach(v[v.size()-1]);
		}
		win.wait_for_button();

		Image badgel(Point(200,0),"badge.jpg");
		badgel.set_mask(Point(200,0),200,200);
		win.attach(badgel);

		Image badgel2(Point(400,200),"badge.jpg");
		badgel2.set_mask(Point(200,0),200,200);
		win.attach(badgel2);

		Image badgel3(Point(600,500),"badge.jpg");
		badgel3.set_mask(Point(200,0),200,200);
		win.attach(badgel3);
		win.wait_for_button();

		Image badgel4(Point(0,0), "badge.jpg");
		badgel4.set_mask(Point(110,70),100,100);
		win.attach(badgel4);
		win.wait_for_button();

		int x = 0;
		int y = 0;
		int dx = 0;
		int dy = 0;
		while (true){
			x = randint(8);
			y= randint(8);
		
		dx = 100*x - badgel4.point(0).x;
		dy = 100*y - badgel4.point(0).y;
		badgel4.move(dx,dy);
		win.wait_for_button();
	}

		

	}catch(exception& e){
		cerr << "exeption" << e.what() <<endl;
		return 1;
	}catch(...){
		cerr<< "exeption\n";
		return 2;
	}

}




