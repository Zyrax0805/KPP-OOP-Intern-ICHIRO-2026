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
    
public:
    vector<vector<char>> grid;
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

   int get_cols(){return cols;}
   int get_rows(){return rows;}
   vector<vector<char>> get_grid(){return grid;}
 
    
};//end of field class

class ball{

private:
    point letak;
    int speed;
    vector<int> arah = {-1, 0, 45, 90, 135, 180, 225, 270, 315};

public:
    ball(point position = {-1,-1}, int kecepatan = 0) : letak(position), speed(kecepatan){}

    point getposition() {return letak;}
    
    bool check_goal(){
        //kekurangan cuma bisa pada satu fixed field
        if((letak.y >= 4 and letak.y <= 9) and letak.x == 18){
            return true;
        }else return false;
    }

    //move (letak, speed, arah)

    

};//end of ball class

class simulator{
private:

public:
    // metode simulasi(robot, ball, field) per tick 
    // metode simulasi ini kayak mi solve()

    //representasi grid
    void show_grid (field lapangan, striker ichiro, ball bola){
        // vector<vector<char>> grid = lapangan.get_grid();
        //kasi masuk dulu visualisasi robot
        //pake parameter orientasi robot
        // void make_visual(){}
        for(int i = 1; i <= lapangan.get_rows(); i++){
            for(int j = 1; j <= lapangan.get_cols(); j++){
                cout << lapangan.grid[i][j] << " ";//belum bisa mengeluarkan visi dari robot
                //visualisasi robot dan bola tok + lapangan
            }
        cout << nl;
        }
    }
    


};//end of simulator class

class robot{
private:
    point lokasi;
    vector<string> state;
    point orientation;
    int speed;
    //vector perubahan 4 sisi dari posisi robot
    vector<point> dorien = {{1,0},{-1,0},{0,1},{0,-1}};

public:
    robot(point position, int kecepatan = 1) : lokasi(position), speed(kecepatan){}
    
    //assign orintation dulu deteksinya pake cek 4 arah aja, dimana ada @ disitu dia menghadap
    void get_orientation(field lapangan){
        
        for(int i = 0; i < 4; i++){
            int ny = lokasi.y + dorien[i].y;
            int nx = lokasi.x + dorien[i].x;
            if(lapangan.grid[ny][nx] == '@'){
                orientation = dorien[i];
                break;
            }
        }
        orientation = {-1,-1};//kalau ndak didapat ki orientasinya ke mana
        return;
    }



    //pikir bagaimana cara ubah orientationnya
    //apakah kira rotasi saja 90 derajat
    //atau assign satu satu point yang termasuk kedalam vision sesuai dengan arah robot melihat

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

    simulator cetak_gol;
    


    


    return 0;
}