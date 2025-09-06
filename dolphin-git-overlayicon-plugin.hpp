#pragma once

#include <KOverlayIconPlugin>

class DolphinGITOverlayIconPlugin : public KOverlayIconPlugin
{
    Q_PLUGIN_METADATA(IID "com.github.dolphin-git-overlayicon-plugin" FILE "dolphin-git-overlayicon-plugin.json")
    Q_OBJECT

public:
    DolphinGITOverlayIconPlugin(QObject *parent = nullptr);
    ~DolphinGITOverlayIconPlugin() override = default;

    QStringList getOverlays(const QUrl &item) override;
};
