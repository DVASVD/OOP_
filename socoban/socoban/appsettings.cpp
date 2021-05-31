#include "appsettings.hpp"
#include <QDirIterator>
#pragma comment (lib, "opengl32.lib")

static const QString levels_path = "levels/";
static const QString pics_path = "pics/";
appSettings::appSettings()
{
    load();
}

appSettings::~appSettings()
{
    save();
}
appSettings &appSettings::instance()
{
    static appSettings res;
    return res;
}

void appSettings::load()
{
    // load app settings
    //...

    //load player info
    //...

    //load levels info
    mAvailableLevels.clear();

    QDirIterator it(levelsPath());

    while(it.hasNext())
    {
        it.next();
        QFileInfo info(it.fileInfo());
        if(info.completeSuffix() == "lvl")
            mAvailableLevels.push_back({info.baseName().toInt(), true});

    }

    std::sort(mAvailableLevels.begin(), mAvailableLevels.end(),
              [](const auto &a, const auto &b) -> bool
    {
        return a.first < b.first;
    });
    //if(mAvailableLevels.size() == 0) return;
    //mAvailableLevels[0].second = true;
    //_load_textures();
}
void appSettings::save()
{

}

QString appSettings::levelsPath() const
{
    return levels_path;
}

unsigned appSettings::ScreenWidth() const
{
    static unsigned res{800};
    return  res;
}
unsigned appSettings::ScreenHeight() const
{
    static unsigned res{600};
    return  res;
}

const std::vector<std::pair<int,bool>> &appSettings::availablesLevels()
{
    return mAvailableLevels;
}

//void appSettings::setQtOpenGLWidget(QOpenGLWidget &aQOpenGLWidget)
//{
//    mpGLContext = &aQOpenGLWidget;
//}

//void appSettings::_load_textures()
//{
//    glEnable(GL_TEXTURE_2D);
 //   auto load_texture = [this](QString aPath) -> unsigned int
 //   {
 //       QImage mPngImg;
 //       mPngImg.load(aPath);
 //   }
//}

















