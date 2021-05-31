#include "socoban.hpp"
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include "appsettings.hpp"
#include <QPainter>

#pragma comment (lib, "opengl32.lib")


int menuStateToInt(const socoban::eMenu &aMenu)
{
  switch(aMenu)
  {
    case socoban::eMenu::START:       return (int)socoban::eMenu::START;
    case socoban::eMenu::END:         return (int)socoban::eMenu::END;
    case socoban::eMenu::SELECT_LEVEL:return (int)socoban::eMenu::SELECT_LEVEL;
    case socoban::eMenu::PLAY:        return (int)socoban::eMenu::PLAY;
    case socoban::eMenu::PLAYER_STAT: return (int)socoban::eMenu::PLAYER_STAT;
    case socoban::eMenu::EXIT:        return (int)socoban::eMenu::EXIT;
  }
  return -1;
}

socoban::socoban()
{
    //appSettings::instance().setQtOpenGLWidget(*this);
    mvMenu.push_back({eMenu::PLAY, "Play"});
    mvMenu.push_back({eMenu::SELECT_LEVEL, "Select level"});
    mvMenu.push_back({eMenu::PLAYER_STAT, "Statistic"});
    mvMenu.push_back({eMenu::EXIT, "Exit"});
}

void socoban::initializeGL()
{
    static auto w = appSettings::instance().ScreenWidth();
    static auto h = appSettings::instance().ScreenHeight();

    glOrtho(0, w, h, 0, 0, 1);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);

    appSettings::instance().load();
}

void socoban::resizeGL(int aW, int aH)
{
    static auto w = appSettings::instance().ScreenWidth();
    static auto h = appSettings::instance().ScreenHeight();

    glLoadIdentity();
    glViewport(0, 0, (GLint)aW, (GLint)aH);
    glOrtho(0, w, h, 0, 0, 1);
}

void socoban::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 1, 1, 0);

    _proccesing();
    _draw();
}

void socoban::keyReleaseEvent(QKeyEvent *appKeyEvent)
{
    if(appKeyEvent->key() == Qt::Key_Escape)
    {
        close();
    }
}

void socoban::_proccesing()
{
    switch(mState)
    {
    case eState::MENU:
    {
        break;
    }
    case eState::SELECT_LEVEL:
    {
        break;
    }
    case eState::PLAYER_STAT:
    {
        break;
    }
    case eState::PLAY:
    {
        break;
    }
    case eState::EXIT:
    {
        close();
        break;
    }
    }
}
void socoban::_draw()
{
    switch(mState)
    {
    case eState::MENU:
    {
        break;
    }
    case eState::SELECT_LEVEL:
    {
        break;
    }
    case eState::PLAYER_STAT:
    {
        break;
    }
    case eState::PLAY:
    {
        break;
    }
    case eState::EXIT:
    {
        break;
    }
    }
}

void socoban::_draw_menu()
{
    static auto app_w = appSettings::instance().ScreenWidth() / 2.f;
    static auto app_h = appSettings::instance().ScreenHeight() / 3.f;

    static auto font = QFont("Sans", 25);
    static auto font_selected = QFont("Sans", 30);
    font_selected.setBold(true);

    auto x = app_w - 100;
    auto y = app_h;
    auto dy = 55.f;
    int end = mvMenu.size();

    for(int i = 0; i < end; i++)
    {
        //if(i == menuStateToInt(mCurrentMenu))
        //{

            //qglColor(Qt::red);
            //renderText(x,y,mvMenu[i].second.c_str(), font_selected);
          //  QString text;
           // text = mvMenu[i].second.c_str();
           // QPainter painter(this);

           // painter.setPen(Qt::red);

           // painter.drawText(x, y, text);
            glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
            QPainter painter;
            painter.setPen(Qt::red);
            painter.setFont(QFont("Arial", 50));
            painter.drawText(x, y, mvMenu[i].second);


        //}
        //else
       // {
        //    QPainter painter;
        //    painter.setPen(Qt::white);
        //    painter.setPen(Qt::red);
       //     painter.drawText(x, y, mvMenu[i].second);
      //  }
        y +=dy;
    }

}

void socoban::_draw_menu_select_level()
{
    auto &app = appSettings::instance();
    static auto app_w = app.ScreenWidth() / 2.f;
    static auto app_h = app.ScreenHeight() / 3.f;

    auto &levels = app.availablesLevels();
    int l_count = (int)levels.size();

    if(levels.empty()) return;

    static auto font = QFont("Comic Sans MS", 15);
    static auto font_selected = QFont("Comic Sans MS", 20);
    font_selected.setBold(true);

    int tmp = (mSelectLevelIndex - 6);
    int start = tmp < 0 ? 0 : tmp;

    tmp = (start + 6);
    int end = (tmp < l_count) ? tmp : l_count - 1;

    auto x = app_w - 100;
    auto y = app_h;
    auto dy = 25.f;

    for(int i = start; i < end; ++i)
    {
        const auto &[lvl, islock] = levels[i];

        QString item_str =  "level " + QString::number(lvl);

        QFont &rf = (i == mSelectLevelIndex) ? font_selected : font;

        Qt::GlobalColor color = Qt::gray;

        if(i == mSelectLevelIndex)
        {
            if(islock  == true) color = Qt::red;
        }
        else
        {
            if(islock == true) color = Qt::white;
        }
        QPainter paint;
        QString text = item_str;
        paint.setPen(color);
        paint.drawText(x, y, text);

        y += dy;
    }

}

void socoban::_draw_player_stat()
{

}

void socoban::_draw_play()
{

}
void socoban::_key_released_menu_select_level(int aKey)
{
    const auto &levels = appSettings::instance().availablesLevels();
    int levels_count = (int)levels.size();

    switch(aKey)
    {
        case Qt::Key_Up:
        {
            --mSelectLevelIndex;
            if(mSelectLevelIndex < 0) mSelectLevelIndex = 0;
            break;
        }
    case Qt::Key_Down:
    {
        ++mSelectLevelIndex;
        if(mSelectLevelIndex >= levels_count) mSelectLevelIndex = levels_count - 1;
        break;
    }
    case Qt::Key_Enter:
    {

    }
    }

}
