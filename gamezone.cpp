#include "gamezone.h"

GameZone::GameZone(QWidget *parent) : QWidget(parent)
{
    s.setWidth(1024);
    s.setHeight(512);
    setFixedSize(s);
    framebuffer.resize(win_w*win_h);
    framebuffer.fill(QColor(230, 230, 250));
    for (size_t j = 0; j < map_h; j++) { // draw the map
        for (size_t i = 0; i < map_w; i++) {
            if (map[i + j * map_w] == ' ') continue; // skip empty spaces
            rect_x = i * rect_w;
            rect_y = j * rect_h;
            for(int x = rect_y; x<rect_y+32; x++){
                for (int y = rect_x;y<rect_x+32;y++){
                    framebuffer[x+y*win_w]=color[map[i+j*map_h]-'0'];
                }
            }
        }
    }
    play = new Player;

}

void GameZone::StartGame()
{
    idTimer = startTimer(1000/60);
    gameOn = true;
    this->setFocus();
}

void GameZone::timerEvent(QTimerEvent *event)
{
    if(gameOn){
        game.clear();
        for (size_t i = 0; i < win_w/2; i++) { // draw the visibility cone AND the "3D" view
            play->angle = play->player_a - play->fov/ 2 + play->fov *i/ float(win_w / 2);
            for (float t = 0; t < 20; t += 0.01) {
                float cx = play->player_x + t * cos(play->angle);
                float cy = play->player_y + t * sin(play->angle);


                float pix_x = cx * float(rect_w);
                float pix_y = cy * float(rect_h);
                my_ray.push_back(QPoint(pix_x,pix_y));
                if (map[int(cx) + int(cy)*map_w] != ' '){

                    size_t column_height = win_h/(t*cos(play->angle-play->player_a));
                    //game.push_back(std::make_pair(std::make_pair(QPoint(win_w/2+i,win_h/2-column_height/2),QPoint(win_w/2+i,win_h/2+column_height/2)),color[map[int(cx) + int(cy)*map_w]-'0']));

                    game.push_back(std::make_pair(std::make_pair(column_height, QPoint(pix_x,pix_y)), map[int(cx) + int(cy)*map_w]-'0'));

                    break;
                }
            }
        }
        this->show();
    }
    repaint();
//    gameOn = false;
//    killTimer(idTimer);

}

void GameZone::paintEvent(QPaintEvent *event)
{

    if(gameOn){
        QPainter pan(this);
        for(int i = 0; i < framebuffer.size()-1;i++){

            pan.fillRect(i/win_w,i%win_w-1,1,1, framebuffer[i]);
        }
        pan.setPen(Qt::lightGray);
        for(auto&X:my_ray){
            pan.drawPoint(X);
        }
        QPainter pan2(this);
        if(game.size()!=0){
            for(int i =1; i<win_w/2; i++){
                //qDebug() << "X=" << float(game[i].first.second.x()) << ";   Y=" << float(game[i].first.second.y());


//                size_t column_height = game[i].first.first;
//                uint choose = game[i].second;
//                QPixmap scaledPix = pixes[choose].scaled(column_height,column_height,Qt::KeepAspectRatio,Qt::FastTransformation);
//                QPoint pon = game[i].first.second;
//                QPixmap scaledPix1 = scaledPix.copy(scaledPix.width()-pon.x()%32/32.*float(column_height)-1,0,1,column_height);
//                pan2.drawPixmap(win_h+i,win_h/2-game[i].first.first/2,scaledPix1);
//                if(abs(game[i].first.second.x()- game[i-1].first.second.x()) > (game[i].first.second.y()- game[i-1].first.second.y())){
//                    //qDebug() << "X=" << game[i].first.second.x();
//                    size_t column_height = game[i].first.first;
//                    uint choose = game[i].second;
//                    QPixmap scaledPix = pixes[choose].scaled(column_height,column_height,Qt::KeepAspectRatio,Qt::FastTransformation);
//                    QPoint pon = game[i].first.second;
//                    QPixmap scaledPix1 = scaledPix.copy(scaledPix.width()-pon.x()%32/32.*float(column_height)-1,0,1,column_height);
//                    pan2.drawPixmap(win_h+i,win_h/2-game[i].first.first/2,scaledPix1);
//                }
//                else {
                    //qDebug() << "Y=" << game[i].first.second.y();

                    size_t column_height = game[i].first.first;
                    uint choose = game[i].second;
                    QPixmap scaledPix = pixes[choose].scaled(column_height,column_height,Qt::KeepAspectRatio,Qt::FastTransformation);
                    QPoint pon = game[i].first.second;
                    QPixmap scaledPix1 = scaledPix.copy(scaledPix.width()-pon.y()%32/32.*float(column_height)-1,0,1,column_height);
                    pan2.drawPixmap(win_h+i,win_h/2-game[i].first.first/2,scaledPix1);
//                }

                //QPixmap scaledPix = pixes[game[i].second].scaled(game[i].first.first,game[i].first.first,Qt::KeepAspectRatio,Qt::FastTransformation);
                //QPixmap scaledPix1=scaledPix.copy((scaledPix.width()-game[i].first.second.x()%32/32*game[i].first.first),game[i].first.second.y(),1,game[i].first.first);
                //pan2.drawPixmap(win_h+i,win_h/2-game[i].first.first/2,scaledPix1);
                //pan2.drawPixmap(game[i].first,);
               }
        }
//        for(auto&X:game){
//            pan2.setPen(QColor(X.second));
//            pan2.drawLine(X.first.first, X.first.second);
//        }
    }
}


void GameZone::keyPressEvent(QKeyEvent *event)
{
    this->hide();
    if(event->key()==Qt::Key_W){
        play->move(0);
    }
    else if(event->key()==Qt::Key_S){
        play->move(1);
    }
    if(event->key()==Qt::Key_A){
        play->move(2);
    }
    else if(event->key()==Qt::Key_D){
        play->move(3);
    }
    game.clear();
    my_ray.clear();
    repaint();

}
