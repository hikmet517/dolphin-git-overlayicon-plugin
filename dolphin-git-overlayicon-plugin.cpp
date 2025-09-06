#include "dolphin-git-overlayicon-plugin.hpp"

#include <KOverlayIconPlugin>
#include <QDir>
#include <QUrl>

DolphinGITOverlayIconPlugin::DolphinGITOverlayIconPlugin(QObject *parent)
    : KOverlayIconPlugin(parent)
{
}

QStringList DolphinGITOverlayIconPlugin::getOverlays(const QUrl &item)
{
    if (QDir(item.toLocalFile() + QDir::separator() + QLatin1String{".git"}).exists()) {
        return QStringList{QLatin1String{"git-overlay"}};
    }
    return QStringList{};
}

#include "dolphin-git-overlayicon-plugin.moc"

#include "moc_dolphin-git-overlayicon-plugin.cpp"
