#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define pb push_back()
#define all(x) x.begin(),x.end()
#define fi first
#define se second

struct point {
    int x,y;

    bool operator==(const point& other) const{
        return (x == other.x) and (y == other.y);
    }

    bool operator!=(const point& other) const{
        return !(*this == other);
    }

};

class field{

private:
    int rows, cols;
    vector<vector<char>> grid;

public:
    // pake one indexing
    field(int r = 0, int c = 0) : rows(r), cols(c){
        grid.assign(rows + 1, vector<char>(cols + 1, '.'));
    }

    void input_grid(){
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                cin >> grid[i][j];
            }
        }
    }

    point find_target(char target) const{
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                if(grid[i][j] == target)return {i,j};
            }
        }
        return {-1,-1};
    }

    
};//end of field class

class ball{

private:
    point letak;
    int speed;
    vector<int> arah = {-1, 0, 45, 90, 135, 180, 225, 270, 315};

public:
    ball(point position = {-1,-1}, int kecepatan = 0) : letak(position), speed(kecepatan){}

    

    //getposition
    //move (letak, speed, arah)
    //check goal

    

};//end of ball class

class simulator{
private:

public:
    // metode simulasi(robot, ball, field) per tick 
    // metode simulasi ini kayak mi solve()

    //representasi grid
    void show_grid (field lapangan, striker ichiro, ball bola){

    }
    


};//end of simulator class

class robot{
private:
    point lokasi;
    vector<string> state;
    //orientasi
    int speed;

public:
    robot(point position, int kecepatan = 1) : lokasi(position), speed(kecepatan){}  

    //sense
    //think
    //act

    


};//end of robot class

//buat striker yang inherit ke robot
class striker : public robot{

};

class sensor{

};




int main(){
    int rows, cols;
    if (!(cin >> rows >> cols))return 0;

    field lapangan(rows,cols);
    lapangan.input_grid();

    point start = lapangan.find_target('R');
    point ball_position = lapangan.find_target('0');

    ball bola(ball_position, 0);

    robot striker(start);
    simulator cetak_gol;
    


    


    return 0;
}