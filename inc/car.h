#ifndef CAR_H
#define CAR_H

#include <string>

class Map;

typedef enum class ways {
    left = 0,
    right = 1,
    up = 2,
    down = 3,
}way;

class Car {

    public :
        Car(Map& mapp);
        void push(Map& m);
        bool isFinish(int ending[]); // is needed for main loop
        int* getLocale();
        static Map& getMap(Map&);
        int getCurr_ways();
        void show_move();
        
        
    private :
        int m_locale[2];        // location
        bool m_open_ways[4];    // available moves
        way m_last_move;        //
        int m_CURRENT_WAYS;     // available move number

    private:
        void set_car_loc(Map&); // needed for constructor (first location)
        void check_ways(Map&);  // configures the next move where it should be
        void lock_back();       // helps car to go ahead
        void reset_checks();    // locks all ways at first 
        void countOpenWay();    // this will be important if I work with decision points
        bool go(way);           // sets car's new location after move
        void save_move(way);    // 
};
#endif