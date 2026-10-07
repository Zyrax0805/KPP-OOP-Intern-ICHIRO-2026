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

    boll operator!=(const point& other) const{
        return !(*this == other);
    }

};

class field (){

private:
    int rows, int cols;
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

class ball (){

private:
    point letak;

public:
    ball(point position) : letak(position){}

    

};//end of ball class

class simulator (){
private:

public:
    //tendang
    //fungsi buat hitung jarak
    //gerak bole
    


};//end of simulator class

class robot(){
private:
    point lokasi;
    vector<string> state;
    //orientasi
    //kecepatan

public:
    robot(point position) : lokasi(position){}  

    //sense
    //think
    //act

    //buat striker yang inherit ke robot


};//end of robot class




int main(){
    int rows, cols;
    if (!(cin >> rows >> cols))return 0;

    field lapangan(rows,cols);
    lapangan.input_grid();

    point start = find_target('R');
    point bola = find_target('0');

    robot striker(start);
    simulator cetak_gol;
    


    


    return 0;
}