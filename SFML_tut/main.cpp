//
//  main.cpp
//  SFML_tut
//
//  Created by David Dulac on 27/04/2021.
//

#include <iostream>
#include <SFML/Graphics.hpp>

//int main() {
//    const int withd {1000};
//    const int height {500};
//    const float circleSize {50.f} ;
//    const float borderCircle {-5.f};
//    float wholeCircle {2.f * circleSize };
//    // center the circle
//    sf::Vector2f pos {(withd-wholeCircle)/2.f,(height-wholeCircle)/2.f};
//    // create circle shape
//    sf::CircleShape shape(circleSize,6);
//    shape.setFillColor(sf::Color(150, 50, 250));
//    // set a borderCircle-pixel wide orange outline
//    shape.setOutlineThickness(borderCircle);
//    shape.setOutlineColor(sf::Color(250, 150, 100));
//    // create a window
//    sf::RenderWindow window(sf::VideoMode(withd,height), "myGame");
//
//    while(window.isOpen())
//    {
//        sf::Event event;
//
//        //loop throught the event
//        while(window.pollEvent(event))
//        {
//            switch( event.type)
//            {
//                case sf::Event::Closed:
//                    window.close();
//                    break;
//            }
//        }
//
//        // go right
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//            ++pos.x;
//        // go left
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//            --pos.x;
//        // go down
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//            ++pos.y;
//        // go up
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//                    --pos.y;
//        // if greater than width go back to 0
//        if(pos.x > withd ){
//            pos.x = - wholeCircle;
//        }
//        else if( pos.x < - wholeCircle){
//            pos.x = withd;
//        }
//        if(pos.y > (height)){
//            pos.y = - wholeCircle;
//        }
//        else if( pos.y < - wholeCircle){
//            pos.y = height;
//        }
//        // set the position of the shape
//        shape.setPosition(pos.x,pos.y);
//        window.clear(sf::Color(125,125,125));
//        // draw everything here...
//        window.draw(shape);
//        window.display();
//    }
//    return 0;
//}
#include "projection.hpp"
//#include <vector>

using namespace std;

vector<sf::CircleShape> initialise_points(vector<vector<float>> &points, Projection &p, vector<sf::Vector2f> &coo_x_y) {

    vector<sf::CircleShape> points_shape;
    vector<vector<float>> modifie_points = p.modified_matrice();

    for (int i = 0; i < points.size();  i++) {

        sf::CircleShape test(10.f);
        sf::Vector2f co_x_y(modifie_points[i][0] * 100.0f + 400.0f,modifie_points[i][1] * 100.0f + 300.0f);

        test.setFillColor(sf::Color(250, 250, 250));
        test.setPosition(co_x_y.x,co_x_y.y);
        coo_x_y.push_back(co_x_y);
        points_shape.push_back(test);

    }

    return points_shape;
}

vector<sf::Vector2f> update_points(Projection &p, vector<sf::Vector2f> &coo_x_y) {
    int i{ 0 };

    p.angle_aug();
    p.rotation_update();
    p.rotationZ();
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
//        p.rotationZ();
//    }
    
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
//        p.rotationY();
//    }
//
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
//        p.rotationX();
//    }

    p.projected2D();

    vector<vector<float>> modified_rotation_z = p.modified_matrice();
    vector<sf::Vector2f> new_co;

    cout << "##########################" << endl;

    for (auto& e : coo_x_y){

        e.x = modified_rotation_z[i][0] * 100 + 400;
        e.y = modified_rotation_z[i][1] * 100 + 300;

        cout << e.x  << " " << e.y << endl;

        new_co.push_back(e);

        i += 1;
    }

    cout << "##########################" << endl;


    return new_co;
}

int main() {

    
    // points for a cube
    vector<vector<float>> points{
        {-1,-1,1},
        {1,-1,1},
        {1,1,1},
        {-1,1,1},
        {-1,-1,-1},
        {1,-1,-1},
        {-1,1,-1},
        {1,1,-1}
    };

    Projection p(points);

    vector<sf::Vector2f> coo_x_y;

    vector<sf::CircleShape> points_shape = initialise_points(points, p, coo_x_y);

    int count{ 0 };

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    window.setFramerateLimit(18);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

        }
        window.clear(sf::Color::Black);

        coo_x_y = update_points(p, coo_x_y);

        for (auto& e : points_shape) {

            e.setPosition(coo_x_y[count].x,coo_x_y[count].y);
            window.draw(e);
            count += 1;
        }


        window.display();
        count = 0;
    }

    return 0;
}
