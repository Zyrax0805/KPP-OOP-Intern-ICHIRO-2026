# KPP-OOP-Intern-ICHIRO-2026

mohon maaf sebelumnya dikarenakan tugas KPP saya tidak selesai sesuai dengan apa yang diminta

pertama-tama, saya membuat Robotstate bertipe data enum yang berisi state robot (SEARCH_BALL, APPROACH_BALL, ALIGN_TO_GOAL, KICK)

kemudian saya membuat sebuah user-defined data type bernama Point untuk menyimpan titik kordinat pada sumbu-y dan sumbu-x. sebenarnya tipe datanya itu mirip mirip ama pair sih. cuman karena malas bikin makepair() setiap nge-assign titik baru dan biar ngecomparenya enak, jadinya pake Point itu.

kemudian untuk objeknya saya puunya:
    1. field:
        a. merupakan lapangan dalam representasi grid dua dimensi
        b. atribut privatenya cuma rows dan cols
        c. untuk representasi gridnya saya menggunakan nested vector bertipe data char yang di-set menjadi public agar mudah diubah ubah
        d. ketika pertama kali di-construct, ia akan membuat sebuah grid berukuran rows x cols dengan setiap elemennya bernilai "."
        e. method input_grid() => untuk membuat reprentasi lapangan sesuai dengan input yang diberikan
        f. method find_target() => untuk mengembalikan titik kordinat tempat terget berada (targetnya terserah mau masukin argumen apa ke methodnya) 

    2. ball:
        a. merupakan objek bola yang ditendang oleh robot
        b. atribut privatenya meliputi letak, kelajuan, dan vector yang menyimpan arah pergerakan bola
        c. check_goal() berguna untuk mengecek apakah bola tersebut sudah masuk kedalam gawang atau belum (ditandai dengan mengecek apakah posisi bola itu berada pada gawang lawan atau tidak)
        d. method move() sebenarnya buat ngeupdate pergerakan bola yang sudah ditendang tapi belum jadi (karena saya kepikiran buat masukin perubahan posisi dan kecepatan bola itu di simulator saja)

    3. simulator:
        a. merupakan objek yang mengelola loop tick dengan mensimulasikan apa yang terjadi di lapangan dari awal hingga akhir
        b. saat ini, simulator hanya memiliki 1 method yaitu show_grid() yang berfungsi untuk memberikan visualisasi grid pada tiap tick
    
    4. sensor:
        a. merupakan objek yang dimiliki oleh class robot yang berfungsi sebagai sumber informasi robot yang memberikan data dari hasil scanning agar robot dapat mengetahui posisi bola dan tidak bergerak keluar field.
        b. memiliki method scan() yang berfungsi untuk memeriksa apakah terdapat bola pada jarak pandang robot
        c. memberitahu robot apakah bola tersebut berada dalam jawak pandanganya atau tidak, serta memberi tahu robot bahwa ia sudah pernah mengetahui lokasi bola (sehingga apabila kehilangan jejaknya, ia dapat melakukan perhitungan ulang untuk menentukan di manakah bola itu akan berakhir setelah ditendang)
    
    5. robot:
        a. merupakan objek yang merepresentasikan robot yang bermain bola
        b. memiliki atribut:
            - sensor
            - state
            - lokasi
            - orintation
            - vektor perubahan orientasi
            - kelajuan
            - history state
        c. memiliki class striker yang inherit kepadanya
        d. method get_orientation() berfungsi untuk menentukan arah pandangan robot berdasarkan letak karakter "@", (namun saya sadar {ketika membuat catatan ini} bahwa hal ini nggak perlu karena dalam dunia nyata pasti robotnya sendiri udah tau dia menghadap ke mana :v)
        e. method sense() bergungsi untuk meminta class scan melakukan scanning 
        f. method think() berfungsi untuk menentukan keputusan apa yang harus diambil oleh robot. 
            - jika sensor belum pernah melihat bola, robot akan berada pada state SEARCH_BALL
            - jika ternyata bola itu sudah berjarak 1 petak dari robot, maka robot akan memasuki state KICK (sebenarnya algonya salah sih tapi yoweslah)
            - jika robot tidak berjarak 1 petak dari bola, maka robot memasuki state APPROACH_BALL
        g. act() nya belum sempat saya buat karena masih ga kepikirian algo optimal untuk menentukan tindakan robot selanjutnya setelah mengetahui lokasi bola

Use of AI on this assignment:
1. mencari tahu mengapa class simulator harus ada
2. mencari tahu apa saja atribut dan method yang harus dimiliki oleh setiap class
3. membuat dan mempelajari tipe data enum
4. menggunakan AI untuk men-generate the entire code, tapi codenya ngawur, jadi saya pelajari aja struktur penulisannya.

