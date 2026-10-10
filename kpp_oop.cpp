#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define pb push_back()
#define all(x) x.begin(),x.end()
#define fi first
#define se second

enum RobotState {
    SEARCH_BALL,
    APPROACH_BALL,
    ALIGN_TO_GOAL,
    KICK
};

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
//    vector<vector<char>> get_grid(){return grid;}

 
    
};//end of field class

class ball{

private:
    point letak;
    int speed;
    vector<int> arah = {-1, 0, 90, 180, 270};

public:
    ball(point position = {-1,-1}, int kecepatan = 0) : letak(position), speed(kecepatan){}

    point getposition() {return letak;}
    
    bool check_goal(){
        //kekurangan cuma bisa pada satu fixed field
        if((letak.y >= 4 and letak.y <= 9) and letak.x == 18){
            return true;
        }else return false;
    }

    void move(int arahbola){

    }

    

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

class Sensor{
    // orientasi berdasarkan orientasi robot dan posisi robot
private:
    point orientation;
    point robotpos;
    bool balldetected;
    bool everseenball;

public:
    // Sensor(point posisi_robot, point orien): orientation(orien), robotpos(posisi_robot){}
    Sensor(){}
    void scan(field lapangan, point posisi_robot, point orien){
        orientation = orien;
        robotpos = posisi_robot;
        //mengassign setiap titik pada field yang merupakan area penglihatan robot dengan karakter '@'
        int maxX = lapangan.get_cols();
        int maxY = lapangan.get_rows();
        int rx = robotpos.x;
        int ry = robotpos.y;
        if(orientation.x == 0){//sumbu y
            int cnt = 1;
            for(ll y = ry+1*(orientation.y); y <= ry+3*(orientation.y); y++){
                if(y < 1 or y > maxY)continue;//lewati kalau semisal out of border
                for(ll x = rx-cnt; x <= rx+cnt; x++){
                    if(x < 1 or x > maxX)continue;
                    if(lapangan.grid[y][x] == '0'){
                        balldetected = true;
                        everseenball = true;
                    }
                    lapangan.grid[y][x] = '@';
                }
            }
        }else{//sumbu x
            int cnt = 1;
            for(ll x = rx+1*(orientation.x); x <= rx+3*(orientation.x); x++){
                if(x < 1 or x > maxX)continue;
                for(ll y = ry-cnt; y <= ry+cnt; y++){
                    if(y < 1 or y > maxY)continue;//lewati kalau semisal out of border
                    if(lapangan.grid[y][x] == '0'){
                        balldetected = true;
                        everseenball = true;
                    }
                    lapangan.grid[y][x] = '@';
                }
            }
        }
    }

    bool get_balldetected(){return balldetected;}
    bool get_everseenball(){return everseenball;}
};

class robot{
private:
    point lokasi;
    vector<string> history_state;
    point orientation;
    RobotState state;
    int speed;
    Sensor sensor;
    //vector perubahan 4 sisi dari posisi robot
    vector<point> dorien = {{1,0},{-1,0},{0,1},{0,-1}};//atas, bawah, kanan, kiri

public:
    robot(point position, int kecepatan = 1) : lokasi(position), speed(kecepatan){
        // Sensor sensor(lokasi, orientation);
    }
    
    //assign orintation dulu deteksinya pake cek 4 arah aja, dimana ada @ disitu dia menghadap
    void get_orientation(field lapangan){
        
        for(int i = 0; i < 4; i++){
            int ny = lokasi.y + dorien[i].y;
            int nx = lokasi.x + dorien[i].x;
            if(lapangan.grid[ny][nx] == '@'){
                orientation = dorien[i];
                return;
            }
        }
        orientation = {-1,-1};//kalau ndak didapat ki orientasinya ke mana
        return;
    }



    //pikir bagaimana cara ubah orientationnya
    //apakah kira rotasi saja 90 derajat
    //atau assign satu satu point yang termasuk kedalam vision sesuai dengan arah robot melihat

    //sense
    void sense(field lapangan){
        sensor.scan(lapangan, lokasi, orientation);

    }

    //think
    void think(field lapangan){
        if(!(sensor.get_everseenball())) state = SEARCH_BALL;
        else{
            bool jauh = true;
            //hitung distance from ball
            for(int i = 0; i < 4; i++){
            int ny = lokasi.y + dorien[i].y;
            int nx = lokasi.x + dorien[i].x;
                if(lapangan.grid[ny][nx] == '0'){
                    state = APPROACH_BALL;
                    jauh = false;
                    break;
                }
            }
            if(!(jauh))state = KICK;
        }
    }
    //act

    


};//end of robot class

//buat striker yang inherit ke robot
class striker : public robot{

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