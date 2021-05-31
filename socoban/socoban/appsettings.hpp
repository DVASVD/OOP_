#ifndef APPSETTINGS_HPP
#define APPSETTINGS_HPP
#include <QString>
#include <vector>
#include <QtOpenGLWidgets>

class appSettings
{
public:
    appSettings(const appSettings &) = delete;
    appSettings & operator =(const appSettings&) = delete;

    static appSettings &instance();

    void load();
    void save();

    //void setQtOpenGLWidget(QOpenGLWidget &);

    QString levelsPath() const;
    unsigned ScreenWidth() const;
    unsigned ScreenHeight() const;

    const std::vector<std::pair<int,bool>> &availablesLevels();

private:
   //void _load_textures();


private:
    appSettings();
    ~appSettings();

private:
    unsigned mScreenWidth{0};
    unsigned mScreenHeight{0};

    //QOpenGLWidget *mpGLContext{nullptr};

    std::vector<std::pair<int,bool>> mAvailableLevels;
};

#endif // APPSETTINGS_HPP
