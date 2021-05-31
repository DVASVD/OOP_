#ifndef SOCOBAN_HPP
#define SOCOBAN_HPP
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QtOpenGLWidgets>
#include <QGraphicsScene>
#pragma comment (lib, "opengl32.lib")


class socoban : public QOpenGLWidget
{
    void initializeGL() override;
    void resizeGL(int, int) override;
    void paintGL() override;
    void keyReleaseEvent(QKeyEvent*) override;



public:

    enum class eState
    {
        MENU
        ,SELECT_LEVEL
        ,PLAYER_STAT
        ,PLAY
        ,EXIT
    };

    enum class eMenu
    {
        START = -1
        ,PLAY
        ,SELECT_LEVEL
        ,PLAYER_STAT
        ,EXIT
        ,END
    };

    socoban();

private:
    void _proccesing();
    void _draw();

    void _draw_menu();
    void _draw_menu_select_level();
    void _draw_player_stat();
    void _draw_play();
    void _key_released_menu_select_level(int);

private:
    int mSelectLevelIndex{0};

    eState mState{eState::MENU};
    eMenu mCurrentMenu;

    std::vector<std::pair<eMenu, QString>> mvMenu;
};


#endif // SOCOBAN_HPP
